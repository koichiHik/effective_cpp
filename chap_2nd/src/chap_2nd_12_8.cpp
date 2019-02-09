
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
  DeepCopyContainer d1;

  // デフォルトのコピーコンストラクタを使ってしまうと，最後に二重解放．
  DeepCopyContainer d2(d1);

  return 0;
}
