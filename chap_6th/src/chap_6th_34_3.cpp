
#include <iostream>

class ConcreteParentClass {
public:
  virtual ~ConcreteParentClass() {}
  void concrete_method();
};

void ConcreteParentClass::concrete_method() {
  std::cout << "ConcreteParentClass::concrete_method()" << std::endl;
}

class ConcreteChildClass : public ConcreteParentClass {
public:
  void concrete_method();
};

void ConcreteChildClass::concrete_method() {
  std::cout << "ConcreteChildClass::concrete_method()" << std::endl;
}

int main() {
  ConcreteChildClass cc;
  cc.concrete_method();
  return 0;
}