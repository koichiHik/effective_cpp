#include <iostream>

int main(int, char**) {

  std::cout << "Effective C++ 3項" << std::endl;

  // 1. データが const
  // 変数に対するconst宣言
  const double a = 0;

  // error: assignment of read-only variable ‘a’
  // a = 1;

  // 2. ポインタが非 const, データが const
  const int *b = 0;

  // データの更新は許されない．
  // error : assignment of read-only location ‘* b’
  //*b = 10;

  // ポインタの更新は許される．
  // This is possible.
  b = nullptr;

  // 3. ポインタが const，データが 非const
  int * const c = nullptr;
  int d = 0;

  // データの更新は許される．
  *c = 100;

  // ポインタの更新は許されない．
  // error : assignment of read-only variable ‘c’
  // c = &d;

  // 4. ポインタ，データともに const
  int const * const e = 0;
  // error : assignment of read-only location ‘*(const int*)e’
  //*e = 10;

  // error: assignment of read-only variable ‘e’
  // e = nullptr;

  return 0;
}
