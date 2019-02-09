
#include <iostream>

class Base {
public:

  class Internal {
  public:
    Internal() { std::cout << "Base::Internal" << std::endl; }
  };

  void methodA() { std::cout << "Base::methodA()" << std::endl; };
  void methodB(int a) { std::cout << "Base::methodB()" << std::endl; };
  void methodC() { std::cout << "Base::methodC()" << std::endl; };
};

class Inherited : public Base {
public:

  class Internal {
  public:
    Internal() { std::cout << "Inherited::Internal" << std::endl; }
  };

  void methodA() { std::cout << "Inherited::methodA()"  << std::endl; };
  void methodB() { std::cout << "Inherited::methodB()" << std::endl; };

public:
  int methodC;
};

int main(int, char**) {
  std::cout << "" << std::endl;

  Inherited obj;
  obj.methodA();
  //obj.methodB(0);  // 基底クラスで宣言されているmethodB(int)は隠蔽されるため，アクセス不可！
  obj.methodB();
  //obj.methodC();     // 基底クラスで宣言されているmethodC()は隠蔽されるため，アクセス不可！

  Inherited::Internal intl;  // 基底クラスで定義されている内部クラスがインスタンス化される．

  return 0;
}