# 3 užduotis. „Naujų tipų kūrimas ir jų naudojimas“
[2 Užduoties](https://github.com/gabijabalionyt/2-uzduotis) tęsinys. Objektinis programavimas

## [V1.1](https://github.com/gabijabalionyt/3-uzduotis/releases/tag/V1.1)

Pirmoje trečiosios užduoties versijoje **struct Student** buvo pakeista į **class Student.**
```ruby
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
   |Flag| 1000 |  10000 |  100000 | 1000000  |      10000000      |  Suma |
   |----|-----:|:------:|:-------:|:--------:|:------------------:|------:|
   | O1 |28 ms | 304  ms| 3205 ms | 5657 ms  | neuzteko atminties |9,194 s|
   | O2 |28 ms | 287  ms| 3203 ms | 6029 ms  | neuzteko atminties |9,547 s|
   | O3 |28 ms | 292  ms| 3307 ms | 5713 ms  | neuzteko atminties |9,340 s|

 |                 |O1 | O2| O3|
 |-----------------|--:|:-:|--:|
 |V1.1.exe dydis KB|892|894|900|
 
 
 
 
## [V1.2]()

Antroje užduoties versijoje paprašyta realizuoti `Class Student` reikiamus ir tinkančius (turinčius prasmę) operatorius.Kadangi programoje nedirbama su dinamine atmintimi, nei *"Rule of 5"*, nei *"Rule of 3"* nebuvo realizuotos.

Realizuoti išvesties, įvesties bei lyginimo operatoriai `class Student` objektams lyginti. (Būtų galima palyginti ar vartotojas to paties studento neįvedė kelis kartus)

```ruby
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
```
Pačioje programoje naudotas įvesties operatorius studento duomenims - vardui, pavardei bei egzamino - iš tekstinio failo skaitymui.


```ruby
...
       while (std::getline(ReadFile, EntryLine))
            {
                std::istringstream ReadLine (EntryLine);
                ReadLine >> Stud;
...
            }
....
```
