
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> class BinaryTreeLnk : virtual public MutableBinaryTree<Data> {

private:
  // ...

protected:
  using Container::size;
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

  struct NodeLnk : virtual public MutableBinaryTree<Data>::MutableNode {

  public:
    NodeLnk *leftChild{nullptr};
    NodeLnk *rightChild{nullptr};
    Data element{};

  public:
    /* ********************************************************************** */

    // Specific constructor
    NodeLnk(const Data &);

    NodeLnk(Data &&);

    // Copy constructor
    NodeLnk(const NodeLnk &);

    // Move constructor
    NodeLnk(NodeLnk &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~NodeLnk();

    /* ********************************************************************** */

    // Copy assignment
    NodeLnk &operator=(const NodeLnk &);

    // Move assignment
    NodeLnk &operator=(NodeLnk &&) noexcept;

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

  NodeLnk *root{nullptr};

public:
  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const TraversableContainer<Data> &);
  BinaryTreeLnk(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk &);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk &operator=(const BinaryTreeLnk &);

  // Move assignment
  BinaryTreeLnk &operator=(BinaryTreeLnk &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeLnk &) const noexcept;
  inline bool operator!=(const BinaryTreeLnk &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  inline const Node &Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  inline MutableNode &Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;
};

/* ************************************************************************** */

} // namespace lasd

#include "binarytreelnk.cpp"

#endif
