
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
  SmartPtr() 
  {}

  explicit SmartPtr(T *realPtr) 
    : ptr(realPtr)
  {}

  // Tというテンプレートパラメータが指定されているクラスで，
  // 別のテンプレートパラメータが指定された時の振る舞いを記述．
  template<typename U>
  SmartPtr(const SmartPtr<U> &other)
    : ptr(other.getPtr()) 
  { std::cout << "SmartPtr(const SmartPtr<U> &other)" << std::endl; }

  template<typename U>
  SmartPtr& operator=(SmartPtr<U> &rhs)
  { 
    std::cout << "SmartPtr& operator=(SmartPtr<U> &rhs)" << std::endl;
    this->ptr = rhs.getPtr();
    return *this;
  }

  T* getPtr() const { return this->ptr; }
private:
  T *ptr;
};

int main(int, char**) {

  std::cout << "chap_7th_44_5.cpp" << std::endl;

  // ポインタでできるなら，スマートポインタでも同じことができるはず！
  SmartPtr<Child> sc = SmartPtr<Child>(new Child);

  // 暗黙的にコピーコンストラクタが呼ばれる．
  SmartPtr<Parent> sp = SmartPtr<Parent>(new Parent);
  sp = sc;

  std::cout << sp.getPtr() << std::endl;
  std::cout << sc.getPtr() << std::endl;

  return 0;
}