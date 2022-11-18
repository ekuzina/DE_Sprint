#include <iostream>

int main(int argc, char const *argv[]) {
  int year = 0;
  const char* leapYear = "The year is leap";
  const char* notLeapYear = "The year is not leap";

  std::cout << "Insert the year to define whether it is leap or not" << std::endl;
  std::cin >> year;

  if (year % 100 == 0) {
   if (year % 400 == 0) { std::cout << leapYear << std::endl;} 
   else { std::cout << notLeapYear << std::endl;}
  } else {
    if (year % 4 == 0) { std::cout << leapYear << std::endl;} 
    else { std::cout << notLeapYear << std::endl;}
  }

  return 0;
}