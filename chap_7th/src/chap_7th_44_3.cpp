
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

  T* getPtr() const { return this->ptr; }
private:
  T *ptr;
};

template<>
class SmartPtr<Parent> {
public:
  SmartPtr(const SmartPtr<Child>& other) 
    : ptr(other.getPtr()) 
  {}

private:
  Parent *ptr;
};

int main(int, char**) {

  std::cout << "chap_7th_44_2.cpp" << std::endl;

  // ポインタでできるなら，スマートポインタでも同じことができるはず！
  SmartPtr<Child> sc = SmartPtr<Child>(new Child);

  // 暗黙的にコピーコンストラクタが呼ばれる．
  SmartPtr<Parent> sp = sc;

  return 0;
}