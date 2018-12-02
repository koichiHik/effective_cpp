
#include <iostream>

class Empty {};

class IntClassComposition {
  int8_t intNum;
  Empty empty;
};

class IntClassPrivateInheritance : private Empty {
  int8_t intNum;
};

class IntClassPublicInheritance : private Empty {
  int8_t intNum;
};

int main(int, char**) {

  IntClassComposition intClassComposition;
  std::cout << sizeof(intClassComposition) << std::endl;

  IntClassPrivateInheritance intClassPrivateInheritance;
  std::cout << sizeof(intClassPrivateInheritance) << std::endl;

  IntClassPublicInheritance intClassPublicInheritance;
  std::cout << sizeof(intClassPublicInheritance) << std::endl;

  return 0;
}