
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
  { std::cout << "explicit SmartPtr(T *realPtr)" << std::endl; }

  // Tというテンプレートパラメータが指定されているクラスで，
  // 別のテンプレートパラメータが指定された時の振る舞いを記述．
  template<typename U>
  SmartPtr(const SmartPtr<U> &other)
    : ptr(other.getPtr()) 
  { std::cout << "SmartPtr(const SmartPtr<U> &other)" << std::endl; }

  T* getPtr() const { return this->ptr; }
private:
  T *ptr;
};

int main(int, char**) {

  std::cout << "chap_7th_44_6.cpp" << std::endl;

  std::cout << "Explicit Copy Constructor Call" << std::endl;
  SmartPtr<Child> sc = SmartPtr<Child>(new Child);

  // 暗黙的にコピーコンストラクタが呼ばれる．
  std::cout << "Implicit Copy Constructor Call" << std::endl;
  SmartPtr<Child> sc2 = sc;

  // 暗黙的にコピーコンストラクタが呼ばれる．
  std::cout << "Implicit Copy Constructor Call" << std::endl;
  SmartPtr<Parent> sp = sc;

  return 0;
}