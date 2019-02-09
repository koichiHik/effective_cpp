
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

template class Rational<int>;

/**
template<>
class Rational<int>
{
public:
  Rational(const int& numerator=0, const int& denominator=1)
    : m_numerator(numerator), m_denominator(denominator)
  {};

  friend const Rational<int> operator*(const Rational<int>& lhs, const Rational<int>& rhs) {
    return Rational<int>(lhs.m_numerator+rhs.m_numerator, lhs.m_denominator+rhs.m_denominator);
  }
  void say() {
    std::cout << "m_numerator : " << m_numerator << std::endl;
    std::cout << "m_denominator : " << m_denominator << std::endl;
  }


public:
  int m_numerator;
  int m_denominator;
};

**/


template<typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {
  return Rational<T>(lhs.m_numerator+rhs.m_numerator, lhs.m_denominator+rhs.m_denominator);
}

template const Rational<int> operator*(const Rational<int>&, const Rational<int>&);

/*
const Rational<int> operator*(const Rational<int>& lhs, const Rational<int>& rhs) {
  return Rational<int>(lhs.m_numerator+rhs.m_numerator, lhs.m_denominator+rhs.m_denominator);
}
*/

int main(int, char**) {

  Rational<int> tmp = 10;
  Rational<int> a(100, 10);
  Rational<int> b(10, 100);

  tmp.say();

  Rational<int> ans = tmp * a;
  ans.say();

  Rational<int> ans2 = tmp * 2;
  ans2.say();

  return 0;
}