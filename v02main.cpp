#include "funkcijos.h"
int main() {
  vector < Irasas > studentai;
  studentai.reserve(10000);
  Duomenys(studentai);
  studentai.clear();
  return 0;
}
