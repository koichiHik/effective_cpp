
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <time.h>


// Forward Declaration
template <typename T>
class ContainerImpl;

template <typename T>
class Container {
public:
  Container() 
    : pImpl(new ContainerImpl<T>())
  {}

  Container(const Container& obj)
    : pImpl(new ContainerImpl<T>(*obj.pImpl))
  {}

  Container& operator=(const Container& rhs) {
    *pImpl = *(rhs.pImpl);
    return *this;
  }

private:
  std::shared_ptr<ContainerImpl<T> > pImpl;
};

template <typename T>
class ContainerImpl {
public:
  ContainerImpl() 
    : vec(1000000000)
  {}

  ContainerImpl(const ContainerImpl& obj)
    : vec(obj.vec)
  {}

private:
  std::vector<T> vec;
};


int main(int, char**) {

  Container<int> contIntA, contIntB;

  clock_t c1, c2;
  c1 = clock();

  {
    for (int i = 0; i < 5; i++) {
      using std::swap;
      swap(contIntA, contIntB);
    }
  }

  c2 = clock();
  std::cout << std::fixed << (double)(c2 - c1) / CLOCKS_PER_SEC << std::endl;

  return 0;
}