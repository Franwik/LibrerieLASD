#include <functional>
#include <iostream>

/* ************************************************************************** */

#include "vector/vector.hpp"
#include "list/list.hpp"
#include "stack/stack.hpp"
#include "queue/queue.hpp"

using namespace std;
using TestFun = function<void(unsigned int &, unsigned int &)>;

unsigned int testnum = 0;
unsigned int testerr = 0;

/* ************************************************************************** */

void run(TestFun);

/* ************************************************************************** */

// Add Test To Run Here
void runTests() {

  run(my_vector_test);

  run(my_list_test);

  run(my_stack_test);

  run(my_queue_test);
}

void run(TestFun test) {
  unsigned int loctestnum = 0, loctesterr = 0;
  test(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

string comment(unsigned int testerr) {

  if (testerr > 0) {
    return " CHECK YOUR ERRORS (⨱^⨱) ";
  } else {
    return "~ CONGRATULATIONS (•◡•) ~";
  }
}

void mytest() {

  cout << "\n+---------------------------------------------------------------------------"
          "---+\n";
  cout << "|                              Welcome to MyTest!                             "
          " |\n";
  cout << "+-----------------------------------------------------------------------------"
          "-+\n";

  testnum = 0;
  testerr = 0;

  runTests();

  cout << "\nMy Test (Errors/Tests: " << testerr << "/" << testnum << ")";

  cout << "\n\n#~~~~~~~~~~~~~~~~~~~~~~~~~~~" + comment(testerr) +
              "~~~~~~~~~~~~~~~~~~~~~~~~~~#\n\n";
}