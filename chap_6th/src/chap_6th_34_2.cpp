
#include <iostream>

class ParentClassWithVirtual {
public:
  virtual ~ParentClassWithVirtual() {};
  virtual void virtual_func();
};

void ParentClassWithVirtual::virtual_func() {
  std::cout << "ParentClassWithVirtual::virtual_func()" << std::endl;
}

class ChildClassWithVirtual : public ParentClassWithVirtual {
public:
  virtual void virtual_func();
};

void ChildClassWithVirtual::virtual_func() {
  std::cout << "ChildClassWithVirtual::virtual_func()" << std::endl;
}

int main() {
  ChildClassWithVirtual cc;
  cc.virtual_func();
  return 0;
}