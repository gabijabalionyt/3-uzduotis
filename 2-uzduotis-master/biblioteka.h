#define pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stoi;
using std::getline;
using std::istringstream;
using std::swap;
using std::istream;
using std::streamsize;
using std::setprecision;
using std::max;
struct Student
{
    string vardas, pavarde;
    double gv,gm;   //galutinis pazymys su vidurkiu ir su mediana
};


const string Error = "Jusu ivesti duomenys neatitinka reikalavimu. Bandykite dar karta.";

double Vidurkis (vector<int> Grade, int n);
double Mediana (vector<int> Grade, int n);
bool AllLetters (string Input)  ;
bool Digits (const string & str) ;
void Conversion (string & Text);
void NewLine ();
void Rasymas (int Nr, vector<Student> S, int var);
void Rikiavimas (vector<Student> S, int Nr);
void versija1 (vector <Student> &,vector <Student> &silpni, vector <Student> &kieti );
void versija2 (vector <Student> &,vector <Student> &silpni, vector <Student> &kieti );
void versija3 (size_t Value);
void versija3pro (vector <Student> S, vector <Student> silpni, vector <Student> kieti) ;
void rasymas ( vector<Student> silpni, vector<Student> kieti, int Value );

int pasirinkimas ();
