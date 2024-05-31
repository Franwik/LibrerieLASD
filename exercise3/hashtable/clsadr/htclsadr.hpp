
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> class HashTableClsAdr : virtual public HashTable<Data> {

private:
  // ...

protected:
  using Container::size;
  using HashTable<Data>::tablesize;
  using HashTable<Data>::HashKey;

  Vector<List<Data>> table{tablesize};

public:
  // Default constructor
  HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(unsigned long);
  // A hash table of a given size
  HashTableClsAdr(const TraversableContainer<Data> &);
  // A hash table obtained from a TraversableContainer
  HashTableClsAdr(unsigned long, const TraversableContainer<Data> &);
  // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(MappableContainer<Data> &&);
  // A hash table obtained from a MappableContainer
  HashTableClsAdr(unsigned long, MappableContainer<Data> &&);
  // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr &);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr &operator=(const HashTableClsAdr &);

  // Move assignment
  HashTableClsAdr &operator=(HashTableClsAdr &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr &) const noexcept;
  inline bool operator!=(const HashTableClsAdr &) const noexcept;

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
};

/* ************************************************************************** */

} // namespace lasd

#include "htclsadr.cpp"

#endif
