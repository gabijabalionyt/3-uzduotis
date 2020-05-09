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
 
 
 
## [V1.2](https://github.com/gabijabalionyt/3-uzduotis/releases/tag/V1.2)

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
## [V1.5](https://github.com/gabijabalionyt/3-uzduotis/releases/tag/V1.5.1)

Trečioje šios užduoties versijoje klasė `class Student` buvo išskaidyta į dvi klases - `Class Person` (*Base klasė*) ir `Class Student` (*Derived klasė*)

```ruby

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

```
Sakykime, kas nors nori sukurti `Class Person` tipo objektą

``` 
Person P ("Gabija", "Balionytė")
```
Vartotojui sistema išmestų klaidą.

Kuriant `Class Student` problemų nekiltų:
```
Student Stud ("Gabija", "Balionytė",8);
std::cout << Stud;
```

Būtų išspausdinama:
**Gabija Balionytė 8**
