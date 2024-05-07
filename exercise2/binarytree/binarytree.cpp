
namespace lasd {

// Node
/* ************************************************************************** */

// Operators

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node &other) const noexcept {

  if (Element() != other.Element()) {
    return false;
  }

  if (HasLeftChild() != other.HasLeftChild()) {
    return false;
  }

  if (HasRightChild() != other.HasRightChild()) {
    return false;
  }

  if (HasLeftChild() && LeftChild() != other.LeftChild()) {
    return false;
  }

  if (HasRightChild() && RightChild() != other.RightChild()) {
    return false;
  }

  return true;
}

template <typename Data>
inline bool BinaryTree<Data>::Node::operator!=(const Node &other) const noexcept {
  return !(*this == other);
}

// Specific member function

template <typename Data> inline bool BinaryTree<Data>::Node::IsLeaf() const noexcept {
  return !(HasLeftChild() || HasRightChild());
}

/* ************************************************************************** */

// BinaryTree
/* ************************************************************************** */

// Operators

template <typename Data>
bool BinaryTree<Data>::operator==(BinaryTree &other) const noexcept {
  return (size == other.size) && (!size || Root() == other.Root());
}

template <typename Data>
inline bool BinaryTree<Data>::operator!=(BinaryTree &other) const noexcept {
  return !(*this == other);
}

// Specific member function

template <typename Data> inline void BinaryTree<Data>::Traverse(TraverseFun func) const {
  BreadthTraverse(func);
}

template <typename Data>
inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun func) const {
  if (size) {
    PreOrderTraverse(func, Root());
  }
}

template <typename Data>
inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun func, const Node &node) const {

  func(node.Element());

  if (node.HasLeftChild()) {
    PreOrderTraverse(func, node.LeftChild());
  }

  if (node.HasRightChild()) {
    PreOrderTraverse(func, node.RightChild());
  }
}

template <typename Data>
inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun func) const {
  if (size) {
    PostOrderTraverse(func, Root());
  }
}

template <typename Data>
inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun func,
                                                const Node &node) const {

  if (node.HasLeftChild()) {
    PostOrderTraverse(func, node.LeftChild());
  }

  if (node.HasRightChild()) {
    PostOrderTraverse(func, node.RightChild());
  }

  func(node.Element());
}

template <typename Data>
inline void BinaryTree<Data>::InOrderTraverse(TraverseFun func) const {
  if (size) {
    InOrderTraverse(func, Root());
  }
}

template <typename Data>
inline void BinaryTree<Data>::InOrderTraverse(TraverseFun func, const Node &node) const {

  if (node.HasLeftChild()) {
    InOrderTraverse(func, node.LeftChild());
  }

  func(node.Element());

  if (node.HasRightChild()) {
    InOrderTraverse(func, node.RightChild());
  }
}

template <typename Data>
inline void BinaryTree<Data>::BreadthTraverse(TraverseFun func) const {

  QueueLst<const Node &> queue{};
  const Node &curr;

  queue.Enqueue(Root());

  while (queue.Size()) {

    curr = queue.HeadNDequeue;

    func(curr.Element());

    if (curr.HasLeftChild()) {
      queue.Enqueue(curr.LeftChild());
    }

    if (curr.HasRightChild()) {
      queue.Enqueue(curr.RightChild());
    }
  }
}

/* ************************************************************************** */

// MutableBinaryTree
/* ************************************************************************** */

template <typename Data> inline void MutableBinaryTree<Data>::Map(MapFun func) {
  BreadthMap(func);
}

template <typename Data> inline void MutableBinaryTree<Data>::PreOrderMap(MapFun func) {
  if (size) {
    PreOrderMap(func, Root());
  }
}

template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun func, MutableNode &node) {

  func(node.Element());

  if (node.HasLeftChild()) {
    PreOrderMap(func, node.LeftChild());
  }

  if (node.HasRightChild()) {
    PreOrderMap(func, node.RightChild());
  }
}

template <typename Data> inline void MutableBinaryTree<Data>::PostOrderMap(MapFun func) {
  if (size) {
    PostOrderMap(func, Root());
  }
}

template <typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun func, MutableNode &node) {

  if (node.HasLeftChild()) {
    PostOrderMap(func, node.LeftChild());
  }

  if (node.HasRightChild()) {
    PostOrderMap(func, node.RightChild());
  }

  func(node.Element());
}

template <typename Data> inline void MutableBinaryTree<Data>::InOrderMap(MapFun func) {
  if (size) {
    InOrderMap(func, Root());
  }
}

template <typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun func, MutableNode &node) {

  if (node.HasLeftChild()) {
    InOrderMap(func, node.LeftChild());
  }

  func(node.Element());

  if (node.HasRightChild()) {
    InOrderMap(func, node.RightChild());
  }
}

template <typename Data> inline void MutableBinaryTree<Data>::BreadthMap(MapFun func) {

  QueueLst<MutableNode &> queue{};
  MutableNode &curr;

  queue.Enqueue(Root());

  while (queue.Size()) {

    curr = queue.HeadNDequeue;

    func(curr.Element());

    if (curr.HasLeftChild()) {
      queue.Enqueue(curr.LeftChild());
    }

    if (curr.HasRightChild()) {
      queue.Enqueue(curr.RightChild());
    }
  }
}

/* ************************************************************************** */

// BTPreOrderIterator
/* ************************************************************************** */

// Contstructors

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &tree) {
  if (!tree.Empty()) {
    root = tree.Root();
    stack.Push(tree.Root());
  }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator &other) {
  stack = other.stack;
  root = other.root;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator &&other) noexcept {
  std::swap(stack, other.stack);
  std::swap(root, other.root);
}

// Operators

template <typename Data>
BTPreOrderIterator<Data> &
BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data> &other) {
  BTPreOrderIterator<Data> temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
BTPreOrderIterator<Data> &&
BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data> &&other) {
  std::swap(stack, other.stack);
  std::swap(root, other.root);
  return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(
    const BTPreOrderIterator<Data> &other) const noexcept {
  return stack == other.stack && root == other.root;
}

template <typename Data>
inline bool BTPreOrderIterator<Data>::operator!=(
    const BTPreOrderIterator<Data> &other) const noexcept {
  return !(*this == other);
}

// Specific member functions

template <typename Data> const Data &BTPreOrderIterator<Data>::operator*() const {

  if (Terminated()) {
    throw std::out_of_range("Iterator has terminated");
  }

  return stack.Top()->Element();
}

template <typename Data>
inline bool BTPreOrderIterator<Data>::Terminated() const noexcept {
  return stack.Empty();
}

template <typename Data>
BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator++() {

  if (Terminated()) {
    throw std::out_of_range("Iterator has terminated");
  }

  typename BinaryTree<Data>::Node node = *stack.TopNPop();

  if (node.HasRightChild()) {
    stack.Push(node.RightChild());
  }

  if (node.HasLeftChild()) {
    stack.Push(node.LeftChild());
  }

  return *this;
}

template <typename Data> inline void BTPreOrderIterator<Data>::Reset() noexcept {
  stack.Clear();
  stack.Push(root);
}

/* ************************************************************************** */

// BTPreOrderMutableIterator
/* ************************************************************************** */

// Contstructors

template <typename Data>
inline BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(
    const MutableBinaryTree<Data> &tree)
    : BTPreOrderIterator<Data>::BTPreOrderIterator(tree) {}

template <typename Data>
inline BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(
    const BTPreOrderMutableIterator &other)
    : BTPreOrderIterator<Data>::BTPreOrderIterator(other) {}

template <typename Data>
inline BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(
    BTPreOrderMutableIterator &&other) noexcept
    : BTPreOrderIterator<Data>::BTPreOrderIterator(other) {}

// Operators

template <typename Data>
BTPreOrderMutableIterator<Data> &
BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data> &other) {
  // TODO: implement
}

template <typename Data>
BTPreOrderMutableIterator<Data> &&
BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator<Data> &&other) {
  // TODO: implement
}

template <typename Data>
inline bool BTPreOrderMutableIterator<Data>::operator==(
    const BTPreOrderMutableIterator<Data> &other) const noexcept {
  // TODO: implement
  return true;
}

template <typename Data>
inline bool BTPreOrderMutableIterator<Data>::operator!=(
    const BTPreOrderMutableIterator<Data> &other) const noexcept {
  return !(*this == other);
}

template <typename Data> Data &BTPreOrderMutableIterator<Data>::operator*() const {
  // TODO: implement
}

/* ************************************************************************** */

// BTPostOrderIterator
/* ************************************************************************** */

/* ************************************************************************** */

// BTPostOrderMutableIterator
/* ******************************************Pre******************************** */

/* ************************************************************************** */

// BTInOrderIterator
/* ************************************************************************** */

// Contstructors

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &tree) {
  if (!tree.Empty()) {
    root = tree.Root();
    // carica il percorso fino al nodo piu a sinistra
  }
}

// quando fai ++ (fatti il disegno e ragiona non e difficile, ce la puoi fare, impegnati)

/* ************************************************************************** */

// BTInOrderMutableIterator
/* ************************************************************************** */

/* ************************************************************************** */

// BTBreadthIterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> &tree) {
  if (!tree.Empty()) {
    root = tree.Root();
    queue.Enqueue(tree.Root());
  }
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator &other) {
  queue = other.queue;
  root = other.root;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator &&other) noexcept {
  std::swap(queue, other.queue);
  std::swap(root, other.root);
}

// Operators

template <typename Data>
BTBreadthIterator<Data> &
BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data> &other) {
  BTBreadthIterator<Data> temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
BTBreadthIterator<Data> &&
BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data> &&other) {
  std::swap(queue, other.queue);
  std::swap(root, other.root);
  return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(
    const BTBreadthIterator<Data> &other) const noexcept {
  return queue == other.queue && root == other.root;
}

template <typename Data>
inline bool
BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data> &other) const noexcept {
  return !(*this == other);
}

// Specific member functions

template <typename Data> const Data &BTBreadthIterator<Data>::operator*() const {

  if (Terminated()) {
    throw std::out_of_range("Iterator has terminated");
  }

  return queue.Head()->Element();
}

template <typename Data>
inline bool BTBreadthIterator<Data>::Terminated() const noexcept {
  return queue.Empty();
}

template <typename Data>
BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator++() {

  if (Terminated()) {
    throw std::out_of_range("Iterator has terminated");
  }

  typename BinaryTree<Data>::Node node = *queue.HeadNDequeue();

  if (node.HasLeftChild()) {
    queue.Enqueue(node.LeftChild());
  }

  if (node.HasRightChild()) {
    queue.Enqueue(node.RightChild());
  }

  return *this;
}

template <typename Data> inline void BTBreadthIterator<Data>::Reset() noexcept {
  queue.Clear();
  queue.Enqueue(root);
}

/* ************************************************************************** */

// BTBreadthMutableIterator
/* ************************************************************************** */

/* ************************************************************************** */

} // namespace lasd