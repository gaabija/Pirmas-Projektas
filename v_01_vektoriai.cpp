#include <iostream>

#include <string>

#include <cstdio>

#include <algorithm>

#include <vector>

#include <numeric>

#include <ctype.h>

#include<limits>


using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::sort;
using std::vector;
using std::accumulate;
using std::isdigit;
using std::numeric_limits;
using std::streamsize;

struct Irasas {
  string vardas;
  string pavarde;
  vector < int > pazymiai;
  int npaz = 0;
  double pazSuma = 0;
  int egzas;
  double galut;
};

void Duomenys(Irasas & temp);
void NaudotojoSuvedimas(Irasas & temp);
void RandomSuvedimas(Irasas & temp);
double Mediana(Irasas & temp);
int SkIvedimas();
double Vidurkis(Irasas & temp);
void Spausdinimas(Irasas temp);
void Galutinis(Irasas & temp, char budasIsvesti);

int main() {

  int nStudentu;
  cout << "Iveskite studentu skaiciu: ";
  nStudentu = SkIvedimas();

  vector < Irasas > studentai;
  Irasas irasas;
  studentai.reserve(nStudentu);
  for (int i = 0; i < nStudentu; i++) {
    Duomenys(irasas);
    studentai.push_back(irasas);
    irasas.pazymiai.clear();
  }
  printf("%10s %10s %20s\n ", "Vardas\t", "Pavarde\t", "Galutinis balas\t");
  for (const Irasas & studentas: studentai) {
    Spausdinimas(studentas);
  }
  return 0;
}

void Duomenys(Irasas & temp) {
  cout << "Iveskite varda: ";
  cin >> temp.vardas;
  cout << "Iveskite pavarde: ";
  cin >> temp.pavarde;
  cout << "Iveskite 'p' jei norite ivesti namu darbu pazymius patys. Iveskite 'a' kad pazymiai butu sugeneruojami atsitiktinai . )  ";
  char arPats;
  while (true) {
    cin >> arPats;
    if (arPats != 'p' && arPats != 'a') {
      cout << "Iveskite a arba p raidę: ";
    } else break;
  }
  if (arPats == 'p') {
    NaudotojoSuvedimas(temp);
  } else if (arPats == 'a') {
    RandomSuvedimas(temp);
  }
  cout << "Ar norite kad galutinis balas butu isvedamas pagal viduki? 'v' Ar norite kad butu isvedamas pagal mediana? 'm' )  ";
  char arVidurkis;
  while (true) {
    cin >> arVidurkis;
    if (arVidurkis != 'v' && arVidurkis != 'm') {
      cout << "Iveskite v arba m raidę: ";
    } else break;
  }
  if (arVidurkis == 'v') {
    Galutinis(temp, 'v');
  } else if (arVidurkis == 'm') {
    Galutinis(temp, 'm');
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
      temp.npaz++;
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
  temp.npaz = SkIvedimas();
  cout << "Sugeneruoti namu darbu ivertinimai: ";
  for (int i = 0; i < temp.npaz; i++) {
    temp.pazymiai.push_back(1 + rand() % 10);
    cout << temp.pazymiai.at(i) << " ";
  }
  cout << endl;
  temp.egzas = 1 + rand() % 10;
  cout << "Sugeneruotas egzamino ivertinimas: " << temp.egzas << endl;
}

double Vidurkis(Irasas & temp) {
  int vidurkis;
  if (temp.pazSuma != 0) {
    vidurkis = temp.pazSuma / temp.npaz;
  } else vidurkis = 0;
  return vidurkis;
}

double Mediana(Irasas & temp) {
  double mediana;
  if (temp.pazSuma != 0) {
    sort(temp.pazymiai.begin(), temp.pazymiai.end());
    if (temp.npaz % 2 == 0) {
      mediana = (temp.pazymiai[temp.npaz / 2] + temp.pazymiai[temp.npaz / 2 + 1]) / 2;
    } else {
      mediana = temp.pazymiai[temp.npaz / 2];
    }
  } else mediana = 0;
  return mediana;
}
void Galutinis(Irasas & temp, char budasIsvesti) {
  double galutinis;
  double vidurkis = Vidurkis(temp);
  double mediana = Mediana(temp);
  if (budasIsvesti == 'v') {
    temp.galut = vidurkis * 0.4 + temp.egzas * 0.6;
  } else if (budasIsvesti == 'm') {
    temp.galut = mediana * 0.4 + temp.egzas * 0.6;
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
void Spausdinimas(Irasas temp) {
  cout << endl;
  printf("%10s %10s %20.2f\n ", temp.vardas.c_str(), temp.pavarde.c_str(), temp.galut);

}
