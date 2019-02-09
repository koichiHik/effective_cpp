
#include <iostream>
#include <memory>
#include <cstring>

class DeepCopyContainer {
public:
  DeepCopyContainer() 
    : arr(new int[ARR_LENGTH], std::default_delete<int[]>())
  {
    std::cout << "DeepCopyContainer()" << std::endl;
  }

  ~DeepCopyContainer()
  {
    std::cout << "~DeepCopyContainer()" << std::endl;
  }

  DeepCopyContainer(const DeepCopyContainer& obj)
    : arr(new int[ARR_LENGTH], std::default_delete<int[]>())
  {
    std::cout << "DeepCopyContainer(const DeepCopyContainer& obj)" << std::endl;
    std::memcpy(this->arr.get(), obj.arr.get(), ARR_LENGTH * sizeof(int));
  }

  DeepCopyContainer& operator=(const DeepCopyContainer& obj) {
    std::cout << "DeepCopyContainer& operator=(const DeepCopyContainer& obj)" << std::endl;    
    // 自己代入チェック．
    if (this != &obj) {
      std::memcpy(this->arr.get(), obj.arr.get(), ARR_LENGTH * sizeof(int));
    }

    // 自分を返す．
    return *this;
  }

public:
  static const int ARR_LENGTH = 100;

public:
  std::shared_ptr<int> arr;
};

int main(int, char**) {

  std::cout << __FILE__ << std::endl;

  // 生のポインタを持つ Container．
  DeepCopyContainer d1;

  for (int i = 0; i < DeepCopyContainer::ARR_LENGTH; i++) {
    d1.arr.get()[i] = 99;
  }

  for (int i = 0; i < DeepCopyContainer::ARR_LENGTH; i++) {
    std::cout << d1.arr.get()[i] << ", ";
  }
  std::cout << std::endl;

  // コピーコンストラクタの挙動チェック．
  DeepCopyContainer d3(d1);
  for (int i = 0; i < DeepCopyContainer::ARR_LENGTH; i++) {
    std::cout << d3.arr.get()[i] << ", ";
  }

  // コピー代入演算子の挙動チェック
  DeepCopyContainer d4;
  d4 = d1;
  for (int i = 0; i < DeepCopyContainer::ARR_LENGTH; i++) {
    std::cout << d4.arr.get()[i] << ", ";
  }

  return 0;
}
