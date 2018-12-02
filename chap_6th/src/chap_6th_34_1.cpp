
#include <iostream>

class AbstractClassWithPure {
public:
  virtual ~AbstractClassWithPure() {};
  virtual void pure_virtual_func() = 0;
};

void AbstractClassWithPure::pure_virtual_func() {
  std::cout << "AbstractClassWithPure::pure_virtual_func()" <<std::endl;
}

class DerivedClassWithPure : public AbstractClassWithPure{
public:
  void pure_virtual_func();
};

void DerivedClassWithPure::pure_virtual_func() {
 std::cout << "DerivedClassWithPure::pure_virtual_func()" <<std::endl;
 AbstractClassWithPure::pure_virtual_func();
}

class ParentClassWithVirtual {
public:
  virtual ~ParentClassWithVirtual();
  virtual void virtual_func();
};

class ChildClassWithVirtual : public ParentClassWithVirtual {

};

int main() {
  std::cout << "Hello World." << std::endl;
  DerivedClassWithPure dc;
  dc.pure_virtual_func();
  return 0;
}