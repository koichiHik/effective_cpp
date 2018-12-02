
template<class T>
class TemplatedClass1 {
public:
  T member;
};

template<typename T>
class TemplatedClass2 {
public:
  T member;
};

int main(int, char**) {

  TemplatedClass1<int> tc1;
  TemplatedClass2<int> tc2;

  return 0;
}