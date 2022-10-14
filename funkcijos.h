#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>

#include <string>

#include <iomanip>

#include <algorithm>

#include <fstream>

#include <chrono>

#include <vector>

#include <numeric>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::sort;
using std::vector;
using std::accumulate;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::to_string;
using std::fixed;
using std::numeric_limits;
using std::streamsize;

struct Irasas {
  string vardas;
  string pavarde;
  vector < int > pazymiai;
  int egzas;
  double galut;
};

int SkIvedimas();
void FailoGeneravimas();
void Duomenys(vector < Irasas > studentai);
void Duomenys(vector < Irasas > studentai);
void NaudotojoSuvedimas(Irasas & temp);
void RandomSuvedimas(Irasas & temp);
void NefailoDuomenuGavimas(Irasas & temp);
void Spausdinimas(Irasas temp);
bool Lyginimas(Irasas & a, Irasas & b);
double Vidurkis(Irasas temp);
double Mediana(Irasas temp);
void Galutinis(Irasas & temp, char budasIsvesti);
void DuomenuGeneravimas(int & nStudentu, int & nPazymiu);
void FailoDuomenuGavimas(vector < Irasas > & studentai, int nStudentu, int nPazymiu);
void Grupavimas(int nStudentu, vector < Irasas > & studentai,
  vector < Irasas > & geresnioBalo, vector < Irasas > & zemesnioBalo, char budasIsvesti);
void Spausdinimas(int nStudentu,
   vector < Irasas > & geresnioBalo,
     vector < Irasas > & zemesnioBalo);
#endif
