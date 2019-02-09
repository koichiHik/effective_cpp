#include <iostream>
#include <vector>

class SampleVector {
public:
  SampleVector()
  {
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
  }

  ~SampleVector()
  {}

  int& operator[](int pos) {
    std::cout << "Non const version of operator[]" << std::endl;
    return vec[pos];
  }

  const int& operator[](int pos) const {
    std::cout << "Const version of operator[]" << std::endl;
    return vec[pos];
  }

  void printAllElems() const {
    for (unsigned int i = 0; i < vec.size(); i++) {
      std::cout << vec[i] << std::endl;
    }
  }

private:
  std::vector<int> vec;
};

void printSampleVector(const SampleVector& samVec) {
  std::cout << samVec[1] << std::endl;
}

void modifySampleVector(SampleVector& samVec) {
  samVec[1] = 100;
}

int main(int, char**) {

  std::cout << "Effective C++ 3項" << std::endl;

  SampleVector samVec;

  std::cout << "Calling printSampleVector(const SampleVector&)" << std::endl;
  printSampleVector(samVec);

  std::cout << "Calling modifySampleVector(SampleVector&)" << std::endl;
  modifySampleVector(samVec);

  std::cout << "Calling SampleVector::pringAllElems" << std::endl;
  samVec.printAllElems();

  return 0;
}
