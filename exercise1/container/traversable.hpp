
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer : virtual public TestableContainer<Data> {
  // ...

private:
  // ...

protected:
  // ...

public:
  // Destructor
  virtual ~TraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TraversableContainer &operator=(const TraversableContainer &) noexcept = delete;

  // Move assignment
  TraversableContainer &operator=(TraversableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TraversableContainer &) const noexcept = delete;
  bool operator!=(const TraversableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using TraverseFun = std::function<void(const Data &)>;

  virtual void Traverse(const TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  template <typename Accumulator>
  inline Accumulator Fold(FoldFun<Accumulator> func, Accumulator acc) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  virtual bool Exists(const Data &) const noexcept override;
};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:
  // ...

protected:
public:
  // Destructor
  virtual ~PreOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderTraversableContainer &
  operator=(const PreOrderTraversableContainer &) noexcept = delete;

  // Move assignment
  PreOrderTraversableContainer &
  operator=(PreOrderTraversableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderTraversableContainer &) const noexcept = delete;
  bool operator!=(const PreOrderTraversableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PreOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  inline Accumulator PreOrderFold(FoldFun<Accumulator> func, Accumulator acc) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  inline void Traverse(TraverseFun func) const override { PreOrderTraverse(func); }
};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer : virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:
  // ...

protected:
  // ...

public:
  // Destructor
  virtual ~PostOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderTraversableContainer &
  operator=(const PostOrderTraversableContainer &) noexcept = delete;

  // Move assignment
  PostOrderTraversableContainer &
  operator=(PostOrderTraversableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderTraversableContainer &) const noexcept = delete;
  bool operator!=(const PostOrderTraversableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PostOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  inline Accumulator PostOrderFold(FoldFun<Accumulator> func, Accumulator acc) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  inline virtual void Traverse(const TraverseFun func) const override {
    PostOrderTraverse(func);
  }
};

/* ************************************************************************** */

template <typename Data> class InOrderTraversableContainer {
  // Must extend TraversableContainer<Data>

private:
  // ...

protected:
  // ...

public:
  // Destructor
  // ~InOrderTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not
  // possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not
  // possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might
  // be possible. type operator!=(argument) specifiers; // Comparison of
  // abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;

  // type InOrderTraverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type InOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer
  // member
};

/* ************************************************************************** */

template <typename Data> class BreadthTraversableContainer {
  // Must extend TraversableContainer<Data>

private:
  // ...

protected:
  // ...

public:
  // Destructor
  // ~BreadthTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not
  // possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not
  // possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might
  // be possible. type operator!=(argument) specifiers; // Comparison of
  // abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;

  // type BreadthTraverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type BreadthFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer
  // member
};

/* ************************************************************************** */

} // namespace lasd

#include "traversable.cpp"

#endif
