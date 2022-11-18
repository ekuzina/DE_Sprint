#include <iostream>

int main(int argc, char const *argv[])
{
  std::cout << "Values for y=-2 * x^2 - 5 * x - 8" << std::endl;
  float x = -4;
  while(x<4.01) {
    std::cout << "x:\t" << x <<"\t\ty:\t" << (-2*x*x-5*x-8) <<std::endl;
    x += 0.5;
  }
  return 0;
}