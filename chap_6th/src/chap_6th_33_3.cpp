
#include <iostream>

class Base {
public:
  void methodA() { std::cout << "Base::methodA()" << std::endl; };
  void methodB(int a) { std::cout << "Base::methodB()" << std::endl; };
};

class Inherited : public Base {
public:
  void methodA() { std::cout << "Inherited::methodA()"  << std::endl; };
  void methodB() { std::cout << "Inherited::methodB()" << std::endl; };
  void BaseMethodA() { Base::methodA(); };
  void BaseMethodB(int a) {Base::methodB(a); };

public:
};

int main(int, char**) {
  std::cout << "" << std::endl;

  Inherited obj;
  obj.methodA();
  obj.BaseMethodA();
  obj.methodB();
  obj.BaseMethodB(1);

  return 0;
}