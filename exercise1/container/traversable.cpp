
namespace lasd {

/* ************************************************************************** */

// Traversable Method Implementations

template <typename Data>
bool TraversableContainer<Data>::Exists(const Data &) const noexcept {

    bool isElementFound = false;

    Traverse(
      [&isElementFound](const Data &currData)
      {isElementFound = (isElementFound || (data == currData));}
    );

    return isElementFound;
  }

/* ************************************************************************** */

// PreOrderTraversableContainer Method Implementations

/* ************************************************************************** */

// PostOrderTraversableContainer Method Implementations

/* ************************************************************************** */

}
