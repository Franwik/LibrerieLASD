
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> class HashTableOpnAdr : virtual public HashTable<Data> {

private:
  // ...

protected:
  using Container::size;
  using HashTable<Data>::tablesize;
  using HashTable<Data>::HashKey;

  enum Flag { EMPTY, FULL, DELETED };

  Vector<Data> table{tablesize};
  Vector<Flag> flagTable{tablesize};

public:
  // Default constructor
  HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(unsigned long);
  // A hash table of a given size
  HashTableOpnAdr(const TraversableContainer<Data> &);
  // A hash table obtained from a TraversableContainer
  HashTableOpnAdr(unsigned long, const TraversableContainer<Data> &);
  // A hash table of a given size obtained from a TraversableContainer
  HashTableOpnAdr(MappableContainer<Data> &&);
  // A hash table obtained from a MappableContainer
  HashTableOpnAdr(unsigned long, MappableContainer<Data> &&);
  // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr &);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr &operator=(const HashTableOpnAdr &);

  // Move assignment
  HashTableOpnAdr &operator=(HashTableOpnAdr &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr &) const noexcept;
  inline bool operator!=(const HashTableOpnAdr &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data &) override;
  bool Insert(Data &&) override;
  bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data &) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  void Resize(unsigned long);

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;

protected:
  // Auxiliary member functions

  bool FindInto(const HashTableOpnAdr &, const HashTableOpnAdr &) const noexcept;

  unsigned long Find(const Data &) const noexcept;
  unsigned long HashKey(const Data &, unsigned long) const noexcept;

  // type FindEmpty(argument) specifiers;
  // type Remove(argument) specifiers;
};

/* ************************************************************************** */

} // namespace lasd

#include "htopnadr.cpp"

#endif
