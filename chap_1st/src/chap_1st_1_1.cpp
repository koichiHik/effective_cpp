#include <iostream>

#define DEFINE_NUM 10

#define MAX(a, b) ((a) > (b) ? (a) : (b))

template<typename T>
inline double max(const T &a, const T &b) {
  return ((a) > (b) ? (a) : (b));
}

class Sample {
private:

  enum {ENUM_NUM=10};
//  enum {DEFINE_NUM=20};

  // Can assigne value in declaration.
  static const bool BOOL_NUM=true;
  static const int INT_NUM=5;
  static const unsigned char CHAR_NUM=2;

  // Can not assign value in declaration.
  static const float FLOAT_NUM;
  static const double DOUBLE_CONST;
  int arr[INT_NUM];
  int arr2[ENUM_NUM];
  int arr3[DEFINE_NUM];
};

const double Sample::DOUBLE_CONST=2.0;
const float Sample::FLOAT_NUM=3.0;

int main(int, char**) {
  std::cout << "Effective CPP #2" << std::endl;

  int a = 3.0;
  int b = 3.0;
  
  std::cout << "Before Calling : " << a << std::endl;
  std::cout << MAX(++a, b) << std::endl;
  std::cout << "After Calling  : " << a << std::endl;
  std::cout << std::endl;

  int x = 3.0;
  int y = 3.0;
  
  std::cout << "Before Calling : " << x << std::endl;
  std::cout << max(++x, y) << std::endl;
  std::cout << "After Calling  : " << x << std::endl;

  return 0;
}
