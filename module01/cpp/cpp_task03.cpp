#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <array>

float discriminant(const std::array<float, 3>& coefs) {
  float D = pow(coefs.at(1), 2) - 4*coefs.at(0)*coefs.at(2);
  if (D < 0) {
    std::cout << "Descriminant is negative. I cannot solve equations with complex roots. Bye...";
    exit(EXIT_FAILURE);
  }

  return D;
}

std::array<float, 2>solution(const std::array<float, 3>& coefs) {
  float D = discriminant(coefs);
  std::array<float, 2> x;
  if (D < 1e-6) {
    x.at(0) = -coefs.at(1)/2/coefs.at(0);
    x.at(1) = x.at(0);
  } else {
    x.at(0) = (-coefs.at(1)+sqrt(D))/2/coefs.at(0);
    x.at(1) = (-coefs.at(1)-sqrt(D))/2/coefs.at(0);
  }
  return x;
}

int main(int argc, char const *argv[]) {
  std::array<float, 3> coefs;
  std::cout << "Insert coefficients for quadratic equation: Ax^2+Bx+C=0\n" << std::endl;
  
  std::cout << "A: ";
  std::cin >> coefs.at(0);
  if (fabs(coefs.at(0))<1e-6) {
    std::cout << "That will be a linear equation. I won't solve it. Bye..." << std::endl;
    return 1;
  }
  std::cout << "B: ";
  std::cin >> coefs.at(1);
  std::cout << "C: ";
  std::cin >> coefs.at(2);

  std::array<float, 2> x = solution(coefs);
  std::cout<<"x1 = " << x.at(0) << "\tx2 = " << x.at(1) << std::endl;
    
  return 0;
}