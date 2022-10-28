#include "funkcijos.h"

int main() {
  cout << "Iveskite f jeigu norite dirbti su failu arba n jei norite studentus ivesti patys: " << endl;;
  char arGeneruoti;
  while (true) {
    cin >> arGeneruoti;
    arGeneruoti = tolower(arGeneruoti);
    if (arGeneruoti != 'f' && arGeneruoti != 'n') {
      cout << "Iveskite f arba n raidę: ";
    } else break;
  }
  if (arGeneruoti == 'f') {
    Pagalbine();
  } else if (arGeneruoti == 'n') {
    vector < Irasas > studentai;
    studentai.reserve(1000);
    Duomenys(studentai);
    studentai.clear();
  }

  return 0;
}

