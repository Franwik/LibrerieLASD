
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public ClearableContainer,
            virtual public DictionaryContainer<Data>,
            virtual public BinaryTree<Data>,
            virtual protected BinaryTreeLnk<Data> {

private:
  // ...

protected:
  using Container::size;
  using typename BinaryTree<Data>::Node;
  using typename BinaryTreeLnk<Data>::NodeLnk;
  using BinaryTreeLnk<Data>::root;

public:
  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const TraversableContainer<Data> &);
  BST(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST &);

  // Move constructor
  BST(BST &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST &operator=(const BST &);

  // Move assignment
  BST &operator=(BST &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST &) const noexcept;
  inline bool operator!=(const BST &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  const Data &Min() const;
  Data MinNRemove();
  void RemoveMin();

  const Data &Max() const;
  Data MaxNRemove();
  void RemoveMax();

  const Data &Predecessor(const Data &) const;
  Data PredecessorNRemove(const Data &);
  void RemovePredecessor(const Data &);

  const Data &Successor(const Data &) const;
  Data SuccessorNRemove(const Data &);
  void RemoveSuccessor(const Data &);

  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  inline const Node &Root() const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data &) override;
  bool Insert(Data &&) override;
  bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data &) const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;

protected:
  // Auxiliary functions, if necessary!

  const NodeLnk *Min(const NodeLnk *) const;
  NodeLnk *Min(NodeLnk *);

  const NodeLnk *Max(const NodeLnk *) const;
  NodeLnk *Max(NodeLnk *);

  const NodeLnk *Predecessor(const NodeLnk *, const Data &, const NodeLnk *) const;
  NodeLnk *Predecessor(NodeLnk *, const Data &, NodeLnk *);

  const NodeLnk *Successor(const NodeLnk *, const Data &, const NodeLnk *) const;
  NodeLnk *Successor(NodeLnk *, const Data &, NodeLnk *);

  bool Search(const NodeLnk *, const Data &) const;
  bool Search(NodeLnk *, const Data &);

  NodeLnk *Insert(NodeLnk *, const Data &);
  NodeLnk *Insert(NodeLnk *, Data &&);

  NodeLnk *Remove(NodeLnk *, const Data &);
  NodeLnk *DeleteData(NodeLnk *);

  NodeLnk *skipRight(NodeLnk *);
  NodeLnk *skipLeft(NodeLnk *);

  const Data GetNDeleteMin(NodeLnk *, NodeLnk *);
  void swapChild(NodeLnk *, NodeLnk *, NodeLnk *);
};

/* ************************************************************************** */

} // namespace lasd

#include "bst.cpp"

#endif
