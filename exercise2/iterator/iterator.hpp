
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> class Iterator {

private:
  // ...

protected:
  // ...

public:
  // Destructor
  virtual ~Iterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  Iterator &operator=(Iterator &) = delete;

  // Move assignment
  Iterator &&operator=(Iterator &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(Iterator &) const noexcept = delete;
  bool operator!=(Iterator &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // TODO: format this shit removing the side comments
  virtual Data &operator*() const = 0; // (non-mutable version; concrete function must
                                       // throw std::out_of_range when terminated)

  virtual bool
  Terminated() const noexcept = 0; // (concrete function should not throw exceptions)
};

/* ************************************************************************** */

template <typename Data> class MutableIterator : virtual public Iterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Destructor
  virtual ~MutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableIterator &operator=(MutableIterator &) = delete;

  // Move assignment
  MutableIterator &&operator=(MutableIterator &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(MutableIterator &) const noexcept = delete;
  bool operator!=(MutableIterator &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // TODO: format this shit removing the side comment
  virtual Data &operator*() = 0; // (mutable version; concrete function must throw
  // std::out_of_range when terminated)
};

/* ************************************************************************** */

template <typename Data> class ForwardIterator : virtual public Iterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Destructor
  virtual ~ForwardIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  ForwardIterator &operator=(ForwardIterator &) = delete;

  // Move assignment
  ForwardIterator &&operator=(ForwardIterator &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(ForwardIterator &) const noexcept = delete;
  bool operator!=(ForwardIterator &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // TODO: format this shit removing the side comment
  ForwardIterator &
  operator++() const = 0; // (concrete function must throw std::out_of_range when
  // terminated)
};

/* ************************************************************************** */

template <typename Data> class ResettableIterator : virtual public Iterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Destructor
  virtual ~ResettableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResettableIterator &operator=(ResettableIterator &) = delete;

  // Move assignment
  ResettableIterator &&operator=(ResettableIterator &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(ResettableIterator &) const noexcept = delete;
  bool operator!=(ResettableIterator &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  void Reset() const noexcept = 0;
};

/* ************************************************************************** */

} // namespace lasd

#endif
