
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> class Hashable {

public:
  virtual unsigned long operator()(const Data &) const noexcept = 0;
};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data> {

private:
  // ...

protected:
  using DictionaryContainer<Data>::size;

  unsigned long acoeff = 1;
  unsigned long bcoeff = 0;
  static const unsigned long power = 536870912;

  std::default_random_engine gen =
      std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<unsigned long> dista =
      std::uniform_int_distribution<unsigned long>(1, power - 1);
  std::uniform_int_distribution<unsigned long> distb =
      std::uniform_int_distribution<unsigned long>(0, power - 1);

  static const Hashable<Data> constexpr enchash{};

  unsigned long tablesize = 128;

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Default constructor
  HashTable();

  /* ************************************************************************ */

  // Copy constructor
  HashTable(const HashTable &);

  // Move constructor
  HashTable(HashTable &&) noexcept;

  /* ************************************************************************ */

  // Copy assignment
  HashTable &operator=(const HashTable &);
  // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable &operator=(HashTable &&) noexcept;
  // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

public:
  // Comparison operators
  bool operator==(const HashTable &) const noexcept = delete;
  // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable &) const noexcept = delete;
  // Comparison of abstract hashtable is possible but not required.

protected:
  // Auxiliary member functions

  virtual unsigned long HashKey(const Data &) const noexcept;

  virtual unsigned long HashKey(unsigned long) const noexcept;
};

/* ************************************************************************** */

} // namespace lasd

#include "hashtable.cpp"

#endif
