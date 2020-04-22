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
 | 1000 |  10000 |  100000 | 1000000  |      10000000      |
 |-----:|:------:|:-------:|:--------:|-------------------:|
 |24 ms | 374  ms| 3413 ms | 30570 ms | neuzteko atminties |
 
 Iš viso *(neskaitant paskutinio)* **34.381** s;
  
  **Naudojant Class Student**
   | 1000 |  10000 |  100000 | 1000000  |      10000000      |
   |-----:|:------:|:-------:|:--------:|-------------------:|
   |20 ms | 328  ms| 3054 ms | 33249 ms | neuzteko atminties |
   
  Iš viso *(neskaitant paskutinio)* **36.651** s;
  
  Taigi, naudojant **Class Student** skirstymas ir spausdinimas užtruko šiek tiek ilgiau. Jis buna apie 2 kartus ilgesnis, bet failui didėjant tas skirtumas mažėja. Palyginus 100000 koeficientą gauname 1,995, o lyginant 1000000  koeficientas mažesnis - 1,815.
  **Spartos analizė naudojant Flag'us O1, O2, O3**
   |Flag| 1000 |  10000 |  100000 | 1000000  |      10000000      |  Suma  |
   |----|-----:|:------:|:-------:|:--------:|:------------------:|-------:|
   | O1 |28 ms | 244  ms| 1563 ms | 23014 ms | neuzteko atminties |24,847 s|
   | O2 |23 ms | 267  ms| 1751 ms | 21888 ms | neuzteko atminties |23,929 s|
   | O3 |30 ms | 206  ms| 1757 ms | 22604 ms | neuzteko atminties |24,597 s|

 |                |   O1    |   O2    |   O3    |
 |----------------|--------:|:-------:|--------:|
 |File1000.txt    |59 KB    |55 KB    |48 KB    |
 |File10000.txt   |561 KB   |479 KB   |499 KB   |
 |File100000.txt  |5,799 KB |5,603 KB |4,401 KB |
 |File1000000.txt |68,143 KB|59,939 KB|61,991 KB|
 |Suma            |74,542 KB|66,076 KB|66,939 KB|
 
 Taigi iš analizės matome, kad naudojant O2 flag'ą programa veikia greičiausiai, o generuojami failai užima mažiausiai vietos.
