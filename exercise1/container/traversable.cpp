
namespace lasd {

/* ************************************************************************** */

// Traversable Method Implementations

// Specific Methods

template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> func,
                                                    Accumulator acc) const {

  Traverse([func, &acc](const Data &CurrData) { acc = func(CurrData, acc); });

  return acc;
}

// Override Methods

template <typename Data>
bool TraversableContainer<Data>::Exists(const Data &data) const noexcept {

  bool found = false;

  Traverse([data, &found](const Data &CurrData) -> void {
    found |= (CurrData == data);
  });

  return found;
}

/* ************************************************************************** */

// PreOrderTraversableContainer Method Implementations

// Specific Methods

template <typename Data>
template <typename Accumulator>
Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> func,
                                                             Accumulator acc) const {

  PreOrderTraverse([&acc, func](const Data &currData) { acc = func(currData, acc); });

  return acc;
}

/* ************************************************************************** */

// PostOrderTraversableContainer Method Implementations

// Specific Methods

template <typename Data>
template <typename Accumulator>
Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> func,
                                                               Accumulator acc) const {

  PostOrderTraverse([&acc, func](const Data &currData) { acc = func(currData, acc); });

  return acc;
}

/* ************************************************************************** */

} // namespace lasd
