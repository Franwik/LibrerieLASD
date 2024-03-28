
#ifndef TRAVERSABLETEST_HPP
#define TRAVERSABLETEST_HPP

#include "../../container/traversable.hpp"

/* ************************************************************************** */

// TraversableContainer member functions!

template <typename Data>
void Traverse(unsigned long & testnum, unsigned long & testerr, const lasd::TraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::TraverseFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing traverse - ";
    con.Traverse(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

template <typename Data, typename Value>
void Fold(unsigned long & testnum, unsigned long & testerr, const lasd::TraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival, const Value & finval) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold - ";
    Value val = con.Fold(fun, inival);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

template <typename Data>
void TraversePrint(const Data & dat) {
  std::cout << dat << " ";
}

template <typename Data>
Data FoldAdd(const Data & dat, const Data & acc) {
  return (acc + dat);
}

template <typename Data>
Data FoldMultiply(const Data & dat, const Data & acc) {
  return (acc * dat);
}

int FoldParity(const int &, const int &);

std::string FoldStringConcatenate(const std::string &, const std::string &);

/* ************************************************************************** */

// PreOrderTraversableContainer member functions!

template <typename Data>
void TraversePreOrder(unsigned long & testnum, unsigned long & testerr, const lasd::PreOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::TraverseFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing traverse in pre order - ";
    con.PreOrderTraverse(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

template <typename Data, typename Value>
void FoldPreOrder(unsigned long & testnum, unsigned long & testerr, const lasd::PreOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival, const Value & finval) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in pre order - ";
    Value val = con.PreOrderFold(fun, inival);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

/* ************************************************************************** */

// PostOrderTraversableContainer member functions!

template <typename Data>
void TraversePostOrder(unsigned long & testnum, unsigned long & testerr, const lasd::PostOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::TraverseFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing traverse in post order - ";
    con.PostOrderTraverse(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

template <typename Data, typename Value>
void FoldPostOrder(unsigned long & testnum, unsigned long & testerr, const lasd::PostOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival, const Value & finval) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in post order - ";
    Value val = con.PostOrderFold(fun, inival);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

/* ************************************************************************** */

// InOrderTraversableContainer member functions!

template <typename Data>
void TraverseInOrder(unsigned long & testnum, unsigned long & testerr, const lasd::InOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::TraverseFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing traverse in order - ";
    con.InOrderTraverse(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

template <typename Data, typename Value>
void FoldInOrder(unsigned long & testnum, unsigned long & testerr, const lasd::InOrderTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival, const Value & finval) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in order - ";
    Value val = con.InOrderFold(fun, inival);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

/* ************************************************************************** */

// BreadthTraversableContainer member functions!

template <typename Data>
void TraverseBreadth(unsigned long & testnum, unsigned long & testerr, const lasd::BreadthTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::TraverseFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing traverse in breadth - ";
    con.BreadthTraverse(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

template <typename Data, typename Value>
void FoldBreadth(unsigned long & testnum, unsigned long & testerr, const lasd::BreadthTraversableContainer<Data> & con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival, const Value & finval) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing fold in breadth - ";
    Value val = con.BreadthFold(fun, inival);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned long) tst);
}

/* ************************************************************************** */

#endif
