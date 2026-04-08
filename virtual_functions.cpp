// virtual function
#include <iostream>
using namespace std;

class Base {
public:
  virtual void show() { cout << "Base\n"; }
};

class Dev1 : public Base {
public:
  void show() override { cout << "Dev1\n"; }
};

class Dev2 : public Base {
public:
  void show() override { cout << "Dev2\n"; }
};

int main() {
  Dev1 dv1;
  Dev2 dv2;
  Base *ptr;

  ptr = &dv1;
  ptr->show();

  ptr = &dv2;
  ptr->show();

  return 0;
}

//early binding/static binding

// late binding/dynamic binding

//Polymorphism-- when a call to a member function causes a different function to be executed depending on the type of object that invokes the function.