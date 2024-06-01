#include <iostream>

/* ************************************************************************** */

#include "../../../zlasdtest/container/container.hpp"
#include "../../../zlasdtest/container/dictionary.hpp"
#include "../../../zlasdtest/container/linear.hpp"
#include "../../../zlasdtest/container/mappable.hpp"
#include "../../../zlasdtest/container/testable.hpp"
#include "../../../zlasdtest/container/traversable.hpp"

#include "../../../zlasdtest/list/list.hpp"
#include "../../../zlasdtest/queue/queue.hpp"
#include "../../../zlasdtest/stack/stack.hpp"
#include "../../../zlasdtest/vector/vector.hpp"

#include "../../../zlasdtest/binarytree/binarytree.hpp"
#include "../../../zlasdtest/bst/bst.hpp"
#include "../../../zlasdtest/iterator/iterator.hpp"

#include "../../../zlasdtest/hashtable/hashtable.hpp"

/* ************************************************************************** */

#include "../../../hashtable/clsadr/htclsadr.hpp"
#include "../../../hashtable/hashtable.hpp"
#include "../../../hashtable/opnadr/htopnadr.hpp"

/* ************************************************************************** */

namespace mytest {

using namespace std;

/* ************************************************************************** */

void my_ht_closed_addressing(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctestnum{0};
  unsigned int loctesterr{0};
  cout << endl << "Begin of My Hash Table Closed Addressing Test:" << endl;
  try {
    
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "../Unmanaged error! " << endl;
  }
  cout << "End of My Hash Table Closed Addressing Test! (Errors/Tests: " << loctesterr
       << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void my_ht_closed_addressing_test(unsigned int &testnum, unsigned int &testerr) {
  my_ht_closed_addressing(testnum, testerr);
}

} // namespace mytest