
#include <iostream>
#include <memory>

class DeepCopyContainer {
public:
  DeepCopyContainer() 
    : arr(new int[ARR_LENGTH])
  {}

  ~DeepCopyContainer()
  {
    delete[] this->arr;
  }

public:
  static const int ARR_LENGTH = 100;

public:
  int* arr;
};

int main(int, char**) {

  std::cout << "chap_2nd_12_5" << std::endl;

  // 生のポインタを持つ Container．
  DeepCopyContainer d1, d2;

  // デフォルトのコピー代入演算子を使ってしまうと，メモリリーク．．．
  d1 = d2;

  return 0;
}
