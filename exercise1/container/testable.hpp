
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container{
  // Must extend Container

private:

  // ...

protected:

  // TODO: Create Constructors

public:

  // Destructor
  ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual TestableContainer &operator=(const TestableContainer &) noexcept = 0; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual TestableContainer &operator=(TestableContainer &&) noexcept = 0; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const TestableContainer &) const noexcept = 0; // Comparison of abstract types is not possible.
  virtual bool operator!=(const TestableContainer &) const noexcept = 0; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  virtual bool Exists(const Data &) const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
