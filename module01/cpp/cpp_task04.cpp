#include <iostream>

int main(int argc, char const *argv[]) {
  int number = 0;

  std::cout << "Insert number to define if it is even or odd: ";
  std::cin >> number;
  
  if (number % 2 == 0) { std::cout<< "It is even."<<std::endl;}
  else { std::cout << "It is odd" <<std::endl;}

  return 0;
}
