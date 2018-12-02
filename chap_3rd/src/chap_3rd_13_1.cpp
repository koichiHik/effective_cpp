#include <iostream>
#include <memory>
#include <string>

class Resource {

public:
  Resource() { std::cout << "Resource()" << std::endl; }
  ~Resource() { std::cout << "~Resource()" << std::endl; }
  void say() { std::cout << "Resouce::say()" << std::endl; }
};

int main(int, char**) {

  std::cout << std::endl << std::endl;

  // スコープ内でauto_ptrを宣言．
  {
    std::auto_ptr<Resource> pRsrc1(new Resource());
    std::auto_ptr<Resource> pRsrc2;
    pRsrc1->say();
    
    // auto_ptrはポインタをシェアできないので，代入後はもとのauto_ptrがNULLを指す．
    pRsrc2 = pRsrc1;
    std::cout << pRsrc1.get() << std::endl;
    std::cout << pRsrc2.get() << std::endl;
    pRsrc1->say();
    pRsrc2->say();
  }

  std::cout << std::endl << std::endl;

  // auto_ptrはdeprecatedらしく，推奨はunique_ptrらしい．unique_ptrの場合，もはや代入演算子を使った代入ができない．
  {
    std::unique_ptr<Resource> pRsrc1(new Resource());
    std::unique_ptr<Resource> pRsrc2;
    pRsrc1->say();
    
    // unique_ptrはポインタをシェアできず，代入演算子の使用も不可．
    //pRsrc2 = pRsrc1;
    std::cout << pRsrc1.get() << std::endl;
    //std::cout << pRsrc2.get() << std::endl;
    pRsrc1->say();
    //pRsrc2->say();
  }

  std::cout << std::endl << std::endl;

  // スコープ内でshared_ptrを宣言．
  {
    std::shared_ptr<Resource> pRsrc1(new Resource());
    std::shared_ptr<Resource> pRsrc2;
    pRsrc1->say();
    
    // shared_ptrはポインタをシェアできるので，代入後も２つのshared_ptrが指すアドレスは同じ．
    pRsrc2 = pRsrc1;
    std::cout << pRsrc1 << std::endl;
    std::cout << pRsrc2 << std::endl;
    pRsrc1->say();
    pRsrc2->say();
  }

  std::cout << "End of program." << std::endl;
  return 0;
}
