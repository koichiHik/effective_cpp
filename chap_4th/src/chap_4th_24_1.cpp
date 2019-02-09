
#include <iostream>
#include <string>

class Rational {
public:
  Rational(int numerator=0, int denominator=1) 
   : m_numerator(numerator), m_denominator(denominator) 
  { std::cout << "Rational(int numerator, int denominator)" << std::endl; }

  ~Rational()
  { std::cout << "~Rational()" << std::endl; }

  Rational(const Rational &rhs) {
    this->m_numerator = rhs.m_numerator;
    this->m_denominator = rhs.m_denominator;
    std::cout << "Rational(const Rational &rhs)" << std::endl;
  }

  Rational& operator=(const Rational& rhs) {
    std::cout << "operator=(const Rational& rhs)" << std::endl;
    m_numerator = rhs.m_numerator;
    m_denominator = rhs.m_denominator;
    return *this;
  }

  int m_numerator;
  int m_denominator;
};

int main(int, char**) {
  std::cout << "chap_4th_24_1.cpp" << std::endl;

  Rational r = 100;
  Rational rr = r;

  std::cout << "r.m_numerator : " << r.m_numerator << std::endl;
  std::cout << "r.m_denominator : " << r.m_denominator << std::endl;

  return 0;
}