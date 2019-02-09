
#include <iostream>

class ElementA {
public:
  void sayType() { std::cout << "ElementA" << std::endl; }

};

template<typename ElemType>
class BaseStorage {
public:
  void sayType() { 
    ElemType e;
    e.sayType();
  }
};

class InheritedStorageA : public BaseStorage <ElementA> {
public:
  void clarifyType() { sayType(); }
};

int main(int, char**) {

  std::cout << "chap_7th_43_2.cpp" <<  std::endl;
  InheritedStorageA storageA;
  storageA.clarifyType();

  return 0;
}