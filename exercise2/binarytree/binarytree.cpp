
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
  if (*this != other) {
    BTPreOrderIterator<Data>::operator=(other);
  }
  return *this;
}

template <typename Data>
BTPreOrderMutableIterator<Data> &&
BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator<Data> &&other) {
  if (*this != other) {
    BTPreOrderIterator<Data>::operator=(std::move(other));
  }
  return *this;
}

template <typename Data>
inline bool BTPreOrderMutableIterator<Data>::operator==(
    const BTPreOrderMutableIterator<Data> &other) const noexcept {
  return BTPreOrderIterator<Data>::operator==(other);
}

template <typename Data>
inline bool BTPreOrderMutableIterator<Data>::operator!=(
    const BTPreOrderMutableIterator<Data> &other) const noexcept {
  return !(*this == other);
}

template <typename Data> Data &BTPreOrderMutableIterator<Data>::operator*() const {
  return BTPreOrderIterator<Data>::operator*();
}

/* ************************************************************************** */

// BTPostOrderIterator
/* ************************************************************************** */

// Contstructors

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> &tree) {
  if (!tree.Empty()) {
    root = tree.Root();
    loadToMostLeftLeaf(tree.Root());
  }
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator &other) {
  stack = other.stack;
  root = other.root;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator &&other) noexcept {
  std::swap(stack, other.stack);
  std::swap(root, other.root);
}

// Operators

template <typename Data>
BTPostOrderIterator<Data> &
BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data> &other) {
  BTPostOrderIterator<Data> temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
BTPostOrderIterator<Data> &&
BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data> &&other) {
  std::swap(stack, other.stack);
  std::swap(root, other.root);
  return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(
    const BTPostOrderIterator<Data> &other) const noexcept {
  return stack == other.stack && root == other.root;
}

template <typename Data>
inline bool BTPostOrderIterator<Data>::operator!=(
    const BTPostOrderIterator<Data> &other) const noexcept {
  return !(*this == other);
}

// Specific member functions

template <typename Data> const Data &BTPostOrderIterator<Data>::operator*() const {

  if (Terminated()) {
    throw std::out_of_range("Iterator has terminated");
  }

  return stack.Top()->Element();
}

template <typename Data>
inline bool BTPostOrderIterator<Data>::Terminated() const noexcept {
  return stack.Empty();
}

template <typename Data>
BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator++() {

  if (Terminated()) {
    throw std::out_of_range("Iterator has terminated");
  }

  typename BinaryTree<Data>::Node *node = stack.TopNPop();

  if (!Terminated() && stack.Top()->HasRightChild() &&
      &(stack.Top()->RightChild()) != node) {
    loadToMostLeftLeaf(stack.Top()->RightChild());
  }

  return *this;
}

template <typename Data> inline void BTPostOrderIterator<Data>::Reset() noexcept {
  stack.Clear();
  stack.Push(root);
}

// Auxiliary functions

template <typename Data>
void BTPostOrderIterator<Data>::loadToMostLeftLeaf(
    const typename BinaryTree<Data>::Node *node) noexcept {
  if (node != nullptr) {
    stack.Push(node);

    if (node.HasLeftChild()) {
      loadToMostLeftLeaf(node.LeftChild());
    } else if (node.HasRightChild()) {
      loadToMostLeftLeaf(node.RightChild());
    }
  }
}

/* ************************************************************************** */

// BTPostOrderMutableIterator
/* ******************************************Pre******************************** */

// Contstructors

template <typename Data>
inline BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(
    const MutableBinaryTree<Data> &tree)
    : BTPostOrderIterator<Data>::BTPostOrderIterator(tree) {}

template <typename Data>
inline BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(
    const BTPostOrderMutableIterator &other)
    : BTPostOrderIterator<Data>::BTPostOrderIterator(other) {}

template <typename Data>
inline BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(
    BTPostOrderMutableIterator &&other) noexcept
    : BTPostOrderIterator<Data>::BTPostOrderIterator(other) {}

// Operators

template <typename Data>
BTPostOrderMutableIterator<Data> &BTPostOrderMutableIterator<Data>::operator=(
    const BTPostOrderMutableIterator<Data> &other) {
  if (*this != other) {
    BTPostOrderIterator<Data>::operator=(other);
  }
  return *this;
}

template <typename Data>
BTPostOrderMutableIterator<Data> &&
BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator<Data> &&other) {
  if (*this != other) {
    BTPostOrderIterator<Data>::operator=(std::move(other));
  }
  return *this;
}

template <typename Data>
inline bool BTPostOrderMutableIterator<Data>::operator==(
    const BTPostOrderMutableIterator<Data> &other) const noexcept {
  return BTPostOrderIterator<Data>::operator==(other);
}

template <typename Data>
inline bool BTPostOrderMutableIterator<Data>::operator!=(
    const BTPostOrderMutableIterator<Data> &other) const noexcept {
  return !(*this == other);
}

template <typename Data> Data &BTPostOrderMutableIterator<Data>::operator*() const {
  return BTPostOrderIterator<Data>::operator*();
}

/* ************************************************************************** */

// BTInOrderIterator
/* ************************************************************************** */

// Contstructors

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &tree) {
  if (!tree.Empty()) {
    root = tree.Root();
    loadToLastLeft(tree.Root());
  }
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator &other) {
  stack = other.stack;
  root = other.root;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator &&other) noexcept {
  std::swap(stack, other.stack);
  std::swap(root, other.root);
}

// Operators

template <typename Data>
BTInOrderIterator<Data> &
BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data> &other) {
  BTInOrderIterator<Data> temp{other};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
BTInOrderIterator<Data> &&
BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data> &&other) {
  std::swap(stack, other.stack);
  std::swap(root, other.root);
  return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(
    const BTInOrderIterator<Data> &other) const noexcept {
  return stack == other.stack && root == other.root;
}

template <typename Data>
inline bool
BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data> &other) const noexcept {
  return !(*this == other);
}

// Specific member functions

template <typename Data> const Data &BTInOrderIterator<Data>::operator*() const {

  if (Terminated()) {
    throw std::out_of_range("Iterator has terminated");
  }

  return stack.Top()->Element();
}

template <typename Data>
inline bool BTInOrderIterator<Data>::Terminated() const noexcept {
  return stack.Empty();
}

template <typename Data> BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator++() {

  if (Terminated()) {
    throw std::out_of_range("Iterator has terminated");
  }

  typename BinaryTree<Data>::Node node = *stack.TopNPop();

  if (node.HasRightChild()) {
    loadToLastLeft(node.RightChild());
  }

  return *this;
}

template <typename Data> inline void BTInOrderIterator<Data>::Reset() noexcept {
  stack.Clear();
  loadToLastLeft(root);
}

// Auxiliary functions

template <typename Data>
void BTInOrderIterator<Data>::loadToLastLeft(
    const typename BinaryTree<Data>::Node *node) noexcept {
  if (node != nullptr) {
    stack.Push(node);
    if (node.HasLeftChild()) {
      loadToLastLeft(node.LeftChild());
    }
  }
}

/* ************************************************************************** */

// BTInOrderMutableIterator
/* ************************************************************************** */

// Contstructors

template <typename Data>
inline BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(
    const MutableBinaryTree<Data> &tree)
    : BTInOrderIterator<Data>::BTInOrderIterator(tree) {}

template <typename Data>
inline BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(
    const BTInOrderMutableIterator &other)
    : BTInOrderIterator<Data>::BTInOrderIterator(other) {}

template <typename Data>
inline BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(
    BTInOrderMutableIterator &&other) noexcept
    : BTInOrderIterator<Data>::BTInOrderIterator(other) {}

// Operators

template <typename Data>
BTInOrderMutableIterator<Data> &
BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data> &other) {
  if (*this != other) {
    BTInOrderIterator<Data>::operator=(other);
  }
  return *this;
}

template <typename Data>
BTInOrderMutableIterator<Data> &&
BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator<Data> &&other) {
  if (*this != other) {
    BTInOrderIterator<Data>::operator=(std::move(other));
  }
  return *this;
}

template <typename Data>
inline bool BTInOrderMutableIterator<Data>::operator==(
    const BTInOrderMutableIterator<Data> &other) const noexcept {
  return BTInOrderIterator<Data>::operator==(other);
}

template <typename Data>
inline bool BTInOrderMutableIterator<Data>::operator!=(
    const BTInOrderMutableIterator<Data> &other) const noexcept {
  return !(*this == other);
}

template <typename Data> Data &BTInOrderMutableIterator<Data>::operator*() const {
  return BTInOrderIterator<Data>::operator*();
}

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

template <typename Data> BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator++() {

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

// Contstructors

template <typename Data>
inline BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(
    const MutableBinaryTree<Data> &tree)
    : BTBreadthIterator<Data>::BTBreadthIterator(tree) {}

template <typename Data>
inline BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(
    const BTBreadthMutableIterator &other)
    : BTBreadthIterator<Data>::BTBreadthIterator(other) {}

template <typename Data>
inline BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(
    BTBreadthMutableIterator &&other) noexcept
    : BTBreadthIterator<Data>::BTBreadthIterator(other) {}

// Operators

template <typename Data>
BTBreadthMutableIterator<Data> &
BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data> &other) {
  if (*this != other) {
    BTBreadthIterator<Data>::operator=(other);
  }
  return *this;
}

template <typename Data>
BTBreadthMutableIterator<Data> &&
BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator<Data> &&other) {
  if (*this != other) {
    BTBreadthIterator<Data>::operator=(std::move(other));
  }
  return *this;
}

template <typename Data>
inline bool BTBreadthMutableIterator<Data>::operator==(
    const BTBreadthMutableIterator<Data> &other) const noexcept {
  return BTBreadthIterator<Data>::operator==(other);
}

template <typename Data>
inline bool BTBreadthMutableIterator<Data>::operator!=(
    const BTBreadthMutableIterator<Data> &other) const noexcept {
  return !(*this == other);
}

template <typename Data> Data &BTBreadthMutableIterator<Data>::operator*() const {
  return BTBreadthIterator<Data>::operator*();
}

/* ************************************************************************** */

} // namespace lasd