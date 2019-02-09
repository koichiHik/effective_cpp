
#include <iostream>

class Robot {
public:
  virtual ~Robot(){}
  double sense() const {
    return this->doSense();
  }

private:
  virtual double doSense() const = 0;
};

class CameraRobot : public Robot {
public:
  virtual ~CameraRobot(){}
private:
  virtual double doSense() const {
    std::cout << "Sensing by Camera." << std::endl;
    return 0.0;
  };
};

class LidarRobot : public Robot {
public:
  virtual ~LidarRobot(){};
private:
  virtual double doSense() const {
    std::cout << "Sensing by Lidar." << std::endl;
    return 0.0;
  };
};

int main(int, char const **)
{

  std::cout << "Hello World!" << std::endl;

  const Robot* robo = new CameraRobot();
  robo->sense();


  return 0;
}
