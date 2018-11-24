
#include <iostream>

class HumanWoVirtual {
public:
  ~HumanWoVirtual() { std::cout << "~HumanWoVirtual()" << std::endl; };
  void say() { std::cout << "I am HumanWoVirtual!" << std::endl; };
};

class ManWoVirtual : public HumanWoVirtual {
public:
  ~ManWoVirtual() { std::cout << "~ManWoVirtual()" << std::endl; };
  void say() { std::cout << "I am ManWoVirtual!" << std::endl; };
};

class Human {
  public:
  virtual ~Human() { std::cout << "~Human()" << std::endl; };
  virtual void say() { std::cout << "I am Human!" << std::endl; };
};

class Man : public Human {
  public:
  virtual ~Man() { std::cout << "~Man()" << std::endl; };
  virtual void say() { std::cout << "I am Man!" << std::endl; };
};

int main(int, char const **)
{
  // ポインタとしてオブジェクトを扱う場合，振る舞いが異なる．
  // virtualとして関数が定義されている場合，ポインタが基底クラスの型になっていても，実体の関数が呼ばれる．
  {
    HumanWoVirtual *manWoVirtual = new ManWoVirtual;
    std::cout << std::endl;
    std::cout << "manWoVirtual->say()" << std::endl;
    manWoVirtual->say();
    delete manWoVirtual;
  }

  {
    Human *man = new Man();
    std::cout << std::endl;
    std::cout << "man->say()" << std::endl;
    man->say();
    delete man;
  }

  // 実体をアップキャストした場合コピーコンストラクタが呼ばれるため，実体は基底クラスとなる．
  // そのため，どちらのクラスでもsay()は基底クラスのものが呼ばれる．
  {
    Man man;
    std::cout << std::endl;
    std::cout << "man.say()" << std::endl;
    static_cast<Human>(man).say();
  }

  return 0;
}
