
#include <iostream>

class SensingStrategy {
public:
  virtual ~SensingStrategy() {}
  virtual double sense() const = 0;
};

class CameraSensing : public SensingStrategy {
public:
  virtual ~CameraSensing() {}
  virtual double sense() const {
    std::cout << "CameraSensing" << std::endl;
    return 0.0;
  }
};

class LidarSensing : public SensingStrategy {
public:
  virtual ~LidarSensing() {}
  virtual double sense() const {
    std::cout << "LidarSensing" << std::endl;
    return 0.0;
  }
};

class Robot {
public:
  explicit Robot(std::string strategy) 
  : sStrat(nullptr)
  {
    if (strategy == "Camera") {
      sStrat = new CameraSensing();
    }
  };
  virtual ~Robot() {}
  double doSense() const {
    sStrat->sense();
    return 0.0;
  }

private:
  SensingStrategy *sStrat;
};

class Humanoid : public Robot {
public:
  explicit Humanoid(std::string strategy) 
    : Robot(strategy)
  {}
};

int main(int, char**) {

  std::cout << "Hello World!" << std::endl;
  const Robot* robo = new Humanoid("Camera");
  robo->doSense();

  return 0;
}