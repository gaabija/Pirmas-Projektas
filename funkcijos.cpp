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
  cout << "Iveskite failo studentu skaičių: "<<endl;
  int nStudentu;
  nStudentu= SkIvedimas();
 
  vector < Irasas > studentai;
  vector < Irasas > geresnioBalo;
  vector < Irasas > zemesnioBalo;

  list < Irasas > studentaiLIST;
  list < Irasas > geresnioBaloLIST;
  list < Irasas > zemesnioBaloLIST;

  cout << "Ar norite nuskaityti faila? 'n' Ar norite ji sugeneruoti? 'g' )  ";
  char ar;
  while (true) {
    cin >> ar;
    ar = tolower(ar);
    if (ar != 'n' && ar != 'g') {
      cout << "Iveskite n arba g raidę: ";
    } else break;
  }
  if (ar == 'g') {
    cout << "Iveskite studento pazymiu skaičių: " << endl;
    int nPazymiu;
    nPazymiu = SkIvedimas();

      DuomenuGeneravimas(nStudentu, nPazymiu);
     FailoDuomenuGavimasVector(studentai, nStudentu);
     SkaiciavimasVector(nStudentu, studentai, budasIsvesti);
      GrupavimasVector(nStudentu, studentai, geresnioBalo, zemesnioBalo);
      SpausdinimasVector(nStudentu, geresnioBalo, zemesnioBalo);

      FailoDuomenuGavimasList(studentaiLIST, nStudentu);
      SkaiciavimasList(nStudentu, studentaiLIST, budasIsvesti);
      GrupavimasList(nStudentu, studentaiLIST, geresnioBaloLIST, zemesnioBaloLIST);
      SpausdinimasList(nStudentu, geresnioBaloLIST, zemesnioBaloLIST);

      studentaiLIST.clear();
      geresnioBaloLIST.clear();
      zemesnioBaloLIST.clear();
      studentai.clear();
      geresnioBalo.clear();
      zemesnioBalo.clear();
      cout << endl;
    
  } else if (ar == 'n') {
   
      FailoDuomenuGavimasVector(studentai, nStudentu);
     SkaiciavimasVector(nStudentu, studentai, budasIsvesti);
      GrupavimasVector(nStudentu, studentai, geresnioBalo, zemesnioBalo);
      SpausdinimasVector(nStudentu, geresnioBalo, zemesnioBalo);

      FailoDuomenuGavimasList(studentaiLIST, nStudentu);
      SkaiciavimasList(nStudentu, studentaiLIST, budasIsvesti);
      GrupavimasList(nStudentu, studentaiLIST, geresnioBaloLIST, zemesnioBaloLIST);
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

void FailoDuomenuGavimasList(list < Irasas > & studentai, int nStudentu) {
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
    while (fd >> pazymys) {
      studentas.pazymiai.push_back(pazymys);
    }
    studentas.egzas = studentas.pazymiai.back();
    studentas.pazymiai.pop_back();

    studentai.push_back(studentas);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration < double > diff = end - start;
  cout << to_string(nStudentu) << " irasu nuskaitymo laikas i List: " << diff.count() << " s\n";

}
void SkaiciavimasVector(int nStudentu, vector < Irasas > & studentai, char budasIsvesti){
  vector < Irasas > ::iterator it;
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
}
void SkaiciavimasList(int nStudentu, list < Irasas > & studentai,char budasIsvesti){
  list < Irasas > ::iterator it;
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
}
void GrupavimasList(int nStudentu, list < Irasas > & studentai,
  list < Irasas > & geresnioBalo, list < Irasas > & zemesnioBalo) {
  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  list < Irasas > ::iterator it;
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
  geresnioBalo.sort([](const Irasas & f,
    const Irasas & s) {
    return f.vardas < s.vardas;
  });
  zemesnioBalo.sort([](const Irasas & f,
    const Irasas & s) {
    return f.vardas < s.vardas;
  });

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

void FailoDuomenuGavimasVector(vector < Irasas > & studentai, int nStudentu) {
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
    while (fd >> pazymys) {
      studentas.pazymiai.push_back(pazymys);
    }
    studentas.egzas = studentas.pazymiai.back();
    studentas.pazymiai.pop_back();

    studentai.push_back(studentas);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration < double > diff = end - start;
  cout << to_string(nStudentu) << " irasu nuskaitymo laikas i Vector: " << diff.count() << " s\n";

}

void GrupavimasVector(int nStudentu, vector < Irasas > & studentai,
  vector < Irasas > & geresnioBalo, vector < Irasas > & zemesnioBalo) {

  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  vector < Irasas > ::iterator it;
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
  sort(zemesnioBalo.begin(), zemesnioBalo.end(), Lyginimas);
  sort(geresnioBalo.begin(), geresnioBalo.end(), Lyginimas);

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
