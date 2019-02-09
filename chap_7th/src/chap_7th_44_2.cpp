
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

template <typename T>
class SmartPtr {
public:
  explicit SmartPtr(T *realPtr) 
    : ptr(realPtr)
  {}

private:
  T *ptr;
};

int main(int, char**) {

  std::cout << "chap_7th_44_2.cpp" << std::endl;

  // ポインタでできるなら，スマートポインタでも同じことができるはず！
  //SmartPtr<Child> sc = SmartPtr<Child>(new Child);
  //SmartPtr<Parent> sp = sc;

  return 0;
}