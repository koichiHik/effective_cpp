
#include <iostream>

double cameraSense() {
  std::cout << "CameraSensing" << std::endl;
  return 0.0;
}

double lidarSense() {
  std::cout << "LidarSensing" << std::endl;
  return 0.0;
}

class Robot {
public:
  typedef double (*senseFunc)(void);
  explicit Robot(senseFunc func) 
  : func(func)
  {}
  double sense() const {
    return this->func();
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
  const Robot*robo = new Humanoid(cameraSense);
  robo->sense();

  return 0;
}