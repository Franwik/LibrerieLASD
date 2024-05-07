
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

// #include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
// #include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

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
  using Container::size;

public:
  struct Node {

  protected:
    // Comparison operators
    bool operator==(const Node &) const noexcept;
    inline bool operator!=(const Node &) const noexcept;

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

    virtual inline bool IsLeaf() const noexcept;
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0;

    // TODO: Don't forget to throw exceptions
    virtual const Node &
    LeftChild() const = 0; // (concrete function must throw std::out_of_range
    // when not existent)
    virtual const Node &RightChild() const = 0; // (concrete function must throw
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
  bool operator==(BinaryTree &) const noexcept;
  inline bool operator!=(BinaryTree &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // TODO: Don't forget to throw exceptions
  virtual Node &Root() const = 0; // (concrete function must throw std::length_error when
  // empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  inline void PreOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  inline void PostOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  inline void InOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  inline void BreadthTraverse(TraverseFun) const override;

protected:
  // Auxiliary functions, if necessary!
  inline void PreOrderTraverse(TraverseFun, const Node &) const;
  inline void PostOrderTraverse(TraverseFun, const Node &) const;
  inline void InOrderTraverse(TraverseFun, const Node &) const;
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
  struct MutableNode : virtual public BinaryTree<Data>::Node {

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

    // TODO: Don't forget to throw exceptions
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

  // TODO: Don't forget to throw exceptions
  virtual MutableNode &
  Root() const = 0; // (concrete function must throw std::length_error when
  // empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  inline void Map(MapFun) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  inline void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  inline void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  inline void InOrderMap(MapFun) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  inline void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:
  // Auxiliary functions, if necessary!
  inline void PreOrderMap(MapFun, MutableNode &);
  inline void PostOrderMap(MapFun, MutableNode &);
  inline void InOrderMap(MapFun, MutableNode &);
};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  const typename BinaryTree<Data>::Node *root;
  StackLst<const typename BinaryTree<Data>::Node *> stack{};

public:
  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator &);

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator &operator=(const BTPreOrderIterator &);

  // Move assignment
  BTPreOrderIterator &&operator=(BTPreOrderIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator &) const noexcept;
  inline bool operator!=(const BTPreOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data &operator*() const override;

  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;
};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : virtual public MutableIterator<Data>,
                                  virtual public BTPreOrderIterator<Data> {

private:
  // ...

protected:
public:
  // Specific constructors
  inline BTPreOrderMutableIterator(const MutableBinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  inline BTPreOrderMutableIterator(const BTPreOrderMutableIterator &);

  // Move constructor
  inline BTPreOrderMutableIterator(BTPreOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderMutableIterator &operator=(const BTPreOrderMutableIterator &);

  // Move assignment
  BTPreOrderMutableIterator &&operator=(BTPreOrderMutableIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPreOrderMutableIterator &) const noexcept;
  inline bool operator!=(const BTPreOrderMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data &operator*() const override;
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

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  const typename BinaryTree<Data>::Node *root;
  StackLst<const typename BinaryTree<Data>::Node *> stack{};

public:
  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data> &);

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

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  const typename BinaryTree<Data>::Node *root;
  QueueLst<const typename BinaryTree<Data>::Node *> queue{};

public:
  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator &);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator &operator=(const BTBreadthIterator &);

  // Move assignment
  BTBreadthIterator &&operator=(BTBreadthIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator &) const noexcept;
  inline bool operator!=(const BTBreadthIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data &operator*() const override;

  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;
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
