
#include <iostream>

class Parent {
public:
  void pub_method() { std::cout << "Parent::pub_method()" << std::endl; }
};

class PrivateChild {
public:
  void test() { m_parent.pub_method(); }

private:
  Parent m_parent;
};

int main(int, char **) {

  // Private Inheritance.
  PrivateChild prc;
  prc.test();

  return 0;
}