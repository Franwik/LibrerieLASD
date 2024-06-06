#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>
using namespace std;

/* ************************************************************************** */

int main(int argc, char *argv[]) {

  int choose, exit = 0;

  cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ WELCOME "
          "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"
       << endl;

  do {

    cout << "Select test to run:" << endl;
    cout << "[0] close" << endl;
    cout << "[1] lasdtest" << endl;
    cout << "[2] mytest" << endl;
    cout << "[...] all" << endl;

    if (argc == 2 && exit == 0) {
      choose = atoi(argv[1]);
    } else if (argc == 2 && exit == 1) {
      choose = 0;
    } else {
      cin >> choose;
    }

    switch (choose) {
    case 1:
      lasdtest();
      exit++;
      break;
    case 2:
      mytest::mytest();
      exit++;
      break;
    case 0:
      cout << "closing..." << endl;
      break;
    default:
      lasdtest();
      mytest::mytest();
      exit++;
      break;
    }
  } while (choose != 0);

  return 0;
}
