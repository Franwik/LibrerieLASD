#include <cmath>
#include <string>

namespace lasd {

// Hashable
/* ************************************************************************** */

// Operators

template <> class Hashable<int> {
public:
  unsigned long operator()(const int &dat) const noexcept { return (dat * dat); }
};

template <> class Hashable<double> {
public:
  unsigned long operator()(const double &dat) const noexcept {
    long integer = floor(dat);
    long fractional = pow(2, 24) * (dat - integer);
    return (integer * fractional);
  }
};

template <> class Hashable<std::string> {
public:
  unsigned long operator()(const std::string &dat) const noexcept {
    unsigned long hash = 5381;
    for (unsigned long i = 0; i < dat.length(); i++) {
      hash = (hash << 5) + dat[i];
    }
    return hash;
  }
};

/* ************************************************************************** */

// HashTable
/* ************************************************************************** */

// Constructors

template <typename Data> HashTable<Data>::HashTable() {
  acoeff = dista(gen) * 2 + 1;
  bcoeff = distb(gen) * 2 + 1;
}

template <typename Data> HashTable<Data>::HashTable(const HashTable &other) {
  size = other.size;
  acoeff = other.acoeff;
  bcoeff = other.bcoeff;
  tablesize = other.tablesize;
}

template <typename Data> HashTable<Data>::HashTable(HashTable &&other) noexcept {
  std::swap(size, other.size);
  std::swap(acoeff, other.acoeff);
  std::swap(bcoeff, other.bcoeff);
  std::swap(tablesize, other.tablesize);
}

// Operators

template <typename Data> HashTable<Data> &HashTable<Data>::operator=(const HashTable &other) {
  size = other.size;
  acoeff = other.acoeff;
  bcoeff = other.bcoeff;
  tablesize = other.tablesize;
  return *this;
}

template <typename Data> HashTable<Data> &HashTable<Data>::operator=(HashTable &&other) noexcept {
  std::swap(size, other.size);
  std::swap(acoeff, other.acoeff);
  std::swap(bcoeff, other.bcoeff);
  std::swap(tablesize, other.tablesize);
  return *this;
}

// Auxiliary member functions

template <typename Data>
unsigned long HashTable<Data>::HashKey(const Data &dat) const noexcept {
  return HashKey(enchash(dat));
}

template <typename Data>
unsigned long HashTable<Data>::HashKey(unsigned long key) const noexcept {
  return (acoeff * key + bcoeff) % tablesize;
}

/* ************************************************************************** */

} // namespace lasd