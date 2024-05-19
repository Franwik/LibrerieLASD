#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/binarytree/binarytree.hpp"
#include "../../zlasdtest/bst/bst.hpp"
#include "../../zlasdtest/iterator/iterator.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/queue/queue.hpp"
#include "../../zlasdtest/stack/stack.hpp"
#include "../../zlasdtest/vector/vector.hpp"

/* ************************************************************************** */

#include "../../binarytree/binarytree.hpp"
#include "../../bst/bst.hpp"
#include "../../iterator/iterator.hpp"

/* ************************************************************************** */

namespace mytest {

using namespace std;

/* ************************************************************************** */

void my_bst_int(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctestnum{0};
  unsigned int loctesterr{0};
  cout << endl << "Begin of My BST<int> Test:" << endl;
  try {

    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    Min(loctestnum, loctesterr, bst, false, 0);
    Max(loctestnum, loctesterr, bst, false, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 7);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 2);
    InsertC(loctestnum, loctesterr, bst, true, 9);
    InsertC(loctestnum, loctesterr, bst, false, 2);

    Empty(loctestnum, loctesterr, bst, false);
    Size(loctestnum, loctesterr, bst, true, 5);

    Min(loctestnum, loctesterr, bst, true, 2);
    Max(loctestnum, loctesterr, bst, true, 9);

    Root(loctestnum, loctesterr, bst, true, 3);

    Exists(loctestnum, loctesterr, bst, true, 7);
    Exists(loctestnum, loctesterr, bst, false, 1);

    RemoveMin(loctestnum, loctesterr, bst, true);
    MinNRemove(loctestnum, loctesterr, bst, true, 3);

    Root(loctestnum, loctesterr, bst, true, 7);

    Min(loctestnum, loctesterr, bst, true, 5);

    RemoveMax(loctestnum, loctesterr, bst, true);
    MaxNRemove(loctestnum, loctesterr, bst, true, 7);

    Root(loctestnum, loctesterr, bst, true, 5);

    Size(loctestnum, loctesterr, bst, true, 1);

    Remove(loctestnum, loctesterr, bst, false, 7);
    Remove(loctestnum, loctesterr, bst, true, 5);

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 7);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 2);
    InsertC(loctestnum, loctesterr, bst, true, 9);

    TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Predecessor(loctestnum, loctesterr, bst, true, 4, 3);
    Successor(loctestnum, loctesterr, bst, true, 4, 5);

    RemovePredecessor(loctestnum, loctesterr, bst, false, 2);
    RemoveSuccessor(loctestnum, loctesterr, bst, false, 9);

    RemovePredecessor(loctestnum, loctesterr, bst, true, 4);
    Predecessor(loctestnum, loctesterr, bst, true, 4, 2);

    Root(loctestnum, loctesterr, bst, true, 5);

    TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    RemoveSuccessor(loctestnum, loctesterr, bst, true, 4);
    Successor(loctestnum, loctesterr, bst, true, 4, 7);

    PredecessorNRemove(loctestnum, loctesterr, bst, true, 4, 2);
    SuccessorNRemove(loctestnum, loctesterr, bst, true, 4, 7);

    bst.Clear();
    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    lasd::Vector<int> vec(5);

    SetAt(loctestnum, loctesterr, vec, true, 0, 3);
    SetAt(loctestnum, loctesterr, vec, true, 1, 7);
    SetAt(loctestnum, loctesterr, vec, true, 2, 5);
    SetAt(loctestnum, loctesterr, vec, true, 3, 2);
    SetAt(loctestnum, loctesterr, vec, true, 4, 9);

    lasd::BST<int> copbst1(vec);
    TraverseInOrder(loctestnum, loctesterr, copbst1, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    lasd::BST<int> movbst1(std::move(vec));
    TraverseInOrder(loctestnum, loctesterr, movbst1, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

    EqualBST(loctestnum, loctesterr, copbst1, movbst1);

    lasd::BST<int> copbst2(copbst1);
    EqualBST(loctestnum, loctesterr, copbst1, copbst2);

    lasd::BST<int> movbst2(std::move(movbst1));
    TraverseInOrder(loctestnum, loctesterr, movbst1, true, &TraversePrint<int>);
    TraverseInOrder(loctestnum, loctesterr, movbst2, true, &TraversePrint<int>);
    NonEqualBST(loctestnum, loctesterr, movbst1, movbst2);

    lasd::BTPreOrderIterator<int> PreItr1(copbst1);
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 3);
    ++PreItr1;
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 2);
    ++PreItr1;
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 7);
    Terminated(loctestnum, loctesterr, PreItr1, false);

    lasd::BTPreOrderIterator<int> PreItr2(PreItr1);

    GetItrValue(loctestnum, loctesterr, PreItr2, true, 7);
    PreItr2.Reset();
    GetItrValue(loctestnum, loctesterr, PreItr2, true, 3);

    ++PreItr1;
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 5);
    ++PreItr1;
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 9);
    ++PreItr1;
    Terminated(loctestnum, loctesterr, PreItr1, true);
    PreItr1.Reset();

    lasd::BTPreOrderIterator<int> PreItr3(std::move(PreItr1));

    Terminated(loctestnum, loctesterr, PreItr1, true);
    Terminated(loctestnum, loctesterr, PreItr3, false);
    GetItrValue(loctestnum, loctesterr, PreItr3, true, 3);

    lasd::BTPostOrderIterator<int> PostItr1(copbst1);
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 2);
    ++PostItr1;
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 5);
    ++PostItr1;
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 9);
    Terminated(loctestnum, loctesterr, PostItr1, false);

    lasd::BTPostOrderIterator<int> PostItr2(PostItr1);

    GetItrValue(loctestnum, loctesterr, PostItr2, true, 9);
    PostItr2.Reset();
    GetItrValue(loctestnum, loctesterr, PostItr2, true, 2);

    ++PostItr1;
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 7);
    ++PostItr1;
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 3);
    ++PostItr1;
    Terminated(loctestnum, loctesterr, PostItr1, true);
    PostItr1.Reset();

    lasd::BTPostOrderIterator<int> PostItr3(std::move(PostItr1));

    Terminated(loctestnum, loctesterr, PostItr1, true);
    Terminated(loctestnum, loctesterr, PostItr3, false);
    GetItrValue(loctestnum, loctesterr, PostItr3, true, 2);

    lasd::BTInOrderIterator<int> InItr1(copbst1);
    GetItrValue(loctestnum, loctesterr, InItr1, true, 2);
    ++InItr1;
    GetItrValue(loctestnum, loctesterr, InItr1, true, 3);
    ++InItr1;
    GetItrValue(loctestnum, loctesterr, InItr1, true, 5);
    Terminated(loctestnum, loctesterr, InItr1, false);

    lasd::BTInOrderIterator<int> InItr2(InItr1);

    GetItrValue(loctestnum, loctesterr, InItr2, true, 5);
    InItr2.Reset();
    GetItrValue(loctestnum, loctesterr, InItr2, true, 2);

    ++InItr1;
    GetItrValue(loctestnum, loctesterr, InItr1, true, 7);
    ++InItr1;
    GetItrValue(loctestnum, loctesterr, InItr1, true, 9);
    ++InItr1;
    Terminated(loctestnum, loctesterr, InItr1, true);
    InItr1.Reset();

    lasd::BTInOrderIterator<int> InItr3(std::move(InItr1));

    Terminated(loctestnum, loctesterr, InItr1, true);
    Terminated(loctestnum, loctesterr, InItr3, false);
    GetItrValue(loctestnum, loctesterr, InItr3, true, 2);

    lasd::BTBreadthIterator<int> BreadthItr1(copbst1);
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 3);
    ++BreadthItr1;
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 2);
    ++BreadthItr1;
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 7);
    Terminated(loctestnum, loctesterr, BreadthItr1, false);

    lasd::BTBreadthIterator<int> BreadthItr2(BreadthItr1);

    GetItrValue(loctestnum, loctesterr, BreadthItr2, true, 7);
    BreadthItr2.Reset();
    GetItrValue(loctestnum, loctesterr, BreadthItr2, true, 3);

    ++BreadthItr1;
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 5);
    ++BreadthItr1;
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 9);
    ++BreadthItr1;
    Terminated(loctestnum, loctesterr, BreadthItr1, true);
    BreadthItr1.Reset();

    lasd::BTBreadthIterator<int> BreadthItr3(std::move(BreadthItr1));

    Terminated(loctestnum, loctesterr, BreadthItr1, true);
    Terminated(loctestnum, loctesterr, BreadthItr3, false);
    GetItrValue(loctestnum, loctesterr, BreadthItr3, true, 3);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "../Unmanaged error! " << endl;
  }
  cout << "End of My BST<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum
       << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void my_bst_test(unsigned int &testnum, unsigned int &testerr) {
  my_bst_int(testnum, testerr);
}

} // namespace mytest