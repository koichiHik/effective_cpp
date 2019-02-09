
#include <iostream>

class Object {
public:
  static void* operator new(std::size_t size) noexcept(false);
  static void* operator new(std::size_t size, void* pnt) noexcept(false);
  static void* operator new(std::size_t size, const std::nothrow_t &nothrow) noexcept(true);
  static void* operator new(std::size_t size, std::ostream &stream) noexcept(false);
};

void* Object::operator new(std::size_t size) noexcept(false) {
  return ::operator new(size);
}

void* Object::operator new(std::size_t size, void* pnt) noexcept(false) {
  return ::operator new(size, pnt);
}

void* Object::operator new(std::size_t size, const std::nothrow_t &nothrow) noexcept(true)  {
  return ::operator new(size, nothrow);
}

void* Object::operator new(std::size_t size, std::ostream &stream) noexcept(false) {
  stream << "operator new" << std::endl;
  return ::operator new(size);
}

class ObjectChild : public Object{
public:
  // 基底クラスの new 関数も探索対象に入れる．
  using Object::operator new;
  static void* operator new(std::size_t size, std::ostream &stream) noexcept(false);
};

void* ObjectChild::operator new(std::size_t size, std::ostream &stream) noexcept(false) {
  return ::operator new(size);
}

int main(int, char**) {

  std::cout << "Hello World!" << std::endl;
  
  // デフォルトの new operator も定義した．
  Object* obj1 = new Object;
  delete obj1;
  
  // ostream を引数として取る new operator
  Object* obj2 = new(std::cout) Object;
  delete obj2;

  // 派生クラスの new operator も定義した．
  ObjectChild* objc1 = new ObjectChild;
  delete objc1;

  // 派生クラスで独自定義した new 演算子．
  ObjectChild* objc2 = new(std::cout) ObjectChild;
  delete objc2;

  return 0;
}