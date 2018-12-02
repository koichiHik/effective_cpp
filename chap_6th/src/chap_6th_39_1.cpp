
#include <iostream>

class Parent {
public:
  void pub_method() { std::cout << "Parent::pub_method()" << std::endl; }
};

class PrivateChild : private Parent {
public:
  void test() { pub_method(); }

};

class PublicChild : public Parent {
public:
  void test() { pub_method(); }
};

int main(int, char **) {

  // Private Inheritance.
  PrivateChild prc;
  //prc.pub_method();  <- Private継承のため，基底クラスのメソッドに対するアクセス不可！
  prc.test();

  // Public Inheritance.
  PublicChild pubc;
  pubc.pub_method();
  pubc.test();

  return 0;
}