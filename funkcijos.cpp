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

void Pagalbine() {
  cout << "Iveskite kiek pazymiu kiekvienam studentui sugeneruoti: ";
  int nPazymiu;
  nPazymiu = SkIvedimas();
  cout << "Ar norite kad galutinis balas butu isvedamas pagal viduki? 'v' Ar norite kad butu isvedamas pagal mediana? 'm' )  ";
  char arVidurkis;
  char budasIsvesti;
  string name;
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

  //cout << "Iveskite norimo generuoti studentu skaičių: "<<endl;
  // int nStudentu;
  // nStudentu= SkIvedimas();
  int studentuSkaiciai[5] = {
    1000,
    10000,
    100000,
    1000000,
    10000000
  };

  vector < Irasas > studentai;
  vector < Irasas > geresnioBalo;
  vector < Irasas > zemesnioBalo;

  list < Irasas > studentaiLIST;
  list < Irasas > geresnioBaloLIST;
  list < Irasas > zemesnioBaloLIST;

  for (int i: studentuSkaiciai) {
    int nStudentu = i;
    DuomenuGeneravimas(nStudentu, nPazymiu);
    FailoDuomenuGavimasVector(studentai, nStudentu, nPazymiu);
    GrupavimasVector(nStudentu, studentai, geresnioBalo, zemesnioBalo, budasIsvesti);
    SpausdinimasVector(nStudentu, geresnioBalo, zemesnioBalo);

    FailoDuomenuGavimasList(studentaiLIST, nStudentu, nPazymiu);
    GrupavimasList(nStudentu, studentaiLIST, geresnioBaloLIST, zemesnioBaloLIST, budasIsvesti);
    SpausdinimasList(nStudentu, geresnioBaloLIST, zemesnioBaloLIST);
    studentaiLIST.clear();
    geresnioBaloLIST.clear();
    zemesnioBaloLIST.clear();
    studentai.clear();
    geresnioBalo.clear();
    zemesnioBalo.clear();
    cout << endl;
  }
}

void FailoDuomenuGavimasList(list < Irasas > & studentai, int nStudentu, int nPazymiu) {
  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  string name = "Studentai" + to_string(nStudentu) + ".txt";

  ifstream fd;
  stringstream buffer;
  fd.open(name);
  buffer << fd.rdbuf();
  fd.close();
  string eil;

  while (getline(buffer, eil)) {
    Irasas studentas;
    stringstream fd(eil);
    fd >> studentas.vardas;
    fd >> studentas.pavarde;
    int pazymys;
    for (int i = 0; i < nPazymiu; i++) {
      fd >> pazymys;
      studentas.pazymiai.push_back(pazymys);
    }
    fd >> studentas.egzas;

    studentai.push_back(studentas);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration < double > diff = end - start;
  cout << to_string(nStudentu) << " irasu nuskaitymo laikas i List: " << diff.count() << " s\n";

}

void GrupavimasList(int nStudentu, list < Irasas > & studentai,
  list < Irasas > & geresnioBalo, list < Irasas > & zemesnioBalo, char budasIsvesti) {

  list < Irasas > ::iterator it;

  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;

  if (budasIsvesti == 'm') {
    for (it = studentai.begin(); it != studentai.end(); ++it) {
      it -> galut = Mediana( * it) * 0.4 +
        it -> egzas * 0.6;
    }
  } else if (budasIsvesti == 'v') {
    for (it = studentai.begin(); it != studentai.end(); ++it) {
      it -> galut = Vidurkis( * it) * 0.4 +
        it -> egzas * 0.6;
    }
  }

  for (it = studentai.begin(); it != studentai.end(); ++it) {
    if (it -> galut < 5.00) {
      Irasas zemesnis;
      zemesnis.vardas = it -> vardas;
      zemesnis.pavarde = it -> pavarde;
      zemesnis.galut = it -> galut;
      zemesnioBalo.push_back(zemesnis);

    } else {
      Irasas geresnis;
      geresnis.vardas = it -> vardas;
      geresnis.pavarde = it -> pavarde;
      geresnis.galut = it -> galut;
      geresnioBalo.push_back(geresnis);
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration < double > diff = end - start;
  cout << to_string(nStudentu) << " irasu grupavimo laikas su List: " << diff.count() << " s\n";
}

void SpausdinimasList(int nStudentu,
  list < Irasas > & geresnioBalo,
  list < Irasas > & zemesnioBalo) {

  string zemesniuName = "ZemesnioBalo" + to_string(nStudentu) + ".txt";
  ofstream zemesn(zemesniuName);
  string geresniuName = "GeresnioBalo" + to_string(nStudentu) + ".txt";
  ofstream geresn(geresniuName);

  for (Irasas zemesnis: zemesnioBalo) {
    zemesn << zemesnis.vardas << " " <<
      zemesnis.pavarde << " " << fixed << setprecision(2) <<
      zemesnis.galut << endl;
  }
  for (Irasas geresnis: geresnioBalo) {
    geresn << geresnis.vardas << " " <<
      geresnis.pavarde << " " << fixed << setprecision(2) <<
      geresnis.galut << endl;
  }
  zemesnioBalo.clear();
  geresnioBalo.clear();
}

void DuomenuGeneravimas(int & nStudentu, int & nPazymiu) {
  string name = "Studentai" + to_string(nStudentu) + ".txt";
  ofstream studFile(name);
  for (int i = 0; i < nStudentu; i++) {
    studFile << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
    for (int j = 0; j < nPazymiu + 1; j++) {
      studFile << rand() % 10 + 1 << " ";
    }
    studFile << endl;
  }

}

void FailoDuomenuGavimasVector(vector < Irasas > & studentai, int nStudentu, int nPazymiu) {
  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  int index = 0;
  ifstream fd;
  string name = "Studentai" + to_string(nStudentu) + ".txt";
  fd.open(name);

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
  cout << to_string(nStudentu) << " irasu nuskaitymo laikas i Vector: " << diff.count() << " s\n";
}

void GrupavimasVector(int nStudentu, vector < Irasas > & studentai,
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
  cout << to_string(nStudentu) << " irasu grupavimo laikas su Vector: " << diff.count() << " s\n";
}

void SpausdinimasVector(int nStudentu,
  vector < Irasas > & geresnioBalo,
  vector < Irasas > & zemesnioBalo) {
  string zemesniuName = "ZemesnioBalo" + to_string(nStudentu) + ".txt";
  ofstream zemesn(zemesniuName);
  string geresniuName = "GeresnioBalo" + to_string(nStudentu) + ".txt";
  ofstream geresn(geresniuName);
  sort(zemesnioBalo.begin(), zemesnioBalo.end(), Lyginimas);
  sort(geresnioBalo.begin(), geresnioBalo.end(), Lyginimas);
  for (Irasas temp: zemesnioBalo) {
    zemesn << temp.vardas << " " << temp.pavarde << " " <<
      fixed << setprecision(2) << temp.galut << endl;
  }
  for (Irasas temp: geresnioBalo) {
    geresn << temp.vardas << " " << temp.pavarde << " " << fixed << setprecision(2) <<
      temp.galut << endl;
  }
  zemesnioBalo.clear();
  geresnioBalo.clear();
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
