
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

  Rational operator*(const Rational& rhs) {
    std::cout << "operator*(const Rational& rhs)" << std::endl;
    return Rational(this->m_numerator * rhs.m_numerator, this->m_denominator * rhs.m_denominator);
  }

  void say() {
    std::cout << "m_numerator : " << m_numerator << std::endl;
    std::cout << "m_denominator : " << m_denominator << std::endl;    
  }

  int m_numerator;
  int m_denominator;
};

int main(int, char**) {
  std::cout << "chap_4th_24_3.cpp" << std::endl;

  // 100からの暗黙の型変換．
  Rational r = 100;

  // 2からの暗黙の型変換　＋　掛け算の実行．
  Rational ans = r * 2;
  Rational ans2 = r.operator*(Rational(2));

  ans.say();
  ans2.say();

  return 0;
}