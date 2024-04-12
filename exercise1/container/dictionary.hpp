
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data> {
  // ...

private:
  // ...

protected:
  // ...

public:
  // Destructor
  ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer &operator=(const DictionaryContainer &) noexcept = delete;

  // Move assignment
  DictionaryContainer &operator=(DictionaryContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TraversableContainer &) const noexcept = delete;
  bool operator!=(const TraversableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data &) noexcept = 0; // Copy of the value
  virtual bool Insert(Data &&) noexcept = 0;      // Move of the value
  virtual bool Remove(Data &&) noexcept = 0;

  bool InsertAll(const TraversableContainer<Data> &TraversableC) noexcept;
  bool InsertAll(MappableContainer<Data> &&MappableC) noexcept;
  bool RemoveAll(const TraversableContainer<Data> &TraversableC) noexcept;

  bool InsertSome(const TraversableContainer<Data> &TraversableC) noexcept;
  bool InsertSome(MappableContainer<Data> &&MappableC) noexcept;
  bool RemoveSome(const TraversableContainer<Data> &TraversableC) noexcept;
};

/* ************************************************************************** */

} // namespace lasd

#include "dictionary.cpp"

#endif
