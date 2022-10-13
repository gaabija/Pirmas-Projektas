#include "funkcijos.h"

void Duomenys(vector < Irasas > studentai) {
  int nStudentu;
  char budasIsvesti;
  cout << "Iveskite studentu skaiciu: ";
  cin >> nStudentu;
  for (int i = 0; i < nStudentu; i++) {
    Irasas st;
    NefailoDuomenuGavimas(st);
    studentai.push_back(st);
    st.pazymiai.clear();
  }
  cout << "Ar norite kad galutinis balas butu isvedamas pagal viduki? 'v' Ar norite kad butu isvedamas pagal mediana? 'm' )  ";
  char arVidurkis;
  while (true) {
    cin >> arVidurkis;
    arVidurkis = tolower(arVidurkis);
    if (arVidurkis != 'v' && arVidurkis != 'm') {
      cout << "Iveskite v arba m raidę: ";
    } else break;
  }
  if (arVidurkis == 'v') {
    budasIsvesti = 'v';
  } else if (arVidurkis == 'm') {
    budasIsvesti = 'm';
  }
  sort(studentai.begin(), studentai.end(), Lyginimas);
  printf("%10s %10s %20s\n ", "Vardas\t", "Pavarde\t", "Galutinis balas\t");
  for (Irasas & studentas: studentai) {
    Galutinis(studentas, budasIsvesti);
    Spausdinimas(studentas);
  }

}
void Spausdinimas(Irasas temp) {
  cout << endl;
  printf("%10s %10s %20.2f\n ", temp.vardas.c_str(), temp.pavarde.c_str(), temp.galut);

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
bool Lyginimas(Irasas & a, Irasas & b) {
  return a.vardas < b.vardas;
}

double Vidurkis(Irasas temp) {
  double vidurkis =
    accumulate(temp.pazymiai.begin(), temp.pazymiai.end(), 0.0) / temp.pazymiai.size();
  return vidurkis;
}

double Mediana(Irasas temp) {
  double mediana;
  sort(temp.pazymiai.begin(), temp.pazymiai.end());
  int vidurinisElementas = temp.pazymiai.size() / 2;
  if (temp.pazymiai.size() / 2 == 0) {
    mediana = (temp.pazymiai[vidurinisElementas - 1] + temp.pazymiai[vidurinisElementas]) / 2.;
  } else {
    mediana = temp.pazymiai[vidurinisElementas];
  }
  return mediana;
}

void FailoGeneravimas() {
  cout << "Iveskite kiek pazymiu kiekvienam studentui sugeneruoti: ";
  int nPazymiu;
  nPazymiu = SkIvedimas();
  cout << "Ar norite kad galutinis balas butu isvedamas pagal viduki? 'v' Ar norite kad butu isvedamas pagal mediana? 'm' )  ";
  char arVidurkis;
  char budasIsvesti;
  while (true) {
    cin >> arVidurkis;
    arVidurkis = tolower(arVidurkis);
    if (arVidurkis != 'v' && arVidurkis != 'm') {
      cout << "Iveskite v arba m raidę: ";
    } else break;
  }
  if (arVidurkis == 'v') {
    budasIsvesti = 'v';
  } else if (arVidurkis == 'm') {
    budasIsvesti = 'm';
  }
   cout << "-------------------------------------------------------------------------" << endl;
  string name;
  int studentuSkaiciai[5] = {
    100,
    1000,
    10000,
    100000,
    1000000
  };

  vector < Irasas > studentai;
  vector < Irasas > geresnioBalo;
  vector < Irasas > zemesnioBalo;

  for (int i: studentuSkaiciai) {
    int nStudentu = i;
    DuomenuGeneravimas(nStudentu, nPazymiu);
    FailoDuomenuGavimas(studentai, nStudentu, nPazymiu);
    Grupavimas(nStudentu, studentai,
      geresnioBalo, zemesnioBalo, budasIsvesti);
    Spausdinimas(nStudentu, geresnioBalo, zemesnioBalo);
  }
}

void DuomenuGeneravimas(int & nStudentu, int & nPazymiu) {
  string name = "Studentai" + to_string(nStudentu) + ".txt";
  ofstream stud(name);
  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  for (int i = 0; i < nStudentu; i++) {
    stud << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
    for (int j = 0; j < nPazymiu + 1; j++) {
      stud << rand() % 10 + 1 << " ";
    }
    stud << endl;
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration < double > diff = end - start;
  cout << to_string(nStudentu) << " irasu generavimo laikas: " << diff.count() << " s\n";
}

void FailoDuomenuGavimas(vector < Irasas > & studentai, int nStudentu, int nPazymiu) {
  int index = 0;
  ifstream fd;
  string name = "Studentai" + to_string(nStudentu) + ".txt";
  fd.open(name);
  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  while (index < nStudentu) {
    studentai.resize(studentai.size() + 1);
    fd >> studentai.at(index).vardas;
    fd >> studentai.at(index).pavarde;
    int ivestis;
    for (int i = 0; i < nPazymiu; i++) {
      fd >> ivestis;
      studentai.at(index).pazymiai.push_back(ivestis);
    }
    fd >> studentai.at(index).egzas;
    index++;
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration < double > diff = end - start;
  cout << to_string(nStudentu) << " irasu nuskaitymo laikas: " << diff.count() << " s\n";

}

void Grupavimas(int nStudentu, vector < Irasas > & studentai,
  vector < Irasas > & geresnioBalo, vector < Irasas > & zemesnioBalo, char budasIsvesti) {
  if (budasIsvesti == 'm') {
    for (int i = 0; i < nStudentu; i++) {
      studentai.at(i).galut = Mediana(studentai.at(i)) * 0.4 +
        studentai.at(i).egzas * 0.6;
    }
  } else if (budasIsvesti == 'v') {
    for (int i = 0; i < nStudentu; i++) {
      studentai.at(i).galut = Vidurkis(studentai.at(i)) * 0.4 +
        studentai.at(i).egzas * 0.6;
    }
  }
  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  for (auto & i: studentai) {
    if (i.galut < 5.00) {
      zemesnioBalo.push_back(i);
    } else {
      geresnioBalo.push_back(i);
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration < double > diff = end - start;
  cout << to_string(nStudentu) << " irasu grupavimo laikas: " << diff.count() << " s\n";
}

void Spausdinimas(int nStudentu,
  const vector < Irasas > & geresnioBalo,
    const vector < Irasas > & zemesnioBalo) {
  string zemesniuName = "ZemesnioBalo" + to_string(nStudentu) + ".txt";
  ofstream zemesn(zemesniuName);
  string geresniuName = "GeresnioBalo" + to_string(nStudentu) + ".txt";
  ofstream geresn(geresniuName);

  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  for (const auto & temp: zemesnioBalo) {
    zemesn << temp.vardas << " " << temp.pavarde << " " <<
      fixed << setprecision(2) << temp.galut << endl;
  }
  for (const auto & temp: geresnioBalo) {
    geresn << temp.vardas << " " << temp.pavarde << " " << fixed << setprecision(2) <<
      temp.galut << endl;
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration < double > diff = end - start;
  cout << to_string(nStudentu) << " irasu grupiu irasymo i failus laikas: " << diff.count() << " s\n";
  cout << "-------------------------------------------------------------------------" << endl;
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
