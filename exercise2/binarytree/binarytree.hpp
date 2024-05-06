
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
// #include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderTraversableContainer<Data>,
                   virtual public PostOrderTraversableContainer<Data>,
                   virtual public InOrderTraversableContainer<Data>,
                   virtual public BreadthTraversableContainer<Data> {

private:
  // ...

protected:
  // ...

public:
  struct Node {

  protected:
    // Comparison operators
    // ? what does "possible but not visible" means
    virtual bool operator==(Node &) const
        noexcept = 0; // Comparison of abstract types is possible, but is not visible.
    virtual bool operator!=(Node &) const
        noexcept = 0; // Comparison of abstract types is possible, but is not visible.

  public:
    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node &operator=(Node &) = delete;

    // Move assignment
    Node &&operator=(Node &&) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    virtual const Data &Element() const noexcept = 0;

    virtual inline bool IsLeaf() const noexcept {
      return !(HasLeftChild() && HasRightChild());
    }
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0;

    // * Don't forget to throw exceptions
    virtual const Data &
    LeftChild() const = 0; // (concrete function must throw std::out_of_range
    // when not existent)
    virtual const Data &RightChild() const = 0; // (concrete function must throw
    // std::out_of_range when not existent)
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree &operator=(BinaryTree &) = delete;

  // Move assignment
  BinaryTree &&operator=(BinaryTree &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // ? how is it possible?
  bool operator==(
      BinaryTree &) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(
      BinaryTree &) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  // * Don't forget to throw exceptions
  // ? why Node and not Data?
  virtual Node &Root() const = 0; // (concrete function must throw std::length_error when
  // empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  // TODO: implement in cpp
  inline void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // ? should't the following be virtual = 0?
  // Specific member function (inherited from PreOrderTraversableContainer)

  // TODO: implement in cpp
  inline void PreOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // TODO: implement in cpp
  inline void PostOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  // TODO: implement in cpp
  inline void InOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  // TODO: implement in cpp
  inline void BreadthTraverse(TraverseFUn) const override;

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public ClearableContainer,
                          virtual public BinaryTree<Data>,
                          virtual public PreOrderMappableContainer<Data>,
                          virtual public PostOrderMappableContainer<Data>,
                          virtual public InOrderMappableContainer<Data>,
                          virtual public BreadthMappableContainer<Data> {

private:
  // ...

protected:
  // ...

public:
  struct MutableNode : virtual public Node {

    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~MutableNode() = default;

    /* ********************************************************************** */

    // Copy assignment
    MutableNode &operator=(MutableNode &) = delete;

    // Move assignment
    MutableNode &&operator=(MutableNode &&) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    virtual Data &Element() noexcept = 0;

    // * Don't forget to throw exceptions
    virtual Data &
    LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual Data &RightChild() = 0; // (concrete function must throw std::out_of_range
                                    // when not existent)
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBinaryTree &operator=(MutableBinaryTree &) = delete;

  // Move assignment
  MutableBinaryTree &&operator=(MutableBinaryTree &&) = delete;

  /* ************************************************************************ */

  // Specific member functions

  // * Don't forget to throw exceptions
  // ? why Node and not Data?
  virtual Node &Root() const = 0; // (concrete function must throw std::length_error when
  // empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  // TODO: implement in cpp
  inline void Map(MapFun) override; // Override MappableContainer member

  /* ************************************************************************ */

  // ? should't the following be virtual = 0?
  // Specific member function (inherited from PreOrderMappableContainer)

  // TODO: implement in cpp
  inline void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // TODO: implement in cpp
  inline void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  // TODO: implement in cpp
  inline void InOrderMap(MapFun) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // TODO: implement in cpp
  inline void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  // TODO: implement in cpp
  BTPreOrderIterator(const BinaryTree<Data> &); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
};

/* ************************************************************************** */

template <typename Data> class BTPreOrderMutableIterator {
  // Must extend MutableIterator<Data>,
  //             BTPreOrderIterator<Data>

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable
  // binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderMutableIterator(argument) specifiers;

  // Move constructor
  // BTPreOrderMutableIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderMutableIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
};

/* ************************************************************************** */

template <typename Data> class BTPostOrderIterator {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
};

/* ************************************************************************** */

template <typename Data> class BTPostOrderMutableIterator {
  // Must extend MutableIterator<Data>,
  //             BTPostOrderIterator<Data>

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  // BTPostOrderMutableIterator(argument) specifiers; // An iterator over a given mutable
  // binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderMutableIterator(argument) specifiers;

  // Move constructor
  // BTPostOrderMutableIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderMutableIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
};

/* ************************************************************************** */

template <typename Data> class BTInOrderIterator {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;

  // Move constructor
  // BTInOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
};

/* ************************************************************************** */

template <typename Data> class BTInOrderMutableIterator {
  // Must extend MutableIterator<Data>,
  //             BTInOrderIterator<Data>

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable
  // binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderMutableIterator(argument) specifiers;

  // Move constructor
  // BTInOrderMutableIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderMutableIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
};

/* ************************************************************************** */

template <typename Data> class BTBreadthIterator {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;

  // Move constructor
  // BTBreadthIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
};

/* ************************************************************************** */

template <typename Data> class BTBreadthMutableIterator {
  // Must extend MutableIterator<Data>,
  //             BTBreadthIterator<Data>

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable
  // binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthMutableIterator(argument) specifiers;

  // Move constructor
  // BTBreadthMutableIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthMutableIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
};

/* ************************************************************************** */

} // namespace lasd

#include "binarytree.cpp"

#endif
