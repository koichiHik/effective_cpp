
#include <iostream>

class ShallowCopyContainer {
public:
  ShallowCopyContainer() 
    : arr(new int[ARR_LENGTH])
  {}

  ~ShallowCopyContainer()
  {
    delete[] arr;
  }

public:
  static const int ARR_LENGTH = 100;

private:
  int* arr;
};

int main(int, char**) {
  
  ShallowCopyContainer contA, contB;
  contB = contA;

  return 0;
}
