#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/queue/queue.hpp"
#include "../../zlasdtest/stack/stack.hpp"
#include "../../zlasdtest/vector/vector.hpp"

/* ************************************************************************** */

#include "../../binarytree/binarytree.hpp"
#include "../../bst/bst.hpp"
#include "../../iterator/iterator.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void my_bst_int(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctestnum{0};
  unsigned int loctesterr{0};
  cout << endl << "Begin of My BST<int> Test:" << endl;
  try {
    // TODO: add tests
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