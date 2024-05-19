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
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../bst/bst.hpp"
#include "../../iterator/iterator.hpp"

/* ************************************************************************** */

namespace mytest {

using namespace std;

/* ************************************************************************** */

void my_binarytree_lnk(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctestnum{0};
  unsigned int loctesterr{0};
  cout << endl << "Begin of My BinaryTreeLnk<int> Test:" << endl;
  try {

    lasd::Vector<int> vec(5);

    for (int i = 0; i < 5; i++) {
      SetAt(loctestnum, loctesterr, vec, true, i, i + 5);
    }

    lasd::BinaryTreeLnk<int> copbt1(vec);

    lasd::BinaryTreeLnk<int> copbt2(copbt1);

    EqualBT(loctestnum, loctesterr, copbt1, copbt2);

    Empty(loctestnum, loctesterr, copbt1, false);
    Size(loctestnum, loctesterr, copbt1, true, 5);
    Root(loctestnum, loctesterr, copbt1, true, 5);

    unsigned long i = 0;
    TraversePreOrder(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    MapPreOrder(loctestnum, loctesterr, copbt1, true, [&i](int &data) {
      data += i++;
      cout << data << " ";
    });
    i = 0;
    TraversePostOrder(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    MapPostOrder(loctestnum, loctesterr, copbt1, true, [&i](int &data) {
      data += i++;
      cout << data << " ";
    });
    i = 0;
    TraverseInOrder(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    MapInOrder(loctestnum, loctesterr, copbt1, true, [&i](int &data) {
      data += i++;
      cout << data << " ";
    });
    i = 0;
    TraverseBreadth(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    MapBreadth(loctestnum, loctesterr, copbt1, true, [&i](int &data) {
      data += i++;
      cout << data << " ";
    });

    lasd::BinaryTreeLnk<int> movbt(std::move(vec));
    Size(loctestnum, loctesterr, vec, true, 5);
    Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, movbt, true, 5);
    Traverse(loctestnum, loctesterr, movbt, true, &TraversePrint<int>);

    NonEqualBT(loctestnum, loctesterr, copbt1, copbt2);
    NonEqualBT(loctestnum, loctesterr, copbt1, movbt);
    EqualBT(loctestnum, loctesterr, copbt2, movbt);

    lasd::BinaryTreeLnk<int> copbt3;
    Empty(loctestnum, loctesterr, copbt3, true);

    copbt3 = movbt;

    Empty(loctestnum, loctesterr, copbt3, false);
    EqualBT(loctestnum, loctesterr, copbt3, movbt);
    NonEqualBT(loctestnum, loctesterr, copbt3, copbt1);
    Traverse(loctestnum, loctesterr, copbt3, true, &TraversePrint<int>);

    movbt = std::move(copbt1);

    NonEqualBT(loctestnum, loctesterr, copbt3, movbt);
    EqualBT(loctestnum, loctesterr, copbt3, copbt1);

    copbt1.Clear();
    Empty(loctestnum, loctesterr, copbt1, true);
    Size(loctestnum, loctesterr, copbt1, true, 0);

    Traverse(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, copbt2, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, copbt3, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, movbt, true, &TraversePrint<int>);

    lasd::BTPreOrderIterator<int> PreItr1(copbt2);
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 5);
    ++PreItr1;
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 6);
    ++PreItr1;
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 8);
    Terminated(loctestnum, loctesterr, PreItr1, false);

    lasd::BTPreOrderIterator<int> PreItr2(PreItr1);

    GetItrValue(loctestnum, loctesterr, PreItr2, true, 8);
    PreItr2.Reset();
    GetItrValue(loctestnum, loctesterr, PreItr2, true, 5);

    ++PreItr1;
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 9);
    ++PreItr1;
    GetItrValue(loctestnum, loctesterr, PreItr1, true, 7);
    ++PreItr1;
    Terminated(loctestnum, loctesterr, PreItr1, true);
    PreItr1.Reset();

    lasd::BTPreOrderIterator<int> PreItr3(std::move(PreItr1));

    Terminated(loctestnum, loctesterr, PreItr1, true);
    Terminated(loctestnum, loctesterr, PreItr3, false);
    GetItrValue(loctestnum, loctesterr, PreItr3, true, 5);

    lasd::BTPostOrderIterator<int> PostItr1(copbt2);
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 8);
    ++PostItr1;
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 9);
    ++PostItr1;
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 6);
    Terminated(loctestnum, loctesterr, PostItr1, false);

    lasd::BTPostOrderIterator<int> PostItr2(PostItr1);

    GetItrValue(loctestnum, loctesterr, PostItr2, true, 6);
    PostItr2.Reset();
    GetItrValue(loctestnum, loctesterr, PostItr2, true, 8);

    ++PostItr1;
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 7);
    ++PostItr1;
    GetItrValue(loctestnum, loctesterr, PostItr1, true, 5);
    ++PostItr1;
    Terminated(loctestnum, loctesterr, PostItr1, true);
    PostItr1.Reset();

    lasd::BTPostOrderIterator<int> PostItr3(std::move(PostItr1));

    Terminated(loctestnum, loctesterr, PostItr1, true);
    Terminated(loctestnum, loctesterr, PostItr3, false);
    GetItrValue(loctestnum, loctesterr, PostItr3, true, 8);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "../Unmanaged error! " << endl;
  }
  cout << "End of My BinaryTreeLnk<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void my_binarytree_vec(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctestnum{0};
  unsigned int loctesterr{0};
  cout << endl << "Begin of My BinaryTreeVec<int> Test:" << endl;
  try {

    lasd::Vector<int> vec(5);

    for (int i = 0; i < 5; i++) {
      SetAt(loctestnum, loctesterr, vec, true, i, i + 5);
    }

    lasd::BinaryTreeVec<int> copbt1(vec);

    lasd::BinaryTreeVec<int> copbt2(copbt1);

    EqualBT(loctestnum, loctesterr, copbt1, copbt2);

    Empty(loctestnum, loctesterr, copbt1, false);
    Size(loctestnum, loctesterr, copbt1, true, 5);
    Root(loctestnum, loctesterr, copbt1, true, 5);

    unsigned long i = 0;
    TraversePreOrder(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    MapPreOrder(loctestnum, loctesterr, copbt1, true, [&i](int &data) {
      data += i++;
      cout << data << " ";
    });
    i = 0;
    TraversePostOrder(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    MapPostOrder(loctestnum, loctesterr, copbt1, true, [&i](int &data) {
      data += i++;
      cout << data << " ";
    });
    i = 0;
    TraverseInOrder(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    MapInOrder(loctestnum, loctesterr, copbt1, true, [&i](int &data) {
      data += i++;
      cout << data << " ";
    });
    i = 0;
    TraverseBreadth(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    MapBreadth(loctestnum, loctesterr, copbt1, true, [&i](int &data) {
      data += i++;
      cout << data << " ";
    });

    lasd::BinaryTreeVec<int> movbt(std::move(vec));
    Size(loctestnum, loctesterr, vec, true, 5);
    Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, movbt, true, 5);
    Traverse(loctestnum, loctesterr, movbt, true, &TraversePrint<int>);

    NonEqualBT(loctestnum, loctesterr, copbt1, copbt2);
    NonEqualBT(loctestnum, loctesterr, copbt1, movbt);
    EqualBT(loctestnum, loctesterr, copbt2, movbt);

    lasd::BinaryTreeVec<int> copbt3;
    Empty(loctestnum, loctesterr, copbt3, true);

    copbt3 = movbt;

    Empty(loctestnum, loctesterr, copbt3, false);
    EqualBT(loctestnum, loctesterr, copbt3, movbt);
    NonEqualBT(loctestnum, loctesterr, copbt3, copbt1);
    Traverse(loctestnum, loctesterr, copbt3, true, &TraversePrint<int>);

    movbt = std::move(copbt1);

    EqualBT(loctestnum, loctesterr, copbt3, copbt1);
    NonEqualBT(loctestnum, loctesterr, copbt3, movbt);

    copbt1.Clear();
    Empty(loctestnum, loctesterr, copbt1, true);
    Size(loctestnum, loctesterr, copbt1, true, 0);

    Traverse(loctestnum, loctesterr, copbt1, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, copbt2, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, copbt3, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, movbt, true, &TraversePrint<int>);

    lasd::BTInOrderIterator<int> InItr1(copbt2);
    GetItrValue(loctestnum, loctesterr, InItr1, true, 8);
    ++InItr1;
    GetItrValue(loctestnum, loctesterr, InItr1, true, 6);
    ++InItr1;
    GetItrValue(loctestnum, loctesterr, InItr1, true, 9);
    Terminated(loctestnum, loctesterr, InItr1, false);

    lasd::BTInOrderIterator<int> InItr2(InItr1);

    GetItrValue(loctestnum, loctesterr, InItr2, true, 9);
    InItr2.Reset();
    GetItrValue(loctestnum, loctesterr, InItr2, true, 8);

    ++InItr1;
    GetItrValue(loctestnum, loctesterr, InItr1, true, 5);
    ++InItr1;
    GetItrValue(loctestnum, loctesterr, InItr1, true, 7);
    ++InItr1;
    Terminated(loctestnum, loctesterr, InItr1, true);
    InItr1.Reset();

    lasd::BTInOrderIterator<int> InItr3(std::move(InItr1));

    Terminated(loctestnum, loctesterr, InItr1, true);
    Terminated(loctestnum, loctesterr, InItr3, false);
    GetItrValue(loctestnum, loctesterr, InItr3, true, 8);

    lasd::BTBreadthIterator<int> BreadthItr1(copbt2);
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 5);
    ++BreadthItr1;
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 6);
    ++BreadthItr1;
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 7);
    Terminated(loctestnum, loctesterr, BreadthItr1, false);

    lasd::BTBreadthIterator<int> BreadthItr2(BreadthItr1);

    GetItrValue(loctestnum, loctesterr, BreadthItr2, true, 7);
    BreadthItr2.Reset();
    GetItrValue(loctestnum, loctesterr, BreadthItr2, true, 5);

    ++BreadthItr1;
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 8);
    ++BreadthItr1;
    GetItrValue(loctestnum, loctesterr, BreadthItr1, true, 9);
    ++BreadthItr1;
    Terminated(loctestnum, loctesterr, BreadthItr1, true);
    BreadthItr1.Reset();

    lasd::BTBreadthIterator<int> BreadthItr3(std::move(BreadthItr1));

    Terminated(loctestnum, loctesterr, BreadthItr1, true);
    Terminated(loctestnum, loctesterr, BreadthItr3, false);
    GetItrValue(loctestnum, loctesterr, BreadthItr3, true, 5);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "../Unmanaged error! " << endl;
  }
  cout << "End of My BinaryTreeVec<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void my_binarytree_lnk_vec(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctestnum{0};
  unsigned int loctesterr{0};
  cout << endl << "Begin of My BinaryTreeLnk/Vec<int> Test:" << endl;
  try {

    lasd::Vector<int> vec(5);

    for (int i = 0; i < 5; i++) {
      SetAt(loctestnum, loctesterr, vec, true, i, i + 5);
    }

    lasd::BinaryTreeLnk<int> btlnk(vec);

    lasd::BinaryTreeVec<int> btvec(btlnk);

    Traverse(loctestnum, loctesterr, btlnk, true, &TraversePrint<int>);
    Traverse(loctestnum, loctesterr, btvec, true, &TraversePrint<int>);

    EqualBT(loctestnum, loctesterr, btlnk, btvec);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "../Unmanaged error! " << endl;
  }
  cout << "End of My BinaryTreeLnk/Vec<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void my_binarytree_test(unsigned int &testnum, unsigned int &testerr) {
  my_binarytree_lnk(testnum, testerr);
  my_binarytree_vec(testnum, testerr);
  my_binarytree_lnk_vec(testnum, testerr);
}

} // namespace mytest