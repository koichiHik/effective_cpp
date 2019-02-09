
#include <iostream>

class Parent 
{
public:
  virtual ~Parent() {}
  virtual void say() { std::cout << "Parent" << std::endl; }
};

class Child : public Parent 
{
public:
  virtual void say() {std::cout << "Child" << std::endl; }  
};

int main(int, char**) {

  std::cout << "chap_7th_44_1.cpp" << std::endl;

  // ポインタの暗黙の型変換．
  Child *c = new Child;
  Parent *p = c;
  p->say();

  return 0;
}