#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H


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

ifstream fd("C:/Users/gabij/Desktop/kursiokai.txt");

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
#endif
