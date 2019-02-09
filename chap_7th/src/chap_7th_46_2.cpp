
#include <iostream>

template<typename T>
class Rational
{
public:
  Rational(const T& numerator=0, const T& denominator=1)
    : m_numerator(numerator), m_denominator(denominator) {};

  void say() {
    std::cout << "m_numerator : " << m_numerator << std::endl;
    std::cout << "m_denominator : " << m_denominator << std::endl;
  }

public:
  T m_numerator;
  T m_denominator;
};

template<typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {
  return Rational<T>(lhs.m_numerator+rhs.m_numerator, lhs.m_denominator+rhs.m_denominator);
}

int main(int, char**) {

  Rational<int> a(100, 10);
  
  //Rational<int> ans1 = a * 10;
  //Rational<int> ans2 = 10 * a;

  ans1.say();
  ans2.say();

  return 0;
}