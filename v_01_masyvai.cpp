#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include<limits>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::sort;
using std::numeric_limits;
using std::streamsize;

struct Irasas {
  string vardas, pavarde;
  int * paz = new int[50];
  int npaz = 0;
  double pazSuma = 0;
  int egzas;
  double galut;
};

void Duomenys(Irasas & temp);
void NaudotojoSuvedimas(Irasas & temp);
void RandomSuvedimas(Irasas & temp);
int SkIvedimas();
double Mediana(Irasas & temp);
double Vidurkis(const Irasas & temp);
void Spausdinimas(int nStudentu, Irasas studentai[]);
void Galutinis(Irasas & temp, char budasIsvesti);

int main() {

  int nStudentu;
  cout << "Iveskite studentu skaiciu: ";
  nStudentu = SkIvedimas();
  Irasas * studentai = new Irasas[nStudentu];
  for (int i = 0; i < nStudentu; i++) {
    Duomenys(studentai[i]);
  }
  Spausdinimas(nStudentu, studentai);
  delete[] studentai;
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

  cout << "Iveskite namu darbu ivertinimus (desimtbaleje sistemoje) paspausdami Enter, kai noresite baigti vesti pazymius iveskite 0 ir Enter " << endl;;
  for (int i = 0; i < sizeof(temp.paz); i++) {
    cout << "Iveskite " << i + 1 << " pazymi: ";
    while (true) {
      temp.paz[temp.npaz] = SkIvedimas();
      if (temp.paz[temp.npaz] < 0 || temp.paz[temp.npaz] > 10) {
        cout << "Iveskite skaiciu desimtbaleje sistemoje: ";
      } else break;
    }
    if (temp.paz[temp.npaz] != 0) {
      temp.pazSuma = temp.pazSuma + temp.paz[temp.npaz];
      temp.npaz++;
    } else break;

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
    temp.paz[i] = 1 + rand() % 10;
    temp.pazSuma = temp.pazSuma + temp.paz[i];
    cout << temp.paz[i] << " ";
  }
  cout << endl;
  temp.egzas = 1 + rand() % 10;
  cout << "Sugeneruotas egzamino ivertinimas: " << temp.egzas << endl;
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

double Vidurkis(Irasas & temp) {
  int vidurkis;
  if (temp.npaz != 0) {
    vidurkis = temp.pazSuma / temp.npaz;
  } else vidurkis = 0;
  return vidurkis;
}

double Mediana(Irasas & temp) {
  double mediana;
  if (temp.npaz != 0) {
  sort(temp.paz, temp.paz + temp.npaz);
  if (temp.npaz % 2 == 0) {
    mediana = (temp.paz[temp.npaz / 2] + temp.paz[temp.npaz / 2 + 1]) / 2;
  } else {
    mediana = temp.paz[temp.npaz / 2];
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

void Spausdinimas(int nStudentu, Irasas studentai[]) {
  cout << endl;
  printf("%10s %10s %20s\n ", "Vardas\t", "Pavarde\t", "Galutinis balas\t");
  for (int i = 0; i < nStudentu; i++) {
    printf("%10s %10s %20.2f\n ", studentai[i].vardas.c_str(), studentai[i].pavarde.c_str(), studentai[i].galut);
  }

}
