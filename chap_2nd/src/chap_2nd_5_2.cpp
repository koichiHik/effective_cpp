
#include <iostream>

class ParentA {
public:
  virtual ~ParentA();
};

ParentA::~ParentA() {
  std::cout << "ParentA Destructor!" << std::endl;
}

class ChildA : public ParentA {
public:
};

class ChildChildA : public ChildA {
public:
  ~ChildChildA();
};

ChildChildA::~ChildChildA() {
  std::cout << "ChildChildA Destructor!" << std::endl;  
}

class ParentB {
public:
  ~ParentB();
};

ParentB::~ParentB() {
  std::cout << "ParentB Destructor!" << std::endl;
}

class ChildB : public ParentB {
public:
};

class ChildChildB : public ChildB {
public:
  ~ChildChildB();
};

ChildChildB::~ChildChildB() {
  std::cout << "ChildChildB Destructor!" << std::endl;  
}

int main(int, char**) {
  std::cout << "2nd Chapter 5" << std::endl;
  ChildA *A = new ChildChildA();
  delete A;

  ChildB *B = new ChildChildB();
  delete B;

}
