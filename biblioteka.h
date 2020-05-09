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

class Person
{
    protected:
        std::string Name_;
        std::string Surname_;
        Person (std::string aName = " ", std::string aSurname = " ") : Name_{aName}, Surname_{aSurname} { }
    public:
        virtual std::string getName() const { return Name_; }
        virtual  std::string getSurname() const { return Surname_; }
        virtual ~Person () = 0;
};

class Student : public Person
{
    private:
        int Exam_;
        std::vector<int> Homework_;
    public:
        Student (std::string aName = " ", std::string aSurname = " ", int ExamScore = 0) : Person{aName, aSurname}, Exam_{ExamScore} { }
        void setHomework(int);
        int getSize() const { return Homework_.size(); }
        void EmptyHomework();
        double FinalMark (int, double );
        double FinalMark (int, const std::vector<int>);
        double FinalMark (double (*) (std::vector<int>));
        friend std::ostream& operator << (std::ostream& out, Student& s)
        {
            out << s.Name_ << " " << s.Surname_ << " " << s.Exam_ << "\n";
            return out;
        }
        friend std::istream& operator >> (std::istream& in, Student & s)
        {
            in >> s.Name_ >> s.Surname_ >> s.Exam_;
            return in;
        }
        bool operator == (const Student & s)
        {
            return (Name_ == s.getName() && Surname_ == s.getSurname());
        }
        bool operator != (const Student & s)
        {
            return !(*this == s);
        }
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
