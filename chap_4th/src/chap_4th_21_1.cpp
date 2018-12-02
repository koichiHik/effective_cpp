
#include <iostream>
#include <string>

class Hoge {
public:
  Hoge(std::string name) : m_name(name) { std::cout << "Hoge()" << std::endl; }
  ~Hoge() { std::cout << "~Hoge()" << std::endl; }
  Hoge(const Hoge &rhs) : m_name(rhs.m_name) { std::cout << "Hoge(const Hoge &rhs)" << std::endl; }
  Hoge& operator=(const Hoge &rhs) { 
    std::cout << "Hoge& operator=(const Hoge &rhs)" << std::endl;
    if (this == &rhs) {
      return *this;
    }
    this->m_name = rhs.m_name;
    return *this; 
  }

  void sayName() { std::cout << m_name << std::endl; };

private:
 std::string m_name;
};


Hoge& localRefReturn() {
  Hoge tmp("StackHoge");
  return tmp;
}

int main(int, char**) {

  Hoge hoge = localRefReturn();

  hoge.sayName();

  return 0;
}