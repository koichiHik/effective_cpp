
#include <iostream>

class IntNumber {
public:
  IntNumber(int val) 
    : num(val) {
    std::cout << "IntNumber(int val)" << std::endl;
  }

  ~IntNumber() {
    std::cout << "~IntNumber" << std::endl;
  }

  IntNumber(const IntNumber& obj) 
    : num(obj.num) {
    std::cout << "IntNumber(const IntNumber& obj)" << std::endl;
  }

  IntNumber& operator=(const IntNumber& val) {
    std::cout << "IntNumber& operator=(const IntNumber& val)" << std::endl;
    if (this != &val) {
      this->num = val.num;
    }
    return *this;
  }

private:
  int num;
};

int main(int, char**) {

  // １．直接的なコンストラクタのコール
  std::cout << "1. Explicit Constructor Call" << std::endl;
  IntNumber num1(1);
  std::cout << std::endl;

  // 2．暗黙的なコンストラクタのコール
  std::cout << "2. Implicit Constructor Call" << std::endl;
  IntNumber num2 = 2;
  std::cout << std::endl;

  // ３．明示的なコピーコンストラクタのコール
  std::cout << "3. Explicit Copy Constructor Call" << std::endl;
  IntNumber num3(num1);
  std::cout << std::endl;

  // ４．暗黙的なコピーコンストラクタのコール
  std::cout << "4. Implicit Copy Constructor Call" << std::endl;
  IntNumber num4 = num1;
  std::cout << std::endl;

  // ５．明示的なコピー代入演算子のコール
  std::cout << "5. Explicit operator= Call" << std::endl;
  num1.operator=(num2.operator=(num3.operator=(num4)));
  std::cout << std::endl;

  // ６．コピー代入演算子のコール
  std::cout << "6. Implicit operator= Call" << std::endl;
  num1 = num2 = num3 = num4;
  std::cout << std::endl;

  return 0;
}
