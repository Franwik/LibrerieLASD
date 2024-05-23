
namespace lasd {

// PreOrderMappableContainer
/* ************************************************************************** */

// Overrided methods

template <typename Data> inline void PreOrderMappableContainer<Data>::Map(MapFun fun) {
  PreOrderMap(fun);
}

/* ************************************************************************** */

// PostOrderMappableContainer
/* ************************************************************************** */

// Overrided methods

template <typename Data> inline void PostOrderMappableContainer<Data>::Map(MapFun fun) {
  PostOrderMap(fun);
}

/* ************************************************************************** */

// InOrderMappableContainer
/* ************************************************************************** */

template <typename Data>
inline void InOrderMappableContainer<Data>::Map(const MapFun fun) {
  InOrderMap(fun);
}

/* ************************************************************************** */

// BreadthMappableContainer
/* ************************************************************************** */

template <typename Data>
inline void BreadthMappableContainer<Data>::Map(const MapFun fun) {
  BreadthMap(fun);
}

/* ************************************************************************** */

} // namespace lasd
