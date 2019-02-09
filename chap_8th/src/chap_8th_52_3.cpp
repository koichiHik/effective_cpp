
#include <iostream>

class Object {
public:
  static void* operator new(std::size_t size) noexcept(false);
  static void* operator new(std::size_t size, void* pnt) noexcept(false);
  static void* operator new(std::size_t size, const std::nothrow_t &nothrow) noexcept(true);

  static void operator delete(void* pnt) noexcept(false);
  static void operator delete(void* pnt1, void* pnt2);
  static void operator delete(void* pnt, const std::nothrow_t &nothrow) noexcept(true);

  static void* operator new(std::size_t size, std::ostream &stream) noexcept(false);
  static void operator delete(void* pnt, std::ostream &stream) noexcept(false);
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
  stream << "placement new" << std::endl;
  return ::operator new(size);
}

void Object::operator delete(void* pnt) noexcept(false) {
  ::operator delete(pnt);
}

void Object::operator delete(void* pnt1, void* pnt2) noexcept(false) {
  ::operator delete(pnt1, pnt2);
}

void Object::operator delete(void* pnt1, const std::nothrow_t &nothrow) noexcept(true) {
  ::operator delete(pnt1, nothrow);
}

void Object::operator delete(void* pnt, std::ostream &stream) noexcept(false) {
  stream << "placement delete" << std::endl;
  ::operator delete(pnt);
}

class ObjectChild : public Object{
public:
  // 基底クラスの new 関数も探索対象に入れる．
  ObjectChild() {
    throw std::exception();
  }
  using Object::operator new;
  using Object::operator delete;
  static void* operator new(std::size_t size, std::ostream &stream) noexcept(false);
};

void* ObjectChild::operator new(std::size_t size, std::ostream &stream) noexcept(false) {
  return ::operator new(size);
}

int main(int, char**) {

  std::cout << "Hello World!" << std::endl;
  
  ObjectChild *obj2;
  try {
    // ostream を引数として取る new operator
    obj2 = new(std::cout) ObjectChild;
    delete obj2;
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}