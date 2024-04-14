
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public PreOrderMappableContainer<Data>,
                        virtual public PostOrderMappableContainer<Data> {

private:
  // ...

protected:
  using Container::size;

public:
  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer &operator=(const LinearContainer &) = delete;

  // Move assignment
  LinearContainer &operator=(LinearContainer &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer &) const noexcept;
  inline bool operator!=(const LinearContainer &con) const noexcept {
    return !(*this == con);
  };

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data &operator[](unsigned long) const = 0;
  virtual Data &operator[](unsigned long) = 0;

  virtual const Data &Front() const;
  virtual Data &Front();

  virtual const Data &Back() const;
  virtual Data &Back();

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun fun) const override { PreOrderTraverse(fun); }

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun fun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun fun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun fun) override { PreOrderMap(fun); }

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun fun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun fun) override;
};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data> {
  // ...

private:
  // ...

protected:
  using Container::size;

public:
  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer &operator=(const SortableLinearContainer &) = delete;

  // Move assignment
  SortableLinearContainer &operator=(SortableLinearContainer &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const SortableLinearContainer &con) const noexcept {
    return LinearContainer<Data>::operator==(con);
  }
  inline bool operator!=(const SortableLinearContainer &con) const noexcept {
    return LinearContainer<Data>::operator!=(con);
  }

  /* ************************************************************************ */

  // Specific member function

  inline virtual void Sort() noexcept { quickSort(0, size - 1); }

protected:
  // Auxiliary member functions

  void quickSort(unsigned long p, unsigned long r) noexcept;

  unsigned long partiziona(unsigned long p, unsigned long r) noexcept;
};

/* ************************************************************************** */

} // namespace lasd

#include "linear.cpp"

#endif
