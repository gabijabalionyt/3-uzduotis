# 3 užduotis. „Naujų tipų kūrimas ir jų naudojimas“
[2 Užduoties](https://github.com/gabijabalionyt/2-uzduotis) tęsinys. Objektinis programavimas

## [V1.1](https://github.com/gabijabalionyt/3-uzduotis/releases/tag/V1.1)

Pirmoje trečiosios užduoties versijoje **struct Student** buvo pakeista į **class Student.**
```
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

```
Studentai šioje versijoje skirstomi pagal 1-ąją strategiją: kiekvienas studentas yra ir pagrindiniame std::vector<Student> Students konteineryje, ir viename iš suskaidytų konteinerių (std::vector<Student> FailedStudents arba std::vector<Student> PassedStudents), nes šią strategiją implementavus antrojoje užduotyje V1 versijoje, studentai būdavo suskirstyti ir įrašyti į failus greičiau.
  
 ### **Duomenų skirstymo ir spausdinimo spartos analizė**
 *(Duomenys su didžiausiu duomenų failu nėra pateikiami, nes kompiuteryje trūksta atminties jiems apdroti)*
 
  **Naudojant Struct Student**
 | 1000 |  10000 |  100000 | 1000000  |  10000000 |
 |-----:|:------:|:-------:|:--------:|----------:|
 |24 ms | 219  ms| 2508 ms | 24191 ms |492473  ms |
 
 Iš viso *(neskaitant paskutinio)* **26.942** s;
  
  **Naudojant Class Student**
   | 1000 |  10000 |  100000 | 1000000  |      10000000      |
   |-----:|:------:|:-------:|:--------:|-------------------:|
   |40 ms | 398  ms| 5004 ms | 43914 ms | neuzteko atminties |
   
  Iš viso *(neskaitant paskutinio)* **49.356** s;
  
  Taigi, naudojant **Class Student** skirstymas ir spausdinimas užtruko šiek tiek ilgiau. Jis buna apie 2 kartus ilgesnis, bet failui didėjant tas skirtumas mažėja. Palyginus 100000 koeficientą gauname 1,995, o lyginant 1000000  koeficientas mažesnis - 1,815.
  **Spartos analizė naudojant Flag'us O1, O2, O3**
   |Flag| 1000 |  10000 |  100000 | 1000000  |      10000000      |  Suma  |
   |----|-----:|:------:|:-------:|:--------:|:------------------:|-------:|
   | O1 |38 ms | 415  ms| 4288 ms | 44562 ms | neuzteko atminties |49,303 s|
   | O2 |40 ms | 398  ms| 5122 ms | 47392 ms | neuzteko atminties |52,952 s|
   | O3 |38 ms | 401  ms| 4923 ms | 45493 ms | neuzteko atminties |50,855 s|
