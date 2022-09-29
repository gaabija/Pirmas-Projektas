#include <iostream>

#include <string>

#include <stdio.h>

#include <cstdio>

#include <algorithm>

#include <vector>

#include <numeric>

#include <ctype.h>

#include <limits>

#include <fstream>

#include <sstream>

#include <iomanip>

#include <iterator>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::sort;
using std::vector;
using std::accumulate;
using std::numeric_limits;
using std::streamsize;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::basic_stringstream;
using std::setprecision;
using std::istream_iterator;

struct Irasas {
  string vardas;
  string pavarde;
  vector < int > pazymiai;
  double pazSuma = 0;
  int egzas;
  double galutv;
  double galutm;
};

void Duomenys(vector < Irasas > studentai);
void NaudotojoSuvedimas(Irasas & temp);
void RandomSuvedimas(Irasas & temp);
double Mediana(Irasas & temp);
int SkIvedimas();
double Vidurkis(Irasas & temp);
void FailoDuomenuGavimas(Irasas & temp, int nPazymiu);
void NefailoDuomenuGavimas(Irasas & temp);
bool Lyginimas(Irasas & a, Irasas & b);
double KiekPazymiu(string
  const & str);
void RezultataiSpausdinimas(vector < Irasas > studentai);

ifstream fd("kursiokai.txt");
int main() {
  vector < Irasas > studentai;
  studentai.reserve(10000);
  Duomenys(studentai);
  studentai.clear();
  return 0;
}

void Duomenys(vector < Irasas > studentai) {
  cout << "Iveskite 'f' jei norite duomenis imti is failo. Iveskite 'b' kad kad galetumete toliau naudotis be failo . )  ";
  char arFailas;
  int nStudentu;
  while (true) {
    cin >> arFailas;
    arFailas = tolower(arFailas);
    if (arFailas != 'f' && arFailas != 'b') {
      cout << "Iveskite f arba b raidę: ";
    } else break;
  }
  if (arFailas == 'b') {

    cout << "Iveskite studentu skaiciu: ";
    cin >> nStudentu;
    for (int i = 0; i < nStudentu; i++) {
      Irasas st;
      NefailoDuomenuGavimas(st);
      studentai.push_back(st);
      st.pazymiai.clear();
    }
    RezultataiSpausdinimas(studentai);

  } else if (arFailas == 'f') {
    try {
      if (!fd.is_open())
        throw 0;
      string row1;
      getline(fd, row1);
      double nPazymiu = KiekPazymiu(row1);
      while (!fd.eof()) {
        Irasas st;
        FailoDuomenuGavimas(st, nPazymiu);
        studentai.push_back(st);
      }
    } catch (int err) {
      std::cerr << "Neatsidare nurodytas failas " << err << endl;
    }
    RezultataiSpausdinimas(studentai);
  }

}
double KiekPazymiu(string
  const & stream) {
  stringstream streaming(stream); // distance from first and last element -3 nes vardas pavarde egzas
  return distance(istream_iterator < string > (streaming), istream_iterator < string > ()) - 3;
}
void FailoDuomenuGavimas(Irasas & temp, int nPazymiu) {
  temp.pazSuma = 0;
  char vardas[20];
  char pav[26];
  fd.get(vardas, 20);
  temp.vardas = vardas;
  fd.get(pav, 26);
  temp.pavarde = pav;
  int pazymys;
  for (int i = 0; i < nPazymiu; i++) {
    fd >> pazymys;
    temp.pazymiai.push_back(pazymys);
    temp.pazSuma += pazymys;
  }
  fd >> temp.egzas;

  fd.clear();
  fd.ignore(256, '\n');
}
void NefailoDuomenuGavimas(Irasas & temp) {
  cout << "Iveskite varda: ";
  cin >> temp.vardas;
  cout << "Iveskite pavarde: ";
  cin >> temp.pavarde;
  cout << "Iveskite 'p' jei norite ivesti namu darbu pazymius patys. Iveskite 'a' kad pazymiai butu sugeneruojami atsitiktinai . )  ";
  char arPats;
  while (true) {
    cin >> arPats;
    arPats = tolower(arPats);
    if (arPats != 'p' && arPats != 'a') {
      cout << "Iveskite a arba p raidę: ";
    } else break;
  }
  if (arPats == 'p') {
    NaudotojoSuvedimas(temp);
  } else if (arPats == 'a') {
    RandomSuvedimas(temp);
  }
}
void NaudotojoSuvedimas(Irasas & temp) {
  cout << "Iveskite namų darbų ivertinimus (desimtbaleje sistemoje) paspausdami Enter, kai baigsite iveskite 0 ir Enter " << endl;
  int pazymys;
  int i = 1;
  while (true) {
    cout << i << " -as pazymys: ";
    while (true) {
      pazymys = SkIvedimas();
      if (pazymys < 0 || pazymys > 10) {
        cout << "Iveskite skaiciu desimtbaleje sistemoje: ";
      } else break;
    }
    if (pazymys >= 1 && pazymys <= 10) {
      temp.pazymiai.push_back(pazymys);

      temp.pazSuma = temp.pazSuma + pazymys;
    } else break;
    i++;
  }

  cout << "Iveskite egzamino ivertinima (desimtbaleje sistemoje): ";
  while (true) {
    temp.egzas = SkIvedimas();
    if (temp.egzas < 0 || temp.egzas > 10) {
      cout << "Iveskite skaiciu desimtbaleje sistemoje: ";
    } else break;
  }
}

void RandomSuvedimas(Irasas & temp) {
  cout << "Iveskite kiek namu darbu pazymiu sugeneruoti: ";
  int npaz;
  npaz = SkIvedimas();
  cout << "Sugeneruoti namu darbu ivertinimai: ";
  for (int i = 0; i < npaz; i++) {
    temp.pazymiai.push_back(1 + rand() % 10);
    cout << temp.pazymiai.at(i) << " ";
  }
  cout << endl;
  temp.egzas = 1 + rand() % 10;
  cout << "Sugeneruotas egzamino ivertinimas: " << temp.egzas << endl;
}

double Vidurkis(Irasas & temp) {
  double vidurkis;
  if (temp.pazSuma != 0) {
    vidurkis = accumulate(temp.pazymiai.begin(), temp.pazymiai.end(), 0.0) / temp.pazymiai.size();
  } else vidurkis = 0;
  return vidurkis;
}

double Mediana(Irasas & temp) {
  double mediana;
  if (temp.pazSuma != 0) {
    sort(temp.pazymiai.begin(), temp.pazymiai.end());
    if (temp.pazymiai.size() % 2 == 0) {
      mediana = (temp.pazymiai[temp.pazymiai.size() / 2] + temp.pazymiai[temp.pazymiai.size() / 2 + 1]) / 2;
    } else {
      mediana = temp.pazymiai[temp.pazymiai.size() / 2];
    }
  } else mediana = 0;
  return mediana;
}

void RezultataiSpausdinimas(vector < Irasas > studentai) {
  printf("%20s %20s %20s %20s\n ", "Pavarde\t", "Vardas\t", "Galutinis(vid)\t", "Galutinis(med)\t");
  sort(studentai.begin(), studentai.end(), Lyginimas);
  for (Irasas & temp: studentai) {
    temp.galutv = 0.4 * Vidurkis(temp) + (0.6 * temp.egzas);
    temp.galutm = 0.4 * Mediana(temp) + (0.6 * temp.egzas);
    printf("%20s %20s %20.2f %20.2f\n ", temp.pavarde.c_str(), temp.vardas.c_str(), temp.galutv, temp.galutm);
  }
}

int SkIvedimas() {
  int sk;
  cin >> sk;
  while (1) {
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
      cout << "Iveskite sveikaji skaiciu: " << endl;
      cin >> sk;
    }
    if (!cin.fail())
      break;
  }
  return sk;
}
bool Lyginimas(Irasas & a, Irasas & b) {
  return a.pavarde < b.pavarde;
}
