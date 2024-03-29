
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  unsigned long size = 0;

  /* ************************************************************************ */

  // Default constructor
  Container() = default;

  // Initializing constructor
  explicit Container(unsigned long size) : size(size){};

  // Copy constructor
  explicit Container(const Container &con) : size(con.Size()){};

  // Move constructor
  explicit Container(const Container &&con) : size(con.Size()){};

public:

  // Destructor
  ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual Container &operator=(const Container &) noexcept = 0; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual Container &operator=(Container &&) noexcept = 0; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const Container &) const noexcept = 0; // Comparison of abstract types is not possible.
  virtual bool operator!=(const Container &) const noexcept = 0; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  bool Empty() const noexcept {return size == 0;} // (concrete function should not throw exceptions)

  unsigned long Size() const noexcept {return size;} // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

class ClearableContainer : virtual public Container{
  // Must extend Container

private:

  // ...

protected:

  // TODO: Create Constructors

public:

  // Destructor
  ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual ClearableContainer &operator=(const ClearableContainer &) noexcept = 0; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual ClearableContainer &operator=(ClearableContainer &&) noexcept = 0; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const ClearableContainer &) const noexcept = 0; // Comparison of abstract types is not possible.
  virtual bool operator!=(const ClearableContainer &) const noexcept = 0; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Clear() noexcept = 0;

};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // TODO: Create Constructors

public:

  // Destructor
  ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual ResizableContainer &operator=(const ResizableContainer &) noexcept = 0; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual ResizableContainer &operator=(ResizableContainer &&) noexcept = 0; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const ResizableContainer &) const noexcept = 0; // Comparison of abstract types is not possible.
  virtual bool operator!=(const ResizableContainer &) const noexcept = 0; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Resize(unsigned long size) noexcept = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() noexcept override {Resize(0);} // Override ClearableContainer member

};

/* ************************************************************************** */

}

#endif