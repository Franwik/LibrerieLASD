
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../../vector/vector.hpp"
#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> class BinaryTreeVec : virtual public MutableBinaryTree<Data> {

private:
  // ...

protected:
  using Container::size;
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

  struct NodeVec : virtual public MutableBinaryTree<Data>::MutableNode {

  public:
    Data element{};
    unsigned long index{0};
    BinaryTreeVec *tree{nullptr};

    /* ********************************************************************** */

    // Specific constructor
    NodeVec(const Data &, unsigned long &, BinaryTreeVec *);

    NodeVec(Data &&, unsigned long &, BinaryTreeVec *);

    // Copy constructor
    NodeVec(const NodeVec &);

    // Move constructor
    NodeVec(NodeVec &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~NodeVec() = default;

    /* ********************************************************************** */

    // Copy assignment
    NodeVec &operator=(const NodeVec &);

    // Move assignment
    NodeVec &operator=(NodeVec &&) noexcept;

    /* ********************************************************************** */

    // Specific member functions

    const Data &Element() const noexcept override;
    Data &Element() noexcept override;

    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    inline const Node &LeftChild() const override;
    inline const Node &RightChild() const override;
    inline MutableNode &LeftChild() override;
    inline MutableNode &RightChild() override;
  };

  Vector<NodeVec *> vec;

public:
  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data> &);
  BinaryTreeVec(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec &);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec &operator=(const BinaryTreeVec &);

  // Move assignment
  BinaryTreeVec &operator=(BinaryTreeVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeVec &) const noexcept;
  inline bool operator!=(const BinaryTreeVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  inline const Node &Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  inline MutableNode &Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  void BreadthTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void BreadthMap(const MapFun) override;

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

} // namespace lasd

#include "binarytreevec.cpp"

#endif
