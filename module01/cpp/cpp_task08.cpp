#include <iostream>
#include <random>

#define SIZE 5

void fillMatr(float** matr) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(30.0, 60.0);
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      matr[i][j] = dis(gen);
    }
  }
}

float maxValue(float** matr) {
  float extr = matr[0][0];
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (matr[i][j] > extr) { extr = matr[i][j];}
    }
  }
  return extr;
}

float minValue(float** matr) {
  float extr = matr[0][0];
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (matr[i][j] < extr) { extr = matr[i][j];}
    }
  }
  return extr;
}

int main(int argc, char const *argv[]) {
  float** matr = new float*[SIZE];
  for (int i=0; i<SIZE; ++i) {
    matr[i] = new float[SIZE];
  }

  fillMatr(matr);
  std::cout << "MAX: " << maxValue(matr) << std::endl;
  std::cout << "MIN: " << minValue(matr) << std::endl;

  for (int i=0; i<SIZE; ++i) {
    delete matr[i];
  }
  delete matr;


  return 0;
}