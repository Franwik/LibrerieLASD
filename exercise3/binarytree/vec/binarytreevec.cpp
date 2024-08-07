
namespace lasd {

/* ************************************************************************** */

// NodeVec
/* ************************************************************************** */

// Constructors & Destructor

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data &dat, unsigned long &i,
                                      BinaryTreeVec *treeptr) {
  element = dat;
  index = i;
  tree = treeptr;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data &&dat, unsigned long &i,
                                      BinaryTreeVec *treeptr) {
  std::swap(element, dat);
  index = i;
  std::swap(tree, treeptr);
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec &other) {
  element = other.element;
  index = other.index;
  tree = other.tree;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(NodeVec &&other) noexcept {
  std::swap(element, other.element);
  std::swap(index, other.index);
  std::swap(tree, other.tree);
}

// Operators

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec &
BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec &other) {
  NodeVec temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec &
BinaryTreeVec<Data>::NodeVec::operator=(NodeVec &&other) noexcept {
  std::swap(element, other.element);
  std::swap(index, other.index);
  std::swap(tree, other.tree);
  return *this;
}

// Specific member functions

template <typename Data>
const Data &BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
  return element;
}

template <typename Data>
Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept {
  return element;
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
  return (2 * index) + 1 < tree->vec.Size() &&
         tree->vec[(2 * index) + 1] != nullptr;
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
  return (2 * index) + 2 < tree->vec.Size() &&
         tree->vec[(2 * index) + 2] != nullptr;
}

template <typename Data>
inline const BinaryTreeVec<Data>::Node &
BinaryTreeVec<Data>::NodeVec::LeftChild() const {
  if ((2 * index) + 1 >= tree->vec.Size() ||
      tree->vec[(2 * index) + 1] == nullptr) {
    throw std::out_of_range("Left child doesn't exists");
  }
  return *tree->vec[(2 * index) + 1];
}

template <typename Data>
inline const BinaryTreeVec<Data>::Node &
BinaryTreeVec<Data>::NodeVec::RightChild() const {
  if ((2 * index) + 2 >= tree->vec.Size() ||
      tree->vec[(2 * index) + 2] == nullptr) {
    throw std::out_of_range("Right child doesn't exists");
  }
  return *tree->vec[(2 * index) + 2];
}

template <typename Data>
inline BinaryTreeVec<Data>::MutableNode &
BinaryTreeVec<Data>::NodeVec::LeftChild() {
  if (tree->vec[(2 * index) + 1] == nullptr) {
    throw std::out_of_range("Left child doesn't exists");
  }
  return *tree->vec[(2 * index) + 1];
}

template <typename Data>
inline BinaryTreeVec<Data>::MutableNode &
BinaryTreeVec<Data>::NodeVec::RightChild() {
  if (tree->vec[(2 * index) + 2] == nullptr) {
    throw std::out_of_range("Right child doesn't exists");
  }
  return *tree->vec[(2 * index) + 2];
}

/* ************************************************************************** */

// BinaryTreeVec
/* ************************************************************************** */

// Constructors

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data> &con) {

  unsigned long index{0};

  vec.Resize(con.Size());

  con.Traverse([this, &index](const Data &currData) {
    NodeVec *node = new NodeVec(currData, index, this);
    vec[index++] = node;
  });

  size = con.Size();
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> &&con) {
  unsigned long index{0};

  vec.Resize(con.Size());

  con.Map([this, &index](Data &currData) {
    NodeVec *node = new NodeVec(std::move(currData), index, this);
    vec[index++] = node;
  });

  size = con.Size();
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec &other) {
  size = other.size;
  vec.Resize(other.vec.Size());
  for (unsigned long i = 0; i < vec.Size(); i++) {
    if (other.vec[i] != nullptr) {
      vec[i] = new NodeVec(other.vec[i]->element, other.vec[i]->index, this);
    } else {
      vec[i] = nullptr;
    }
  }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec &&other) noexcept {
  std::swap(size, other.size);
  std::swap(vec, other.vec);
  for (unsigned long i = 0; i < vec.Size(); i++) {
    vec[i]->tree = this;
  }
}

template <typename Data> BinaryTreeVec<Data>::~BinaryTreeVec() {

  for (unsigned long i = 0; i < size; i++) {
    if (vec[i] != nullptr) {
      delete vec[i];
      vec[i] = nullptr;
    }
  }

  size = 0;
}

// Operators

template <typename Data>
BinaryTreeVec<Data> &
BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data> &other) {
  BinaryTreeVec<Data> temp{other};
  std::swap(temp, *this);
  for (unsigned long i = 0; i < size; i++) {
    vec[i]->tree = this;
  }
  return *this;
}

template <typename Data>
BinaryTreeVec<Data> &
BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data> &&other) noexcept {
  std::swap(size, other.size);
  std::swap(vec, other.vec);
  for (unsigned long i = 0; i < other.vec.Size(); i++) {
    other.vec[i]->tree = &other;
  }
  for (unsigned long i = 0; i < vec.Size(); i++) {
    vec[i]->tree = this;
  }
  return *this;
}

template <typename Data>
inline bool
BinaryTreeVec<Data>::operator==(const BinaryTreeVec &other) const noexcept {
  return BinaryTree<Data>::operator==(other);
}

template <typename Data>
inline bool
BinaryTreeVec<Data>::operator!=(const BinaryTreeVec &other) const noexcept {
  return !(*this == other);
}

// Specific member functions

template <typename Data>
inline const BinaryTreeVec<Data>::Node &BinaryTreeVec<Data>::Root() const {
  if (vec.Empty())
    throw std::length_error("The tree is empty");
  return *vec[0];
}

template <typename Data>
inline BinaryTreeVec<Data>::MutableNode &BinaryTreeVec<Data>::Root() {
  if (vec.Empty())
    throw std::length_error("The tree is empty");
  return *vec[0];
}

template <typename Data> void BinaryTreeVec<Data>::Clear() {
  for (unsigned long i = 0; i < size; i++) {
    delete vec[i];
    vec[i] = nullptr;
  }

  size = 0;

  vec.Clear();
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const {
  for (unsigned long i = 0; i < vec.Size(); i++) {
    fun(vec[i]->Element());
  }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(const MapFun fun) {
  for (unsigned long i = 0; i < vec.Size(); i++) {
    fun(vec[i]->Element());
  }
}

/* ************************************************************************** */

} // namespace lasd
