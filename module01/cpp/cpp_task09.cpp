#include <iostream>
#include <string>
#include <array>
#include <utility>
#include <algorithm>

#define NMARKS 5

struct Student{
  std::string name = "Noname NN";
  std::string group = "no group";
  std::array<int, NMARKS> marks = {0,0,0,0,0};
};

Student createStudent(const char* name, const char* group, std::array<int, NMARKS> marks) {
  Student s;
  s.name = name;
  s.group = group;
  s.marks = marks;

  return s;
}

float meanMark(Student& s) {
  float mean = 0;
  for (int v: s.marks) { mean += v;}
  mean /= NMARKS;

  return mean;
}

struct compMarks {
  bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
    return left.second < right.second;
  }
};

template<size_t n>
void sortEntries(std::array<Student, n>* arr) {
  std::array<std::pair<int,int>, n> marks;
  for(int i=0; i<n; i++) {
    marks.at(i) = std::pair<int,int>(i,meanMark(arr->at(i)));
  }
  std::sort(marks.begin(), marks.end(), compMarks());
  std::array<Student, n> tmpArr = *arr;
  for(int i=0; i<marks.size(); i++) {
    arr->at(i) = tmpArr.at(marks.at(i).first);
  }
  return;
}

bool isMarksGood(Student& s) {
  for(int m: s.marks) {
    if(m<4) {return false;}
  }
  return true;
}

template<size_t n>
void printStudents(std::array<Student, n>* arr) {
  for(Student s: *arr) {
    if(isMarksGood(s)) {
      std::cout << s.name << "\t" << s.group<< std::endl;}
  }

}


int main(int argc, char const *argv[]) { 
  std::array<Student, 4> students;

  students.at(3) = createStudent("Ivanov II",  "B21-503", {2,4,5,3,3});
  students.at(2) = createStudent("Sidorov SF", "B21-503", {5,4,5,4,4});
  students.at(1) = createStudent("Kuznetsov VD",  "B19-316", {2,4,5,3,4});
  students.at(0) = createStudent("Petrov PV",  "M20-401", {5,5,5,5,5});

  sortEntries(&students);
  std::cout<<"Good students: "<<std::endl;
  printStudents(&students);

  return 0;
}