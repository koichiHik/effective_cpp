
#include <iostream>
#include <string>
#include <vector>


class UnCopyableClass {
public:

  // コンストラクタは必要なので，宣言＆定義を書く．
  UnCopyableClass() {};

  // デストラクタは必要なので，宣言＆定義を書く．
  ~UnCopyableClass() {};

private:
  // コピーコンストラクタは使わせないようにしたいので，宣言だけにして，praivteスコープとする．
  UnCopyableClass(const UnCopyableClass& obj);

  // 代入演算子は使わせないようにしたいので，宣言だけにして，praivteスコープとする．
  UnCopyableClass& operator=(const UnCopyableClass &obj);
};

int main(int, char**)
{
  UnCopyableClass objA, objB;

  // コンパイルエラー！　コピーコンストラクタのコールはダメ！
  //UnCopyableClass objC(objA);

  // コンパイルエラー！　コピー代入演算子のコールはダメ！
  //objA = objB;

  return 0;
}
