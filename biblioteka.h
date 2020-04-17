#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>

const std::string Error = "Duomenys neatitinka reikalavimu. Bandukite dar karta.";

class Student
{
    private:
        std::string Name_;
        std::string Surname_;
        std::vector<int> Homework_;
        int Exam_;
    public:
        Student() : Homework_(0) { };
        void setStudent(std::string, std::string, std::string);
        void setHomework(int);
        void EmptyHomework();
        std::string getName() const { return Name_; }
        std::string getSurname() const { return Surname_; }
        int getExam() const { return Exam_; }
        int getSize() const { return Homework_.size(); }
        double FinalMark (int, double );
        double FinalMark (int, const std::vector<int>);
        double FinalMark (double (*) (std::vector<int>));
};

double Average (std::vector<int>);
double Median (std::vector<int>);
bool CompareSurnames (const Student&, const Student&);
bool AllLetters (std::string);
bool Digits (const std::string&);
void Conversion (std::string&);
void printTable (std::ostream&, std::string::size_type, std::string::size_type);
void printTableAverage (std::string::size_type, std::string::size_type);
void printTableMedian (std::string::size_type, std::string::size_type);
void Print (std::ostream&, std::vector<Student>, std::string::size_type, std::string::size_type);
void GenerateFiles (std::size_t);
int Choice();
#endif
