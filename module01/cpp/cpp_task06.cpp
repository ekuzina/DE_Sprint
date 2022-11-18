#include <iostream>
#include <string>


int main(int argc, char const *argv[]){
  std::string stop = "stop";
  std::string tmp = "";
  float num = 0;
  float max = 0;

  std::cin >> num;
  max = num;
  do {
    std::cin >> tmp;
    try {
      num = std::stof(tmp);
      if (num > max) { max = num;}
    } catch(...) {}
  } while (stop.compare(tmp) != 0);

  std::cout << "MAX: " << max << std::endl;

  return 0;
}