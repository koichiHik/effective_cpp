
#include <iostream>
#include <tr1/functional>

double cameraSense(void) {
  std::cout << "Camera Sense" << std::endl;
  return 0.0;
}

class Robot {
public:
  typedef std::tr1::function<double (void)> senseFunc;
  explicit Robot(senseFunc func) 
  : func(func)
  {};
  virtual ~Robot() {}
  double doSense() const {
    func();
    return 0.0;
  }

private:
  senseFunc func;
};

class Humanoid : public Robot {
public:
  explicit Humanoid(senseFunc func) 
    : Robot(func)
  {}
};

int main(int, char**) {

  std::cout << "Hello World!" << std::endl;
  const Robot* robo = new Humanoid(cameraSense);
  robo->doSense();

  return 0;
}