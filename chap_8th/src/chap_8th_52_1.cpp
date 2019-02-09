
#include <iostream>

class Object {
public:
  static void* operator new(std::size_t size, std::ostream &stream) noexcept(false);

};

void* Object::operator new(std::size_t size, std::ostream &stream) noexcept(false) {
  stream << "operator new" << std::endl;
  return ::operator new(size);
}

int main(int, char**) {

  std::cout << "Hello World!" << std::endl;
  
  // デフォルトの new operator は隠蔽される．
  // Object* obj = new Object;
  
  // ostream を引数として取る new operator
  Object* obj = new(std::cout) Object;

  return 0;
}