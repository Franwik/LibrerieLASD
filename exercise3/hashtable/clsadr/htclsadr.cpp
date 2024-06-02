
namespace lasd {

// HashTableClsAdr
/* ************************************************************************** */

// Constructors

template <typename Data> HashTableClsAdr<Data>::HashTableClsAdr(unsigned long newsize) {
  while (newsize > tablesize) {
    tablesize *= 2;
  }
  table.Resize(tablesize);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> &con)
    : HashTableClsAdr<Data>::HashTableClsAdr(con.Size()) {
  con.Traverse([this](const Data &currData) { Insert(currData); });
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long newsize,
                                       const TraversableContainer<Data> &con)
    : HashTableClsAdr<Data>::HashTableClsAdr(newsize) {
  con.Traverse([this](const Data &currData) { Insert(currData); });
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> &&con)
    : HashTableClsAdr<Data>::HashTableClsAdr(con.Size()) {
  con.Map([this](Data &currData) { Insert(std::move((currData))); });
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long newsize,
                                       MappableContainer<Data> &&con)
    : HashTableClsAdr<Data>::HashTableClsAdr(newsize) {
  con.Map([this](Data &currData) { Insert(std::move(currData)); });
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr &other)
    : HashTable<Data>::HashTable(other) {
  table = other.table;
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr &&other) noexcept
    : HashTable<Data>::HashTable(std::move(other)) {
  std::swap(table, other.table);
}

// Operators

template <typename Data>
HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(const HashTableClsAdr &other) {
  HashTableClsAdr<Data> temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
HashTableClsAdr<Data> &
HashTableClsAdr<Data>::operator=(HashTableClsAdr &&other) noexcept {
  HashTable<Data>::operator=(std::move(other));
  std::swap(table, other.table);
  return *this;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr &other) const noexcept {
  if (size != other.size) {
    return false;
  }

  bool found = true;

  for (unsigned long i = 0; i < tablesize && found; i++) {
    table[i].Traverse(
        [&found, &other](const Data &currData) { found &= other.Exists(currData); });
  }

  return found;
}

template <typename Data>
inline bool
HashTableClsAdr<Data>::operator!=(const HashTableClsAdr &other) const noexcept {
  return !(*this == other);
}

// Specific member functions (inherited from DictionaryContainer)

template <typename Data> bool HashTableClsAdr<Data>::Insert(const Data &dat) {
  unsigned long index = HashKey(dat);
  if (table[index].Insert(dat)) {
    size++;
    return true;
  }
  return false;
}

template <typename Data> bool HashTableClsAdr<Data>::Insert(Data &&dat) {
  unsigned long index = HashKey(dat);
  if (table[index].Insert(std::move(dat))) {
    size++;
    return true;
  }
  return false;
}

template <typename Data> bool HashTableClsAdr<Data>::Remove(const Data &dat) {
  unsigned long index = HashKey(dat);
  if (table[index].Remove(dat)) {
    size--;
    return true;
  }
  return false;
}

// Specific member functions (inherited from TestableContainer)

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data &dat) const noexcept {
  unsigned long index = HashKey(dat);
  return table[index].Exists(dat);
}

// Specific member functions (inherited from ResizableContainer)

template <typename Data> void HashTableClsAdr<Data>::Resize(unsigned long newsize) {
  if (newsize == size) {
    return;
  }

  unsigned long newtsize{128};

  while (newsize > newtsize) {
    newtsize *= 2;
  }

  HashTableClsAdr temp{newtsize};

  for (unsigned long i = 0; i < tablesize; i++) {
    table[i].Traverse([&temp](const Data &currData) { temp.Insert(currData); });
  }
  std::swap(temp, *this);
}

// Specific member function (inherited from ClearableContainer)

template <typename Data> void HashTableClsAdr<Data>::Clear() {
  table.Clear();
  size = 0;
  tablesize = 128;
  table.Resize(tablesize);
}

/* ************************************************************************** */

} // namespace lasd