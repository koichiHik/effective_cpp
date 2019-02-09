
#include <iostream>

class ShallowCopyContainer {
public:
  ShallowCopyContainer() 
    : arr(new int[ARR_LENGTH])
  {}

  ~ShallowCopyContainer()
  {
    if (arr != nullptr) {
      delete[] arr;
      arr = nullptr;
    }
  }

  ShallowCopyContainer& operator=(const ShallowCopyContainer& rhs) {

    // 自分だった場合は，そのまま自分を返す．
    if (this == &rhs) {
      return *this;
    }

    // もともと自分が持っていた領域を delete[] してリークを防ぐ．
    delete[] this->arr;
    this->arr = rhs.arr;
    return *this;
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
