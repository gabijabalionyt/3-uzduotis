#include "biblioteka.h"


void Student::setStudent(std::string aName, std::string aSurname, std::string ExamScore)
{
    Name_ = aName;
    Surname_ = aSurname;
    Exam_ = std::stoi(ExamScore);
}
//---------------------------------

void Student::setHomework(int Score)
{
    Homework_.push_back(Score);
}
//---------------------------------

void Student::EmptyHomework()
{
    Homework_.clear();
}
//---------------------------------

double Student::FinalMark (int Exam, double HomeworkScore)
{
    return 0.4 * HomeworkScore + 0.6 * Exam;
}
//---------------------------------
double Student::FinalMark (int Exam, const std::vector<int> Homework)
{
    if (Homework_.size() == 0)
        throw std::domain_error("Studentas neatliko ne vieno namu darbo.");
    return FinalMark (Exam_, Average(Homework_));
}
//---------------------------------
double Student::FinalMark (double (*Criteria)(std::vector<int>))
{
    return FinalMark(Exam_, Criteria(Homework_));
}
//---------------------------------

double Average (std::vector<int> HomeworkScore)
{
    if (HomeworkScore.size() == 0)
        throw std::domain_error ("Skaiciavimo atlikti negalima. Iveskite duomenis.");

    return std::accumulate (HomeworkScore.begin(), HomeworkScore.end(), 0.0)/HomeworkScore.size();
}
//---------------------------------

double Median (std::vector<int> HomeworkScore)
{
    typedef std::vector <int>::size_type VecSize;
    VecSize size = HomeworkScore.size();

    if (size == 0)
        throw std::domain_error ("Skaiciavimo atlikti negalima. Iveskite duomenis.");

    sort (HomeworkScore.begin(), HomeworkScore.end());

    VecSize Middle = size / 2;

    if (size % 2 == 0)
        return (HomeworkScore[Middle-1] + HomeworkScore[Middle])/2;
    else
        return HomeworkScore[Middle];
}
//---------------------------------

bool CompareSurnames (const Student & x, const Student & y)
{
    return x.getSurname() < y.getSurname();
}
//---------------------------------

bool AllLetters (std::string Input)
{
    for (int i = 0; i < Input.length(); i++)
    {
        if (isalpha(Input[i]) == false)
            return false;
    }
    return true;
}
//----------------------------------

bool Digits (const std::string & str)
{
    return all_of (str.begin(), str.end(), ::isdigit);
}
//---------------------------------

void Conversion (std::string & Text)
{
    if (islower(Text.at(0)))
        Text.at(0) = toupper (Text.at(0));

    for (int i = 1; i < Text.length(); i++)
        if (isupper(Text.at(i)))
            Text.at(i) = tolower (Text.at(i));
}
//---------------------------------

void printTable (std::ostream & out, std::string::size_type x, std::string::size_type y)
{
    out << "Vardas" << std::string(x - 5, ' ')
        << "Pavarde" << std::string(y - 6, ' ') << "Galutinis pazymys" << std::endl;

    auto Spaces = x + y + 18;
    for (auto i = 0; i <= Spaces ; i++)
        out << "-";
    out << std::endl;
}
//---------------------------------

void printTableAverage (std::string::size_type x, std::string::size_type y)
{
    std::cout << "Vardas" << std::string(x - 5, ' ')
              << "Pavarde" << std::string(y - 6, ' ') << "Galutinis pazymys (vid.)" << std::endl;

    auto Spaces = x + y + 24;
    for (auto i = 0; i <= Spaces ; i++)
        std::cout << "-";
    std::cout << std::endl;
}
//---------------------------------

void printTableMedian (std::string::size_type x, std::string::size_type y)
{
    std::cout << "Vardas" << std::string(x - 5, ' ')
              << "Pavarde" << std::string(y - 6, ' ') << "Galutinis pazymys (med.)" << std::endl;

    auto Spaces = x + y + 24;
    for (auto i = 0; i <= Spaces ; i++)
        std::cout << "-";
    std::cout << std::endl;
}
//---------------------------------

void Print (std::ostream & out, std::vector<Student> Main, std::string::size_type x, std::string::size_type y)
{
    for (std::vector<Student>::iterator IT = Main.begin(); IT != Main.end(); IT++)
    {
        out << (*IT).getName() << std::string(x + 1 - (*IT).getName().size(), ' ');
        out << (*IT).getSurname() << std::string(y + 1 - (*IT).getSurname().size(), ' ');
        std::streamsize prec = std::cout.precision();
        out << std::fixed << std::setprecision(2) << (*IT).FinalMark(Average) << " "
            << (*IT).FinalMark(Median) << std::setprecision(prec) << std::endl;
    }
    for (auto i = 0; i != x + y + 10; i++)
        out << "-";
        out << std::endl;
}

//---------------------------------
void GenerateFiles (std::size_t i)
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution <int> Interval (1, 10), Amount(10, 20);

    int NumberOfStudents = i,
        AmountOfResults = Amount(eng);

    std::ofstream Write;
    Write.open("File" + std::to_string(i) + ".txt");

    for (size_t j = 1; j <= NumberOfStudents; j++)
    {
        Write << "Vardas" + std::to_string(j) << " Pavarde" + std::to_string(j) << " " << Interval(eng);   //egzamino paþymys áraðomas PRIEÐ namø darbø rezultatus

        std::vector <int> Results;
        std::vector <int>::iterator IT;

        for (size_t k = 0; k < AmountOfResults; k++)
            Results.push_back(Interval(eng));

        for (IT = Results.begin(); IT < Results.end(); IT++)
            Write << " " << *IT;

        Write << std::endl;
    }
    Write.close();
}
int Choice()
{ std::string Entry;
int EntryChoice;
std::cout << "Kaip norite gauti stendentu duomenis?\n Spauskite:"
"\n1, jeigu norite duomenis nuskaityti is failo 'kursiokai.txt',"
"\n2, jeigu norite duomenis ivesti pats/pati"
"\n3, jeigu norite skaityti duomenis is sugeneruotu failu" << std::endl;

    while (std::cin >> Entry)
    {
        if (Entry == "1")
        {
            EntryChoice = 1;
            break;
        }
        else if (Entry == "2")
        {
            EntryChoice = 2;
            break;
        }
        else if (Entry == "3")
        {
            EntryChoice = 3;
            break;
        }
        else
            std::cout << Error << std::endl;
    }std::cin.ignore();
    return EntryChoice;
}
