
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
    Node &operator=(Node &&) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    virtual const Data &Element() const noexcept = 0;

    inline bool IsLeaf() const noexcept;
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0;

    virtual const Node &LeftChild() const = 0;
    virtual const Node &RightChild() const = 0;
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree &operator=(BinaryTree &) = delete;

  // Move assignment
  BinaryTree &operator=(BinaryTree &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree &) const noexcept;
  inline bool operator!=(const BinaryTree &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Node &Root() const = 0;

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
    using BinaryTree<Data>::Node::LeftChild;
    using BinaryTree<Data>::Node::RightChild;
    using BinaryTree<Data>::Node::Element;

    /* ********************************************************************** */

    // Destructor
    virtual ~MutableNode() = default;

    /* ********************************************************************** */

    // Copy assignment
    MutableNode &operator=(MutableNode &) = delete;

    // Move assignment
    MutableNode &operator=(MutableNode &&) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    virtual Data &Element() noexcept = 0;

    virtual MutableNode &LeftChild() = 0;
    virtual MutableNode &RightChild() = 0;
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBinaryTree &operator=(MutableBinaryTree &) = delete;

  // Move assignment
  MutableBinaryTree &operator=(MutableBinaryTree &&) = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual MutableNode &Root() = 0;

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
  const typename BinaryTree<Data>::Node *root{nullptr};
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
  BTPreOrderIterator &operator=(BTPreOrderIterator &&);

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

  ForwardIterator<Data> &operator++() override;

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
  BTPreOrderMutableIterator &operator=(BTPreOrderMutableIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPreOrderMutableIterator &) const noexcept;
  inline bool operator!=(const BTPreOrderMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data &operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>,
                            virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  const typename BinaryTree<Data>::Node *root{nullptr};
  StackLst<const typename BinaryTree<Data>::Node *> stack{};

public:
  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator &);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator &operator=(const BTPostOrderIterator &);

  // Move assignment
  BTPostOrderIterator &operator=(BTPostOrderIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator &) const noexcept;
  inline bool operator!=(const BTPostOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data &operator*() const override;

  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  ForwardIterator<Data> &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;

protected:
  // Auxiliary functions

  void loadToMostLeftLeaf(const typename BinaryTree<Data>::Node *) noexcept;
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>,
                                   virtual public BTPostOrderIterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  inline BTPostOrderMutableIterator(const MutableBinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  inline BTPostOrderMutableIterator(const BTPostOrderMutableIterator &);

  // Move constructor
  inline BTPostOrderMutableIterator(BTPostOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderMutableIterator &operator=(const BTPostOrderMutableIterator &);

  // Move assignment
  BTPostOrderMutableIterator &operator=(BTPostOrderMutableIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPostOrderMutableIterator &) const noexcept;
  inline bool operator!=(const BTPostOrderMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data &operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  const typename BinaryTree<Data>::Node *root{nullptr};
  StackLst<const typename BinaryTree<Data>::Node *> stack{};

public:
  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator &);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator &operator=(const BTInOrderIterator &);

  // Move assignment
  BTInOrderIterator &operator=(BTInOrderIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator &) const noexcept;
  inline bool operator!=(const BTInOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data &operator*() const override;

  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  ForwardIterator<Data> &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;

protected:
  // Auxiliary functions

  void loadToLastLeft(const typename BinaryTree<Data>::Node *) noexcept;
};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTInOrderIterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  inline BTInOrderMutableIterator(const MutableBinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  inline BTInOrderMutableIterator(const BTInOrderMutableIterator &);

  // Move constructor
  inline BTInOrderMutableIterator(BTInOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderMutableIterator &operator=(const BTInOrderMutableIterator &);

  // Move assignment
  BTInOrderMutableIterator &operator=(BTInOrderMutableIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTInOrderMutableIterator &) const noexcept;
  inline bool operator!=(const BTInOrderMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data &operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  const typename BinaryTree<Data>::Node *root{nullptr};
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
  BTBreadthIterator &operator=(BTBreadthIterator &&);

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

  ForwardIterator<Data> &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;
};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTBreadthIterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  inline BTBreadthMutableIterator(const MutableBinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  inline BTBreadthMutableIterator(const BTBreadthMutableIterator &);

  // Move constructor
  inline BTBreadthMutableIterator(BTBreadthMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthMutableIterator &operator=(const BTBreadthMutableIterator &);

  // Move assignment
  BTBreadthMutableIterator &operator=(BTBreadthMutableIterator &&);

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTBreadthMutableIterator &) const noexcept;
  inline bool operator!=(const BTBreadthMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data &operator*() override;
};

/* ************************************************************************** */

} // namespace lasd

#include "binarytree.cpp"

#endif
