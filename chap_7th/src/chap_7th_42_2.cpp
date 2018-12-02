
#include <iostream>

class TypeClass {
public:
  enum value_type { val1 = 100, val2 };
  static const int value_type = 0;
};

template<typename T>
class TemlatedClass {
public:
  void print() {
    //T::value_type *val1;
    typename T::value_type val1 = T::value_type::val1;
    int val2 = T::value_type;
    std::cout << val1 << std::endl;
    std::cout << val2 << std::endl;
  }
};

int main(int, char**) {

  std::cout << "chap_7th_42_1.cpp" <<  std::endl;

  TemlatedClass<TypeClass> tc;
  tc.print();

  return 0;
}