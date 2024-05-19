#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>
using namespace std;

/* ************************************************************************** */

int main() {

  int choose;

  cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ WELCOME "
          "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"
       << endl;

  do {

    cout << "Select test to run:" << endl;
    cout << "[0] close" << endl;
    cout << "[1] lasdtest" << endl;
    cout << "[2] mytest" << endl;
    cout << "[...] all" << endl;
    cin >> choose;

    switch (choose) {
    case 1:
      lasdtest();
      break;
    case 2:
      mytest::mytest();
      break;
    case 0:
      cout << "closing..." << endl;
      break;
    default:
      lasdtest();
      mytest::mytest();
      break;
    }
  } while (choose != 0);

  return 0;
}
