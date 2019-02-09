
#include <iostream>
#include <memory>
#include <cstring>
#include <vector>

class MyContainer {
public:

  MyContainer() 
    : a(0), b(0)
  {
    std::cout << "MyContainer()" << std::endl;
  }

  ~MyContainer()
  {
    std::cout << "~MyContainer()" << std::endl;
  }

  MyContainer(const MyContainer& obj) 
    : a(obj.a), b(obj.b)
  {
    std::cout << "MyContainer(const MyContainer& obj)" << std::endl;    
  }

  MyContainer& operator=(const MyContainer& obj) {
    std::cout << "MyContainer& operator=(const MyContainer& obj)" << std::endl;
    if (this != &obj) {
      this->a = obj.a;
      this->b = obj.b;
    }
    return *this;
  }

  int a, b;
};

int main(int, char**) {

  std::cout << __FILE__ << std::endl;

  MyContainer cont1;

  std::cout << std::endl;
  std::cout << "Start of vector scope1." << std::endl;
  {
    std::vector<MyContainer> vec;
    vec.push_back(cont1);
  }
  std::cout << "End of vector scope1." << std::endl;
  std::cout << std::endl;

  MyContainer cont2;
  cont2.a = 100;
  cont2.b = 1000;
  std::cout << std::endl;
  std::cout << "Start of vector scope2" << std::endl;
  {
    std::vector<MyContainer> vec;
    vec.push_back(cont1);
    vec[0] = cont2;
  }
  std::cout << "End of vector scope2" << std::endl;
  std::cout << std::endl;

  return 0;
}
