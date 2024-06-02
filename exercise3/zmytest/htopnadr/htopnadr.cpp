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

#include "../../zlasdtest/hashtable/hashtable.hpp"

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

    lasd::Vector<int> vec1{200};
    lasd::Vector<int> vec2{200};
    lasd::Vector<int> vec3{200};

    for (int i = 0; i < 200; i++) {
      vec1[i] = i;
      vec2[i] = 200 + i;
      vec3[i] = 100 + i;
    }

    TraversePreOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

    lasd::HashTableOpnAdr<int> ht1;
    Size(loctestnum, loctesterr, ht1, true, 0);
    Empty(loctestnum, loctesterr, ht1, true);

    lasd::HashTableOpnAdr<int> ht2(200);
    Size(loctestnum, loctesterr, ht2, true, 0);
    Empty(loctestnum, loctesterr, ht2, true);

    lasd::HashTableOpnAdr<int> ht3(vec1);
    Size(loctestnum, loctesterr, ht3, true, 200);
    Empty(loctestnum, loctesterr, ht3, false);

    lasd::HashTableOpnAdr<int> ht4(300, vec2);
    Size(loctestnum, loctesterr, ht4, true, 200);
    Empty(loctestnum, loctesterr, ht4, false);

    lasd::HashTableOpnAdr<int> ht5(std::move(vec1));
    Size(loctestnum, loctesterr, ht5, true, 200);
    Empty(loctestnum, loctesterr, ht5, false);

    TraversePreOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);

    lasd::HashTableOpnAdr<int> ht6(50, std::move(vec2));
    Size(loctestnum, loctesterr, ht6, true, 200);
    Empty(loctestnum, loctesterr, ht6, false);

    TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

    lasd::HashTableOpnAdr<int> ht7(ht3);
    Size(loctestnum, loctesterr, ht7, true, 200);
    Empty(loctestnum, loctesterr, ht7, false);
    EqualHT(loctestnum, loctesterr, ht7, ht3);

    lasd::HashTableOpnAdr<int> ht8(std::move(ht4));
    Size(loctestnum, loctesterr, ht8, true, 200);
    Empty(loctestnum, loctesterr, ht8, false);
    NonEqualHT(loctestnum, loctesterr, ht8, ht4);

    ht1 = ht7;
    Size(loctestnum, loctesterr, ht1, true, 200);
    Empty(loctestnum, loctesterr, ht1, false);
    EqualHT(loctestnum, loctesterr, ht1, ht7);

    ht8 = std::move(ht4);
    Size(loctestnum, loctesterr, ht4, true, 200);
    Empty(loctestnum, loctesterr, ht4, false);
    NonEqualHT(loctestnum, loctesterr, ht4, ht8);

    for (int i = 0; i < 200; i++) {
      vec1[i] = i;
      vec2[i] = 200 + i;
    }

    CountHT(loctestnum, loctesterr, ht1, vec3, 100);

    for (int i = 0; i < 100; i++) {
      Remove(loctestnum, loctesterr, ht1, vec1[i + 50]);
      Remove(loctestnum, loctesterr, ht1, 200 + i);
    }

    Size(loctestnum, loctesterr, ht1, true, 100);
    CountHT(loctestnum, loctesterr, ht1, vec3, 50);

    for (int i = 0; i < 100; i++) {
      InsertC(loctestnum, loctesterr, ht4, vec2[i + 50]);
      InsertC(loctestnum, loctesterr, ht4, 1000 + i);
    }

    Size(loctestnum, loctesterr, ht4, true, 300);

    ht4.Resize(200);
    Size(loctestnum, loctesterr, ht4, true, 300);

    ht4.Resize(1000);
    Size(loctestnum, loctesterr, ht4, true, 300);

    ht1.Clear();
    Size(loctestnum, loctesterr, ht1, false, 100);
    ht2.Clear();
    Size(loctestnum, loctesterr, ht2, false, 100);
    ht3.Clear();
    Size(loctestnum, loctesterr, ht3, false, 100);
    ht4.Clear();
    Size(loctestnum, loctesterr, ht4, false, 100);
    ht5.Clear();
    Size(loctestnum, loctesterr, ht5, false, 100);
    ht6.Clear();
    Size(loctestnum, loctesterr, ht6, false, 100);
    ht7.Clear();
    Size(loctestnum, loctesterr, ht7, false, 100);
    ht8.Clear();
    Size(loctestnum, loctesterr, ht8, false, 100);

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