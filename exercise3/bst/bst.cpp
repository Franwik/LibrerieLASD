
namespace lasd {

// BST
/* ************************************************************************** */

// Constructors

template <typename Data> BST<Data>::BST(const TraversableContainer<Data> &con) {
  con.Traverse([this](const Data &currData) { Insert(currData); });
}

template <typename Data> BST<Data>::BST(MappableContainer<Data> &&con) {
  con.Map([this](Data &currData) { Insert(std::move(currData)); });
}

template <typename Data>
BST<Data>::BST(const BST &other) : BinaryTreeLnk<Data>::BinaryTreeLnk(other) {}

template <typename Data>
BST<Data>::BST(BST &&other) noexcept
    : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(other)) {}

// Operators

template <typename Data> BST<Data> &BST<Data>::operator=(const BST &other) {
  if (*this != other) {
    BinaryTreeLnk<Data>::operator=(other);
  }
  return *this;
}

template <typename Data> BST<Data> &BST<Data>::operator=(BST &&other) noexcept {
  if (*this != other) {
    BinaryTreeLnk<Data>::operator=(std::move(other));
  }
  return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST &other) const noexcept {
  if (size != other.size) {
    return false;
  }

  BTInOrderIterator<Data> i1{*this};
  BTInOrderIterator<Data> i2{other};

  while (!i1.Terminated()) {
    if (*i1 != *i2) {
      return false;
    }
    ++i1;
    ++i2;
  }
  return true;
}

template <typename Data>
inline bool BST<Data>::operator!=(const BST &other) const noexcept {
  return !(*this == other);
}

// Specific member functions

template <typename Data> const Data &BST<Data>::Min() const {
  if (root == nullptr) {
    throw std::length_error("Tree is empty");
  }
  return Min(root)->Element();
}

template <typename Data> Data BST<Data>::MinNRemove() {
  if (root == nullptr) {
    throw std::length_error("Tree is empty");
  }
  Data dat{Min()};
  RemoveMin();
  return dat;
}

template <typename Data> void BST<Data>::RemoveMin() {
  if (root == nullptr) {
    throw std::length_error("Tree is empty");
  }
  Remove(Min());
}

template <typename Data> const Data &BST<Data>::Max() const {
  if (root == nullptr) {
    throw std::length_error("Tree is empty");
  }
  return Max(root)->Element();
}

template <typename Data> Data BST<Data>::MaxNRemove() {
  if (root == nullptr) {
    throw std::length_error("Tree is empty");
  }
  Data dat{Max()};
  RemoveMax();
  return dat;
}

template <typename Data> void BST<Data>::RemoveMax() {
  if (root == nullptr) {
    throw std::length_error("Tree is empty");
  }
  Remove(Max());
}

template <typename Data>
const Data &BST<Data>::Predecessor(const Data &dat) const {
  const Node *predecessor{Predecessor(root, dat, nullptr)};
  if (predecessor == nullptr) {
    throw std::length_error("Predecessor not found");
  }
  return predecessor->Element();
}

template <typename Data> Data BST<Data>::PredecessorNRemove(const Data &dat) {
  Data ret{Predecessor(dat)};
  RemovePredecessor(dat);
  return ret;
}

template <typename Data> void BST<Data>::RemovePredecessor(const Data &dat) {
  Remove(Predecessor(dat));
}

template <typename Data>
const Data &BST<Data>::Successor(const Data &dat) const {
  const Node *successor{Successor(root, dat, nullptr)};
  if (successor == nullptr) {
    throw std::length_error("Successor not found");
  }
  return successor->Element();
}

template <typename Data> Data BST<Data>::SuccessorNRemove(const Data &dat) {
  Data ret{Successor(dat)};
  RemoveSuccessor(dat);
  return ret;
}

template <typename Data> void BST<Data>::RemoveSuccessor(const Data &dat) {
  Remove(Successor(dat));
}

// Specific member function (inherited from BinaryTree)

// template <typename Data>
// inline const typename BinaryTree<Data>::Node &BST<Data>::Root() const {
//   return BinaryTreeLnk<Data>::Root();
// }

// Specific member functions (inherited from DictionaryContainer)

template <typename Data> bool BST<Data>::Insert(const Data &dat) {
  unsigned long prevSize{size};
  root = Insert(root, dat);
  return prevSize != size;
}

template <typename Data> bool BST<Data>::Insert(Data &&dat) {
  unsigned long prevSize{size};
  root = Insert(root, std::move(dat));
  return prevSize != size;
}

template <typename Data> bool BST<Data>::Remove(const Data &dat) {
  unsigned long prevSize{size};
  root = Remove(root, dat);
  return prevSize != size;
}

// Specific member functions (inherited from TestableContainer)

template <typename Data>
bool BST<Data>::Exists(const Data &dat) const noexcept {
  return Search(root, dat);
}

// Specific member function (inherited from ClearableContainer)

template <typename Data> void BST<Data>::Clear() {
  return BinaryTreeLnk<Data>::Clear();
}

// Auxiliary functions

template <typename Data>
const typename BST<Data>::NodeLnk *
BST<Data>::Min(const typename BST<Data>::NodeLnk *curr) const {
  if (curr->HasLeftChild()) {
    return Min(curr->leftChild);
  } else {
    return curr;
  }
}

template <typename Data>
typename BST<Data>::NodeLnk *BST<Data>::Min(typename BST<Data>::NodeLnk *curr) {
  if (curr->HasLeftChild()) {
    return Min(curr->leftChild);
  } else {
    return curr;
  }
}

template <typename Data>
const typename BST<Data>::NodeLnk *
BST<Data>::Max(const typename BST<Data>::NodeLnk *curr) const {
  if (curr->HasRightChild()) {
    return Max(curr->rightChild);
  } else {
    return curr;
  }
}

template <typename Data>
typename BST<Data>::NodeLnk *BST<Data>::Max(typename BST<Data>::NodeLnk *curr) {
  if (curr->HasRightChild()) {
    return Max(curr->rightChild);
  } else {
    return curr;
  }
}

template <typename Data>
const typename BST<Data>::NodeLnk *
BST<Data>::Predecessor(const typename BST<Data>::NodeLnk *curr, const Data &dat,
                       const typename BST<Data>::NodeLnk *guess) const {
  if (curr != nullptr) {
    if (curr->Element() < dat) {
      return Predecessor(curr->rightChild, dat, curr);
    } else {
      return Predecessor(curr->leftChild, dat, guess);
    }
  }
  return guess;
}

template <typename Data>
typename BST<Data>::NodeLnk *
BST<Data>::Predecessor(typename BST<Data>::NodeLnk *curr, const Data &dat,
                       typename BST<Data>::NodeLnk *guess) {
  if (curr != nullptr) {
    if (curr->Element() < dat) {
      return Predecessor(curr->rightChild, dat, curr);
    } else {
      return Predecessor(curr->leftChild, dat, guess);
    }
  }
  return guess;
}

template <typename Data>
const typename BST<Data>::NodeLnk *
BST<Data>::Successor(const typename BST<Data>::NodeLnk *curr, const Data &dat,
                     const typename BST<Data>::NodeLnk *guess) const {
  if (curr != nullptr) {
    if (curr->Element() > dat) {
      return Successor(curr->leftChild, dat, curr);
    } else {
      return Successor(curr->rightChild, dat, guess);
    }
  }
  return guess;
}

template <typename Data>
typename BST<Data>::NodeLnk *
BST<Data>::Successor(typename BST<Data>::NodeLnk *curr, const Data &dat,
                     typename BST<Data>::NodeLnk *guess) {
  if (curr != nullptr) {
    if (curr->Element() > dat) {
      return Successor(curr->leftChild, dat, curr);
    } else {
      return Successor(curr->rightChild, dat, guess);
    }
  }
  return guess;
}

template <typename Data>
bool BST<Data>::Search(const typename BST<Data>::NodeLnk *curr,
                       const Data &dat) const {
  if (curr == nullptr) {
    return false;
  }
  if (curr->Element() > dat) {
    return Search(curr->leftChild, dat);
  }
  if (curr->Element() < dat) {
    return Search(curr->rightChild, dat);
  }
  return true;
}

template <typename Data>
bool BST<Data>::Search(typename BST<Data>::NodeLnk *curr, const Data &dat) {
  if (curr != nullptr) {
    if (curr->Element() > dat) {
      return Search(curr->leftChild, dat);
    } else if (curr->Element() > dat) {
      return Search(curr->rightChild, dat);
    } else {
      return true;
    }
  }
  return false;
}

template <typename Data>
typename BST<Data>::NodeLnk *
BST<Data>::Insert(typename BST<Data>::NodeLnk *curr, const Data &dat) {
  if (curr == nullptr) {
    curr = new NodeLnk(dat);
    size++;
  } else {
    if (curr->Element() > dat) {
      curr->leftChild = Insert(curr->leftChild, dat);
    } else if (curr->Element() < dat) {
      curr->rightChild = Insert(curr->rightChild, dat);
    }
  }
  return curr;
}

template <typename Data>
typename BST<Data>::NodeLnk *
BST<Data>::Insert(typename BST<Data>::NodeLnk *curr, Data &&dat) {
  if (curr == nullptr) {
    curr = new NodeLnk(std::move(dat));
    size++;
  } else {
    if (curr->Element() > dat) {
      curr->leftChild = Insert(curr->leftChild, std::move(dat));
    } else if (curr->Element() < dat) {
      curr->rightChild = Insert(curr->rightChild, std::move(dat));
    }
  }
  return curr;
}

template <typename Data>
typename BST<Data>::NodeLnk *
BST<Data>::Remove(typename BST<Data>::NodeLnk *curr, const Data &dat) {
  if (curr != nullptr) {
    if (curr->Element() > dat) {
      curr->leftChild = Remove(curr->leftChild, dat);
    } else if (curr->Element() < dat) {
      curr->rightChild = Remove(curr->rightChild, dat);
    } else {
      curr = DeleteData(curr);
      size--;
    }
  }
  return curr;
}

template <typename Data>
typename BST<Data>::NodeLnk *
BST<Data>::DeleteData(typename BST<Data>::NodeLnk *node) {
  if (node->leftChild == nullptr) {
    node = skipRight(node);
  } else if (node->rightChild == nullptr) {
    node = skipLeft(node);
  } else {
    node->element = GetNDeleteMin(node->rightChild, node);
  }
  return node;
}

template <typename Data>
typename BST<Data>::NodeLnk *
BST<Data>::skipRight(typename BST<Data>::NodeLnk *node) {
  NodeLnk *right{node->rightChild};
  node->rightChild = nullptr;
  delete node;
  return right;
}

template <typename Data>
typename BST<Data>::NodeLnk *
BST<Data>::skipLeft(typename BST<Data>::NodeLnk *node) {
  NodeLnk *left{node->leftChild};
  node->leftChild = nullptr;
  delete node;
  return left;
}

template <typename Data>
const Data BST<Data>::GetNDeleteMin(typename BST<Data>::NodeLnk *node,
                                    typename BST<Data>::NodeLnk *parent) {
  if (node->leftChild == nullptr) {
    Data dat = node->Element();
    NodeLnk *right{skipRight(node)};
    swapChild(parent, node, right);
    return dat;
  }
  return GetNDeleteMin(node->leftChild, node);
}

template <typename Data>
void BST<Data>::swapChild(typename BST<Data>::NodeLnk *parent,
                          typename BST<Data>::NodeLnk *node,
                          typename BST<Data>::NodeLnk *son) {
  if (parent->leftChild == node) {
    parent->leftChild = son;
  } else {
    parent->rightChild = son;
  }
}

} // namespace lasd