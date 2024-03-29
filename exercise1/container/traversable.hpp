
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
class TraversableContainer : virtual public TestableContainer <Data>{
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // TODO: Create Constructors

public:

  // Destructor
  ~TraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual TraversableContainer &operator=(const TraversableContainer &) noexcept = 0; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual TraversableContainer &operator=(TraversableContainer &&) noexcept = 0; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const TraversableContainer &) const noexcept = 0; // Comparison of abstract types might be possible.
  virtual bool operator!=(const TraversableContainer &) const noexcept = 0; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using TraverseFun = std::function<void(const Data &)>;

  virtual void Traverse(const TraverseFun) const noexcept = 0;

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  template <typename Accumulator>
  virtual Accumulator &Fold(const FoldFun func, const Accumulator acc) const noexcept {

    Traverse([&acc](Data &currData){
      acc = func(currData, acc);
    });

    return acc;
  }

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  virtual bool Exists(const Data &) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // TODO: Create Constructors

public:

  // Destructor
  ~PreOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual PreOrderTraversableContainer &operator=(const PreOrderTraversableContainer &) noexcept = 0; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual PreOrderTraversableContainer &operator=(PreOrderTraversableContainer &&) noexcept = 0; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const PreOrderTraversableContainer &) const noexcept = 0; // Comparison of abstract types might be possible.
  virtual bool operator!=(const PreOrderTraversableContainer &) const noexcept = 0; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual PreOrderTraverse(const TraverseFun &) const noexcept = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  virtual Accumulator &PreOrderFold(const FoldFun func, Accumulator acc) const noexcept {

    Traverse([&acc](Data &currData){
      acc = func(currData, acc);
    });

    return acc;
  }

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  virtual void Traverse(const TraverseFun func) const noexcept override {PreOrderTraverse(func)}; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // TODO: Create Constructors

public:

  // Destructor
  ~PostOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual PostOrderTraversableContainer &operator=(const PostOrderTraversableContainer &) noexcept = 0; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual PostOrderTraversableContainer &operator=(PostOrderTraversableContainer &&) noexcept = 0; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const PostOrderTraversableContainer &) const noexcept = 0; // Comparison of abstract types might be possible.
  virtual bool operator!=(const PostOrderTraversableContainer &) const noexcept = 0; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PostOrderTraverse(const TraverseFun &) const noexcept = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  virtual Accumulator &PostOrderFold(const FoldFun func, Accumulator acc) const noexcept {

    Traverse([&acc](Data &currData){
      acc = func(currData, acc);
    });

    return acc;
  }

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  virtual void Traverse(const TraverseFun func) const noexcept override {PostOrderTraverse(func)}; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderTraversableContainer {
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
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

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

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthTraversableContainer {
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
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

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

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
