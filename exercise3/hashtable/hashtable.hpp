
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
  unsigned long operator()(const Data &) const noexcept = 0;
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
  static const unsigned long power = 1073741824;

public:
  // Destructor
  // ~HashTable() specifiers

  /* ************************************************************************
   */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should
  // not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types
  // should not be possible.

  /* ************************************************************************
   */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of
  // abstract hashtable is possible but not required. type
  // operator!=(argument) specifiers; // Comparison of
  // abstract hashtable is possible but not required.

protected:
  // Auxiliary member functions

  // type HashKey(argument) specifiers;
};

/* ************************************************************************** */

} // namespace lasd

#include "hashtable.cpp"

#endif
