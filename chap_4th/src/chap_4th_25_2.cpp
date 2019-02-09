
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <time.h>


// Forward Declaration
class ContainerImpl;

class Container {
public:
  explicit Container();

private:
  //std::shared_ptr<ContainerImpl<T> > pImpl;
  ContainerImpl *pImpl;
};

class ContainerImpl {
public:
  ContainerImpl() 
    : vec(1000000000)
  {}

private:
  std::vector<int> vec;
};

// クラス定義
Container::Container() : pImpl(nullptr) {
  pImpl = new ContainerImpl();
}



int main(int, char**) {

  //Container<int> contIntA, contIntB;
  Container contIntA, contIntB;

  clock_t c1, c2;
  c1 = clock();

  {
    for (int i = 0; i < 100; i++) {
      using std::swap;
      swap(contIntA, contIntB);
    }
  }

  c2 = clock();
  std::cout << std::fixed << (double)(c2 - c1) / CLOCKS_PER_SEC << std::endl;

  return 0;
}