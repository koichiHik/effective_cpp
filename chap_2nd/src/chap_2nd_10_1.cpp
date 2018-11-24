
#include <iostream>

class ParentContainer {
public:
  virtual ~ParentContainer() {};

  enum {ARR_NUM = 3};
};

class ContainerDymanic : public ParentContainer{
public:
  ContainerDymanic() {
    arr = new int[ARR_NUM];
  }

  void print() {
    std::cout << "" << std::endl;
    for (int i = 0; i < ARR_NUM; i++) {
      std::cout << "cont[" << i << "]" << this->arr[i] << std::endl;
    }
  }

  void modifyArr(int val) {
    for (int i = 0; i < ARR_NUM; i++) {
      this->arr[i] = val;
    }
  }

  int *arr;
};

class ContainerStatic : public ParentContainer {
public:

  void print() {
    std::cout << "" << std::endl;
    for (int i = 0; i < ARR_NUM; i++) {
      std::cout << "cont[" << i << "]" << this->arr[i] << std::endl;
    }
  }

  void modifyArr(int val) {
    for (int i = 0; i < ARR_NUM; i++) {
      this->arr[i] = val;
    }
  }

  int arr[ARR_NUM];
};

int main(int, char**) {

  {
    ContainerStatic stContA, stContB;
    std::cout << "Default = operator for class without pointer member." << std::endl;
    stContA.modifyArr(100); 
    stContB = stContA;
    stContA.print();
    stContB.print();

    stContB.modifyArr(500);
    stContA.print();
    stContB.print();
  }

  {
    ContainerDymanic dynContA, dynContB; 
    std::cout << "" << std::endl;
    std::cout << "Default = operator for class with pointer member." << std::endl;
    dynContA.modifyArr(100);
    dynContB = dynContA;
    dynContA.print();
    dynContB.print();
    
    dynContB.modifyArr(500);
    dynContA.print();
    dynContB.print();
  }

    {
    ContainerStatic stContA;
    std::cout << "Default copy operator for class without pointer member." << std::endl;
    stContA.modifyArr(100); 
    ContainerStatic stContB(stContA);
    stContA.print();
    stContB.print();

    stContB.modifyArr(500);
    stContA.print();
    stContB.print();
  }

  {
    ContainerDymanic dynContA; 
    std::cout << "" << std::endl;
    std::cout << "Default copy operator for class with pointer member." << std::endl;
    dynContA.modifyArr(100);
    ContainerDymanic dynContB(dynContA);
    dynContA.print();
    dynContB.print();
    
    dynContB.modifyArr(500);
    dynContA.print();
    dynContB.print();
  }

  return 0;
}
