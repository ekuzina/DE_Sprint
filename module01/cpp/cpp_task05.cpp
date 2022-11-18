#include <iostream>

int main(int argc, char const *argv[]) {
  for(int i = 1; i < 11; ++i) {
    std::cout << i << "^2\t=\t" << i*i << std::endl; 
  }

  return 0;
}