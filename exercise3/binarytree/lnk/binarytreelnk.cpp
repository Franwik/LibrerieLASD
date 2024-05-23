
namespace lasd {

/* ************************************************************************** */

// NodeLnk
/* ************************************************************************** */

// Constructors & Destructor

template <typename Data> BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data &dat) {
  element = dat;
}

template <typename Data> BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data &&dat) {
  std::swap(element, dat);
}

template <typename Data> BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk &other) {
  element = other.element;
  if (other.HasLeftChild()) {
    leftChild = new NodeLnk(*other.leftChild);
  }
  if (other.HasRightChild()) {
    rightChild = new NodeLnk(*other.rightChild);
  }
}

template <typename Data> BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk &&other) noexcept {
  std::swap(element, other.element);
  std::swap(leftChild, other.leftChild);
  std::swap(rightChild, other.rightChild);
}

template <typename Data> BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
  delete leftChild;
  delete rightChild;
}

// Operators

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk &
BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk &other) {
  NodeLnk temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk &
BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk &&other) noexcept {
  std::swap(element, other.element);
  std::swap(leftChild, other.leftChild);
  std::swap(rightChild, other.rightChild);
  return *this;
}

// Specific member functions

template <typename Data>
const Data &BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
  return element;
}

template <typename Data> Data &BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
  return element;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
  return leftChild != nullptr;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
  return rightChild != nullptr;
}

template <typename Data>
inline const typename BinaryTree<Data>::Node &
BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
  if (leftChild == nullptr) {
    throw std::out_of_range("Left child doesn't exists");
  }
  return *leftChild;
}

template <typename Data>
inline const typename BinaryTree<Data>::Node &
BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
  if (rightChild == nullptr) {
    throw std::out_of_range("Right child doesn't exists");
  }
  return *rightChild;
}

template <typename Data>
inline typename MutableBinaryTree<Data>::MutableNode &
BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
  if (leftChild == nullptr) {
    throw std::out_of_range("Left child doesn't exists");
  }
  return *leftChild;
}

template <typename Data>
inline typename MutableBinaryTree<Data>::MutableNode &
BinaryTreeLnk<Data>::NodeLnk::RightChild() {
  if (rightChild == nullptr) {
    throw std::out_of_range("Right child doesn't exists");
  }
  return *rightChild;
}

/* ************************************************************************** */

// BinaryTreeLnk
/* ************************************************************************** */

// Constructors

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data> &con) {
  QueueLst<NodeLnk *> queue{};

  con.Traverse([this, &queue](const Data &currData) {
    NodeLnk *node = new NodeLnk(currData);

    queue.Enqueue(node);

    if (root == nullptr) {
      root = queue.Head();
    } else if (queue.Head()->leftChild == nullptr) {
      queue.Head()->leftChild = node;
    } else {
      queue.HeadNDequeue()->rightChild = node;
    }
  });

  size = con.Size();
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data> &&con) {
  QueueLst<NodeLnk *> queue{};

  con.Map([this, &queue](Data &currData) {
    NodeLnk *node = new NodeLnk(std::move(currData));

    queue.Enqueue(node);

    if (root == nullptr) {
      root = queue.Head();
    } else if (queue.Head()->leftChild == nullptr) {
      queue.Head()->leftChild = node;
    } else {
      queue.HeadNDequeue()->rightChild = node;
    }
  });

  size = con.Size();
}

template <typename Data> BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk &other) {
  if (other.size != 0) {
    size = other.size;
    root = new NodeLnk(*other.root);
  }
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk &&other) noexcept {
  std::swap(size, other.size);
  std::swap(root, other.root);
}

template <typename Data> inline BinaryTreeLnk<Data>::~BinaryTreeLnk() { delete root; }

// Operators

template <typename Data>
BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> &other) {
  BinaryTreeLnk<Data> temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
BinaryTreeLnk<Data> &
BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> &&other) noexcept {
  std::swap(size, other.size);
  std::swap(root, other.root);
  return *this;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk &other) const noexcept {
  return BinaryTree<Data>::operator==(other);
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk &other) const noexcept {
  return !(*this == other);
}

// Specific member functions

template <typename Data>
inline const typename BinaryTree<Data>::Node &BinaryTreeLnk<Data>::Root() const {
  if (root == nullptr) {
    throw std::length_error("Tree is empty");
  }
  return *root;
}

template <typename Data>
inline typename MutableBinaryTree<Data>::MutableNode &BinaryTreeLnk<Data>::Root() {
  if (root == nullptr) {
    throw std::length_error("Tree is empty");
  }
  return *root;
}

template <typename Data> void BinaryTreeLnk<Data>::Clear() {
  size = 0;
  delete root;
  root = nullptr;
}

/* ************************************************************************** */

} // namespace lasd
