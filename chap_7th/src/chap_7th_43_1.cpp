
#include <iostream>

class ElementA {
public:
  void sayType() { std::cout << "ElementA" << std::endl; }

};

class ElementB {
public:

};

template<typename ElemType>
class BaseStorage {
public:
  void sayType() { 
    ElemType e;
    e.sayType();
  }
};

// テンプレート特化を使うと，sayTypeを持たないBaseStorageの定義が可能になる．
template<>
class BaseStorage<ElementB> {
};

/** これはNG
template<typename ElemType>
class InheritedStorageANG : public BaseStorage <ElemType> {
public:
  void clarifyType() { sayType(); }
};
**/

template<typename ElemType>
class InheritedStorageA1 : public BaseStorage <ElemType> {
public:
  void clarifyType() { this->sayType(); }
};

template<typename ElemType>
class InheritedStorageA2 : public BaseStorage <ElemType> {
public:
  using BaseStorage<ElemType>::sayType;
  void clarifyType() { sayType(); }
};

template<typename ElemType>
class InheritedStorageA3 : public BaseStorage <ElemType> {
public:
  void clarifyType() { BaseStorage<ElemType>::sayType(); }
};

int main(int, char**) {

  std::cout << "chap_7th_43_1.cpp" <<  std::endl;
  /**  これはNG！
  InheritedStorageANG<ElementA> storageANG;
  storageANG.clarifyType();
  **/

  InheritedStorageA1<ElementA> storageA1;
  storageA1.clarifyType();

  InheritedStorageA2<ElementA> storageA2;
  storageA2.clarifyType();

  InheritedStorageA3<ElementA> storageA3;
  storageA3.clarifyType();

  /** これはNG!
  InheritedStorageA3<ElementB> storageA3_B;
  storageA3_B.clarifyType();
  **/

  return 0;
}