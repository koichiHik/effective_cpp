
#include <iostream>
#include <string>
#include <vector>

class Uncopyable {
public:
  Uncopyable() {}
  ~Uncopyable() {}
private:
  Uncopyable(const Uncopyable& obj);
  Uncopyable& operator=(const Uncopyable& obj);
};

class ChildUncopyable : private Uncopyable {
public:
};

int main(int, char**)
{
  
  ChildUncopyable objA, objB;

  // コンパイルエラー！　コピーコンストラクタのコールはダメ！
  // ChildUncopyable objC(objA);

  // コンパイルエラー！　コピー代入演算子のコールはダメ！
  // objA = objB;

  return 0;
}
