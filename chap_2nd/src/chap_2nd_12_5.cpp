
#include <iostream>
#include <memory>

class ShallowCopyContainer {
public:
  ShallowCopyContainer() 
    : arr(new int[ARR_LENGTH], std::default_delete<int[]>())
  {}

  ~ShallowCopyContainer()
  {}

public:
  static const int ARR_LENGTH = 100;

public:
  std::shared_ptr<int> arr;
};

int main(int, char**) {
  
  {
    ShallowCopyContainer contA;
    ShallowCopyContainer contB(contA);

    for (int i = 0; i < ShallowCopyContainer::ARR_LENGTH; i++) {
      contA.arr.get()[i] = 99;
    }

    for (int j = 0; j < ShallowCopyContainer::ARR_LENGTH; j++) {
      std::cout << "coutA.arr[" << j << "] : " << contA.arr.get()[j] << std::endl;
      std::cout << "coutB.arr[" << j << "] : " << contB.arr.get()[j] << std::endl;
    }
  }

  {
    ShallowCopyContainer contA, contB;
    contB = contA;

    for (int i = 0; i < ShallowCopyContainer::ARR_LENGTH; i++) {
      contA.arr.get()[i] = 101;
    }

    for (int j = 0; j < ShallowCopyContainer::ARR_LENGTH; j++) {
      std::cout << "coutA.arr[" << j << "] : " << contA.arr.get()[j] << std::endl;
      std::cout << "coutB.arr[" << j << "] : " << contB.arr.get()[j] << std::endl;
    }
  }

  return 0;
}
