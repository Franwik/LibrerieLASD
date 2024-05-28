
namespace lasd {

// HashTableClsAdr
/* ************************************************************************** */

// Constructors

// TODO: implement
template <typename Data> HashTableClsAdr<Data>::HashTableClsAdr(unsigned long newsize) {
  std::cout << "costruttore" << std::endl;
}

// TODO: implement
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> &con) {
  std::cout << "costruttore" << std::endl;
}

// TODO: implement
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long newsize,
                                       const TraversableContainer<Data> &con) {
  std::cout << "costruttore" << std::endl;
}

// TODO: implement
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> &&con) {
  std::cout << "costruttore" << std::endl;
}

// TODO: implement
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long newsize,
                                       MappableContainer<Data> &&con) {
  std::cout << "costruttore" << std::endl;
}

// TODO: implement
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr &other) {
  std::cout << "costruttore" << std::endl;
}

// TODO: implement
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr &&other) noexcept {
  std::cout << "costruttore" << std::endl;
}

// Operators

// TODO: implement
template <typename Data>
HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(const HashTableClsAdr &other) {
  std::cout << "operatore" << std::endl;
}

// TODO: implement
template <typename Data>
HashTableClsAdr<Data> &
HashTableClsAdr<Data>::operator=(HashTableClsAdr &&other) noexcept {
  std::cout << "operatore" << std::endl;
}

// TODO: implement
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr &other) const noexcept {
  std::cout << "operatore" << std::endl;
}

// TODO: implement
template <typename Data>
inline bool
HashTableClsAdr<Data>::operator!=(const HashTableClsAdr &other) const noexcept {
  return !(*this == other);
}

// Specific member functions (inherited from DictionaryContainer)

// TODO: implement
template <typename Data> bool HashTableClsAdr<Data>::Insert(const Data &dat) {
  std::cout << "insert" << std::endl;
}

// TODO: implement
template <typename Data> bool HashTableClsAdr<Data>::Insert(Data &&dat) {
  std::cout << "insert" << std::endl;
}

// TODO: implement
template <typename Data> bool HashTableClsAdr<Data>::Remove(const Data &dat) {
  std::cout << "remove" << std::endl;
}

// Specific member functions (inherited from TestableContainer)

// TODO: implement
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data &dat) const noexcept {
  std::cout << "exists" << std::endl;
}

// Specific member functions (inherited from ResizableContainer)

// TODO: implement
template <typename Data> void HashTableClsAdr<Data>::Resize(unsigned long newSize) {
  std::cout << "resize" << std::endl;
}

// Specific member function (inherited from ClearableContainer)

// TODO: implement
template <typename Data> void HashTableClsAdr<Data>::Clear() {
  std::cout << "clear" << std::endl;
}

/* ************************************************************************** */

} // namespace lasd
