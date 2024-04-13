
namespace lasd {

/* ************************************************************************** */

// LinearContainer Methods Implementation

// Specific Methods

template <typename Data> const Data &LinearContainer<Data>::Front() const {

  if (size == 0) {
    throw std::length_error("Empty structure.");
  }

  return (*this)[0];
}

template <typename Data> Data &LinearContainer<Data>::Front() {

  if (size == 0) {
    throw std::length_error("Empty structure.");
  }

  return (*this)[0];
}

template <typename Data> const Data &LinearContainer<Data>::Back() const {

  if (size == 0) {
    throw std::length_error("Empty structure.");
  }

  return (*this)[size - 1];
}

template <typename Data> Data &LinearContainer<Data>::Back() {

  if (size == 0) {
    throw std::length_error("Empty structure.");
  }

  return (*this)[size - 1];
}

/* ************************************************************************** */

// Specific member function (inherited from PreOrderTraversableContainer)

template <typename Data>
void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const {

  for (int i = 0; i < size; i++) {
    fun((*this)[i]);
  }
}

/* ************************************************************************ */

// Specific member function (inherited from PostOrderTraversableContainer)

template <typename Data>
void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const {

  for (int i = size - 1; i >= 0; i--) {
    fun((*this)[i]);
  }
}

// Specific member function (inherited from PreOrderMappableContainer)

template <typename Data> void LinearContainer<Data>::PreOrderMap(MapFun fun) {
  for (int i = 0; i < size; i++) {
    fun((*this)[i]);
  }
}

/* ************************************************************************ */

// Specific member function (inherited from PostOrderMappableContainer)

template <typename Data> void LinearContainer<Data>::PostOrderMap(MapFun fun) {
  for (int i = size - 1; i >= 0; i--) {
    fun((*this)[i]);
  }
}

/* ************************************************************************** */

// SortableLinearContainer Auxiliary Member Functions Implementation

template<typename Data>
void SortableLinearContainer<Data>::quickSort(unsigned long p, unsigned long r) noexcept {

  if (p >= r) {
    return;
  }

  unsigned long h = partiziona(p, r);

  quickSort(p, h);
  quickSort(h + 1, r);
}

template<typename Data>
unsigned long SortableLinearContainer<Data>::partiziona(unsigned long p, unsigned long r) noexcept {

  Data pivot = (*this)[p];

  unsigned long i = p - 1;
  unsigned long j = r + 1;

  do {

    do {
      --j;
    } while ((*this)[j] > pivot);

    do {
      ++i;
    } while ((*this)[i] < pivot);

    if (i < j) {
      std::swap((*this)[i], (*this)[j]);
    }

  } while (j > i);

  return j;
}

} // namespace lasd
