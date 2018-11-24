#include <iostream>


class Top {
  public:
  Top();
};

Top::Top() {
  std::cout << "Top Constructor!" << std::endl;
}

class Middle {
public:
  Middle();
};

Middle::Middle() {
  std::cout << "Middle Constructor!" << std::endl;
}

class Low : Middle {
private:
  Top top;
};

int main(int, char**) {
  std::cout << "2nd Chapter 5" << std::endl;

  // Class Generation.
  Low low;

}
