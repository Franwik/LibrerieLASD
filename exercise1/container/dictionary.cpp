
namespace lasd {

/* ************************************************************************** */

// Dictionary Methods Implementation

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(
    const TraversableContainer<Data> &TraversableC) noexcept {

  bool all = true;

  TraversableC.Traverse([&all, this](const Data &CurrData) { all &= Insert(CurrData); });

  return all;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> &&MappableC) noexcept {
  bool all = true;

  MappableC.Map(
      [&all, this](const Data &CurrData) { all &= Insert(std::move(CurrData)); });

  return all;
}

template <typename Data>
bool DictionaryContainer<Data>::RemoveAll(
    const TraversableContainer<Data> &TraversableC) noexcept {
  bool all = true;

  TraversableC.Traverse([&all, this](const Data &CurrData) { all &= Remove(CurrData); });

  return all;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertSome(
    const TraversableContainer<Data> &TraversableC) noexcept {
  bool some = false;

  TraversableC.Traverse(
      [&some, this](const Data &CurrData) { some |= Insert(CurrData); });

  return some;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&MappableC) noexcept {
  bool some = false;

  MappableC.Map(
      [&some, this](const Data &CurrData) { some |= Insert(std::move(CurrData)); });

  return some;
}

template <typename Data>
bool DictionaryContainer<Data>::RemoveSome(
    const TraversableContainer<Data> &TraversableC) noexcept {
  bool some = false;

  TraversableC.Traverse(
      [&some, this](const Data &CurrData) { some |= Remove(CurrData); });

  return some;
}

/* ************************************************************************** */

} // namespace lasd
