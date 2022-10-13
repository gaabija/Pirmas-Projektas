#include "funkcijos.h"

int main() {
  cout << "Iveskite g jeigu norite generuoti faila arba n jei norite studentus ivesti patys: " << endl;;
  char arGeneruoti;
  while (true) {
    cin >> arGeneruoti;
    arGeneruoti = tolower(arGeneruoti);
    if (arGeneruoti != 'g' && arGeneruoti != 'n') {
      cout << "Iveskite g arba n raidę: ";
    } else break;
  }
  if (arGeneruoti == 'g') {
    FailoGeneravimas();
  } else if (arGeneruoti == 'n') {
    vector < Irasas > studentai;
    studentai.reserve(10000);
    Duomenys(studentai);
    studentai.clear();
  }

  return 0;
}

