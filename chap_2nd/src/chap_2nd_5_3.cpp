
#include <iostream>
#include <string>
#include <vector>

class A {
public:
  int a;
  float b;
  std::string name;
  std::vector<int> vec;
};

int main(int, char**)
{

  std::cout << "Copy Constructor Example" << std::endl;
  {
    A a;
    a.a = 10;
    a.b = 10.0f;
    a.name = "sample";
    a.vec.push_back(0);
    a.vec.push_back(1);
    a.vec.push_back(2);

    A aa(a);
    aa.vec.push_back(5);

    std::cout << "a.a : " << a.a << std::endl;
    std::cout << "a.b : " << a.b << std::endl;
    std::cout << "a.name : " << a.name << std::endl;

    for (std::size_t i = 0; i < a.vec.size(); i++) {
      std::cout << "elem : " << a.vec[i] << std::endl;
    }          
    std::cout << std::endl;


    std::cout << "aa.a : " << aa.a << std::endl;
    std::cout << "aa.b : " << aa.b << std::endl;
    std::cout << "aa.name : " << aa.name << std::endl;

    for (std::size_t i = 0; i < aa.vec.size(); i++) {
      std::cout << "elem : " << aa.vec[i] << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << "Operator \"=\" Example" << std::endl;
  {
    A a;
    a.a = 10;
    a.b = 10.0f;
    a.name = "sample";
    a.vec.push_back(0);
    a.vec.push_back(1);
    a.vec.push_back(2);

    A aa;
    aa = a;
    aa.vec.push_back(5);

    std::cout << "a.a : " << a.a << std::endl;
    std::cout << "a.b : " << a.b << std::endl;
    std::cout << "a.name : " << a.name << std::endl;

    for (std::size_t i = 0; i < a.vec.size(); i++) {
      std::cout << "elem : " << a.vec[i] << std::endl;
    }          
    std::cout << std::endl;


    std::cout << "aa.a : " << aa.a << std::endl;
    std::cout << "aa.b : " << aa.b << std::endl;
    std::cout << "aa.name : " << aa.name << std::endl;

    for (std::size_t i = 0; i < aa.vec.size(); i++) {
      std::cout << "elem : " << aa.vec[i] << std::endl;
    }
  }  

  return 0;
}
