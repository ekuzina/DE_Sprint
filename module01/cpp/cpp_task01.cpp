#include <iostream>
#include <string>
#include <cmath>

using std::cout, std::cin, std::endl;

int main(int argc, char const *argv[]) {
  float num1 = 0;
  float num2 = 0;  

  cout << "Insert two numbers separated by <ENTER>..." << endl;
  cin  >>  num1 >> num2;

  float eps = 1e-6;
  float diff = num1 - num2;

  if (fabs(diff) < eps) {
    cout << "Numbers are equal" << endl;
  } else {
    if (diff > 0) {
      cout << "First number is bigger than second one" << endl;  
    } else {
      cout << "Second number is bigger than first one" << endl;
    }
  }

  return 0;
}