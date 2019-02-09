#include <iostream>
#include <vector>

class ConstSample {
public:
  ConstSample() 
    : m_x(0), vec()
  {
    m_y = new int[10];
  }

  ~ConstSample()
  {
    delete[] m_y;
  }

  void constFunction() const;

  void nonConstFunction();

  void someFunction();

  const int& getVal() const;

private:
  int m_x;
  int *m_y;
  std::vector<int> vec;
};

void ConstSample::constFunction() const {
  // error: assignment of member ‘ConstSample::m_x’ in read-only object
  // m_x = 10;

  // error: passing ‘const std::vector<int>’ as ‘this’ argument discards qualifiers [-fpermissive]
  // vec.clear();

  // error: passing ‘const std::vector<int>’ as ‘this’ argument discards qualifiers [-fpermissive]
  // vec.push_back(10);

  m_y[2] = 10;

  // error: passing ‘const ConstSample’ as ‘this’ argument discards qualifiers [-fpermissive]
  // someFunction();
}

void ConstSample::nonConstFunction() {
  m_x = 10;

  vec.clear();

  vec.push_back(10);

  m_y[2] = 10;
}

void ConstSample::someFunction() {

}

const int& ConstSample::getVal() const {
  return m_x;
}

int main(int, char**) {

  std::cout << "Effective C++ 3項" << std::endl;

  return 0;
}
