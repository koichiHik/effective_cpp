
#include <iostream>

class Empty {
};

int main(int, char**) {
  Empty emp;
  std::cout << sizeof(emp) << std::endl;
  return 0;
}