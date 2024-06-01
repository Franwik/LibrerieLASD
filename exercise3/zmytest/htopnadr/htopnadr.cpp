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

#include "../../hashtable/clsadr/htclsadr.hpp"
#include "../../hashtable/opnadr/htopnadr.hpp"

/* ************************************************************************** */

namespace mytest {

using namespace std;

/* ************************************************************************** */

void my_htopnadr_int(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctestnum{0};
  unsigned int loctesterr{0};
  cout << endl << "Begin of My HashTable Open Addressing<int> Test:" << endl;
  try {

    // TODO: add tests

    cout << "test su opnadr" << endl;

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "../Unmanaged error! " << endl;
  }
  cout << "End of My HashTable Open Addressing<int> Test! (Errors/Tests: " << loctesterr
       << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void my_htopnadr_test(unsigned int &testnum, unsigned int &testerr) {
  my_htopnadr_int(testnum, testerr);
}

} // namespace mytest