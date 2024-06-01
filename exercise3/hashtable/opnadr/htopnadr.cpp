
namespace lasd {

// HashTableOpnAdr
/* ************************************************************************** */

// Constructors

template <typename Data> HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long newsize) {

  while (newsize > tablesize) {
    tablesize *= 2;
  }
  table.Resize(tablesize);
  flagTable.Resize(tablesize);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> &con)
    : HashTableOpnAdr<Data>::HashTableOpnAdr(con.Size()) {
  std::cout << "wow" << std::endl;
  con.Traverse([this](const Data &currData) { Insert(currData); });
  std::cout << "finito" << std::endl;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long newsize,
                                       const TraversableContainer<Data> &con)
    : HashTableOpnAdr<Data>::HashTableOpnAdr(std::max(newsize, con.Size())) {
  con.Traverse([this](const Data &currData) { Insert(currData); });
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> &&con)
    : HashTableOpnAdr<Data>::HashTableOpnAdr(con.Size()) {
  con.Map([this](Data &currData) { Insert(currData); });
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long newsize,
                                       MappableContainer<Data> &&con)
    : HashTableOpnAdr<Data>::HashTableOpnAdr(std::max(newsize, con.Size())) {
  con.Map([this](Data &currData) { Insert(currData); });
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr &other)
    : HashTable<Data>::HashTable(other) {
  table = other.table;
  flagTable = other.flagTable;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr &&other) noexcept
    : HashTable<Data>::HashTable(std::move(other)) {
  std::swap(table, other.table);
  std::swap(flagTable, other.flagTable);
}

// Operators

template <typename Data>
HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr &other) {
  HashTableOpnAdr<Data> temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
HashTableOpnAdr<Data> &
HashTableOpnAdr<Data>::operator=(HashTableOpnAdr &&other) noexcept {
  HashTable<Data>::operator=(std::move(other));
  std::swap(table, other.table);
  std::swap(flagTable, other.flagTable);
  return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr &other) const noexcept {
  if (size != other.size) {
    return false;
  }

  if (tablesize <= other.tablesize) {
    return FindInto(*this, other);
  } else {
    return FindInto(other, *this);
  }
}

template <typename Data>
inline bool
HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr &other) const noexcept {
  return !(*this == other);
}

// Specific member functions (inherited from DictionaryContainer)

template <typename Data> bool HashTableOpnAdr<Data>::Insert(const Data &dat) {
  if ((static_cast<double>(size) / tablesize) >= 0.66) {
    Resize(tablesize * 2);
  }

  unsigned long i{0};
  unsigned long current{HashKey(dat, i)};
  bool inserted = false;
  bool wasDeleted = false;

  for (i = 0; i < tablesize; i++) {
    current = HashKey(dat, i);
    if (flagTable[current] == FULL && table[current] == dat) {
      return false;
    }
    if (flagTable[current] == EMPTY || flagTable[current] == DELETED) {
      table[current] = dat;
      if (flagTable[current] == DELETED) {
        wasDeleted = true;
      }
      flagTable[current] = FULL;
      inserted = true;
      size++;
      break;
    }
  }

  if (inserted && wasDeleted) {
    i++;
    unsigned long next{HashKey(dat, i)};
    for (; i < tablesize && (flagTable[next] != EMPTY); i++) {
      next = HashKey(dat, i);
      if (flagTable[next] == FULL && table[next] == dat) {
        flagTable[next] = DELETED;
        size--;
        return false;
      }
    }
    return true;
  }

  return false;
}

template <typename Data> bool HashTableOpnAdr<Data>::Insert(Data &&dat) {
  if ((static_cast<double>(size) / tablesize) >= 0.66) {
    Resize(tablesize * 2);
  }

  unsigned long i{0};
  unsigned long current{HashKey(dat, i)};
  bool inserted = false;
  bool wasDeleted = false;

  for (i = 0; i < tablesize; i++) {
    current = HashKey(dat, i);
    if (flagTable[current] == FULL && table[current] == dat) {
      return false;
    }
    if (flagTable[current] == EMPTY || flagTable[current] == DELETED) {
      table[current] = std::move(dat);
      if (flagTable[current] == DELETED) {
        wasDeleted = true;
      }
      flagTable[current] = FULL;
      inserted = true;
      size++;
      break;
    }
  }

  if (inserted && wasDeleted) {
    i++;
    unsigned long next{HashKey(table[current], i)};
    for (; i < tablesize && (flagTable[next] != EMPTY); i++) {
      next = HashKey(table[current], i);
      if (flagTable[next] == FULL && table[next] == table[current]) {
        flagTable[next] = DELETED;
        size--;
        return false;
      }
    }
    return true;
  }

  return false;
}

template <typename Data> bool HashTableOpnAdr<Data>::Remove(const Data &dat) {
  unsigned int index = Find(dat);
  if (index == tablesize) {
    return false;
  }
  flagTable[index] = DELETED;
  size--;

  if ((static_cast<double>(size) / tablesize) <= 0.25) {
    Resize(tablesize / 2);
  }

  return true;
}

// Specific member functions (inherited from TestableContainer)

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data &dat) const noexcept {
  unsigned long index = Find(dat);
  if (index < tablesize) {
    return true;
  }
  return false;
}

// Specific member functions (inherited from ResizableContainer)

template <typename Data> void HashTableOpnAdr<Data>::Resize(unsigned long newSize) {
  if (newSize == size) {
    return;
  }

  unsigned long newtsize{128};

  while (newSize > newtsize) {
    newtsize *= 2;
  }

  HashTableOpnAdr temp{newtsize};

  for (unsigned long i = 0; i < tablesize; i++) {
    if (flagTable[i] == FULL) {
      temp.Insert(table[i]);
    }
  }
  std::swap(temp, *this);
}

// Specific member function (inherited from ClearableContainer)

template <typename Data> void HashTableOpnAdr<Data>::Clear() {
  table.Clear();
  size = 0;
  tablesize = 128;
  table.Resize(tablesize);
  flagTable.Resize(tablesize);
  for (unsigned long i = 0; i < tablesize; i++) {
    flagTable[i] = EMPTY;
  }
}

// Auxiliary member functions

template <typename Data>
bool HashTableOpnAdr<Data>::FindInto(const HashTableOpnAdr &a,
                                     const HashTableOpnAdr &b) const noexcept {
  for (unsigned long i = 0; i < a.tablesize; i++) {
    if (a.flagTable[i] == FULL) {
      if (!b.Exists(a.table[i])) {
        return false;
      }
    }
  }
  return true;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::Find(const Data &dat) const noexcept {
  unsigned long current{};
  for (unsigned long i = 0; i < tablesize; i++) {
    current = HashKey(dat, i);
    if (flagTable[current] == FULL && table[current] == dat) {
      return current;
    }
  }
  return tablesize;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data &dat,
                                             unsigned long index) const noexcept {
  return (HashKey(dat) + ((index * (index + 1)) / 2)) % tablesize;
}

/* ************************************************************************** */

} // namespace lasd
