
#include <iostream>

class Rational
{
public:
  Rational(int numerator=0, int denominator=1)
    : m_numerator(numerator), m_denominator(denominator) {};

  void say() {
    std::cout << "m_numerator : " << m_numerator << std::endl;
    std::cout << "m_denominator : " << m_denominator << std::endl;
  }

public:
  int m_numerator;
  int m_denominator;
};

Rational operator*(const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.m_numerator+rhs.m_numerator, lhs.m_denominator+rhs.m_denominator);
}


int main(int, char**) {

  Rational a(100, 10);
  
  Rational ans1 = a * 10;
  Rational ans2 = 10 * a;

  ans1.say();
  ans2.say();

  return 0;
}