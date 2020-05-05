#include "biblioteka.h"

int main()
{
    std::vector<Student> Students;
    Student Stud;
    std::string Entry;
    int EntryChoice;
   std::string::size_type LongestName = 15,
                           LongestSurname = 15;
  EntryChoice=Choice();


    if (EntryChoice == 1)
    {
       std::string  EntryLine;
        std::ifstream ReadFile ("kursiokai.txt");

        try
        {
            if (!ReadFile.good() || ReadFile.peek() == std::ifstream::traits_type::eof())
                throw "Toks failas neegzistuoja arba yra tuscias.";
        }
        catch(const char *Message)
        {
            std::cout << Message << std::endl;
        }
        std::cout << std::endl;
 while (std::getline(ReadFile, EntryLine))
        {
            std::istringstream ReadLine (EntryLine);
            ReadLine >> Stud;

                if (ReadLine)
                {
                    Stud.EmptyHomework();
                    while (ReadLine >> Entry)
                    {
                        if (Digits(Entry))
                        {
                            int Mark = stoi(Entry);

                            if (Mark > 0 &&  Mark < 11)
                                Stud.setHomework(Mark);
                        }
                    }
                    Students.push_back(Stud);
                    ReadLine.clear();
                }
                ReadLine.end;

            ReadFile.clear();
        }
        ReadFile.end;

        std::sort(Students.begin(), Students.end(), CompareSurnames);
        if (Students.size() != 0)
        {
            printTable(std::cout, LongestName, LongestSurname);
            Print(std::cout, Students, LongestName, LongestSurname);
        }
    }

    else if (EntryChoice == 2)
    {
        LongestName = 6;
        LongestSurname = 7;
        std::cout << "\nKKaip norite apskaiciuoti studentu galutini pazimi?\nSpauskite:"
                     "\n1, jei norite, jog butu naudojamas studento namu darbu rezultatu vidurkis,"
                     "\n2, jei norite, jog butu naudojama mediana. " << std::endl;
        int FMChoice;

        while (std::cin >> Entry)
        {
            if (Entry == "1")
            {
                FMChoice = 1;
                break;
            }
            else if (Entry == "2")
            {
                FMChoice = 2;
                break;
            }
            else
                std::cout << Error << std::endl;
        }
        std::cin.ignore();

        while (true)
        {
            std::cout << "\nIveskite " << Students.size() + 1 << " studento varda, pavarde bei egzamino rezultata"
                         "\nnuo 1 iki 10. Baige paspauskite 'ENTER'." << std::endl;
            std::getline(std::cin, Entry);

            if(!Entry.empty())
            {
                std::string aName,
                            aSurname,
                            ExamScore;
                std::istringstream ReadLine (Entry);
                ReadLine >> aName >> aSurname >> ExamScore;

                if(AllLetters(aName) && AllLetters(aSurname) && Digits(ExamScore) && std::stoi(ExamScore) > 0 && std::stoi(ExamScore) < 11)
                {
                    Conversion(aName);
                    Conversion(aSurname);
                    LongestName = std::max(LongestName, aName.length());
                    LongestSurname = std::max(LongestSurname, aSurname.length());
                    Stud.setStudent(aName, aSurname, ExamScore);

                    std::cout << "\nKokiu formatu bus pateikiami studento namu darbu rezultatai?\nSpauskite:"
                                 "\n1, jei rezultatus ivesti Jus,"
                                 "\n2, jei norite, jog duomenys butu sugeneruoti atsitiktinai." << std::endl;

                    while(std::cin >> Entry)
                    {
                        if (Entry == "1")
                        {
                            Stud.EmptyHomework();
                            std::cout << "\nVeskite skaicius nuo 1-o iki 10-ies."
                                         "\nNoredami baigti vedima, iveskite bet koki kita skaiciu." << std::endl;
                            while (std::cin >> Entry)
                            {
                                if (Digits(Entry) == true)
                                {
                                    int Mark = std::stoi(Entry);

                                    if (Mark > 0 && Mark < 11)
                                        Stud.setHomework(Mark);
                                    else
                                    {
                                        if (Stud.getSize() != 0)
                                            break;
                                        else
                                            std::cout << "Iveskite skaiciu." << std::endl;
                                    }
                                }
                                else
                                    std::cout << Error << std::endl;
                            }
                            break;
                        }
                        else if (Entry == "2")
                        {
                            Stud.EmptyHomework();
                            std::cout << "\nKiek skaiciu generuoti?" << std::endl;

                            while (std::cin >> Entry)
                            {
                                if (Digits(Entry) == true)
                                {
                                    int Mark = std::stoi(Entry);
                                    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
                                    std::default_random_engine eng(seed);
                                    std::uniform_int_distribution <int> dist (1, 10);

                                    if (Mark > 0)
                                    {
                                        for (int i = 0; i < Mark; i++)
                                            Stud.setHomework(dist(eng));
                                        break;
                                    }
                                    else
                                    {
                                        if (Stud.getSize() != 0)
                                            break;
                                        else
                                            std::cout << "Truksta duomenu." << std::endl;
                                    }
                                }
                                else
                                    std::cout << Error << std::endl;
                            }
                            break;
                        }
                        else
                        {
                            std::cin.ignore();
                            std::cin.clear();
                            std::cout << Error << std::endl;
                        }
                    }
                    Students.push_back(Stud);

                    std::sort (Students.begin(), Students.end(), CompareSurnames);

                    std::cin.ignore();
                    std::cin.clear();
                }
                else
                    std::cout << Error << std::endl;
            }
            else
            {
                if (Students.size() == 0)
                    std::cout << "Iveskite bent vieno studento duomenis." <<  std::endl;
                else
                {
                    if (FMChoice == 1)
                        printTableAverage(LongestName, LongestSurname);
                    else
                        printTableMedian (LongestName, LongestSurname);

                    for (std::vector<Student>::iterator IT = Students.begin(); IT != Students.end(); IT++)
                    {
                        std::cout << (*IT).getName() << std::string(LongestName + 1 - (*IT).getName().size(), ' ');
                        std::cout << (*IT).getSurname() << std::string(LongestSurname + 1 - (*IT).getSurname().size(), ' ');

                        std::streamsize prec = std::cout.precision();
                        if (FMChoice == 1)
                            std::cout << std::fixed << std::setprecision(2) << (*IT).FinalMark(Average) << std::setprecision(prec) << std::endl;
                        else
                            std::cout << std::fixed << std::setprecision(2) << (*IT).FinalMark(Median) << std::setprecision(prec) << std::endl;
                    }
                    break;
                }
            }
        }
    }

    else if (EntryChoice == 3)
    {
        int a;
        std::cout << "Jeigu norite naudoti jau sugeneruotus failus spauskite 1, bet jei norite generuoti is naujo spauskite 0\n";
     label: std::cin >> a;
     if (a==0) for (std::size_t i = 1000; i != 10000000; i *= 10)
        {
            Students.clear();
            GenerateFiles(i);}
            else if (a!=0 and a!=1) {std::cout << Error; goto label;}
        for (std::size_t i = 1000; i != 10000000; i *= 10)
        {

            std::string EntryLine;
            std::ifstream ReadFile ("File" + std::to_string(i) + ".txt");

            try
            {
                if (!ReadFile.good() || ReadFile.peek() == std::ifstream::traits_type::eof())
                    throw "Toks failas neegzistuoja arba yra tuscias.";
            }
            catch(const char *Message)
            {
                std::cout << Message << std::endl;
            }

       while (std::getline(ReadFile, EntryLine))
            {
                std::istringstream ReadLine (EntryLine);
                ReadLine >> Stud;

                if (ReadLine)
                {
                    Stud.EmptyHomework();
                    while (ReadLine >> Entry)
                    {
                        if (Digits(Entry))
                        {
                            int Mark = stoi(Entry);

                            if (Mark > 0 &&  Mark < 11)
                                Stud.setHomework(Mark);
                        }
                    }
                    Students.push_back(Stud);
                    ReadLine.clear();
                }
                ReadLine.end;
                ReadFile.clear();
            }
            ReadFile.end;

            auto StartSorting = std::chrono::high_resolution_clock::now();

            std::vector<Student> FailedStudents, PassedStudents;
            std::vector<Student>::iterator IT = Students.begin();

            while (IT != Students.end())
            {
                if ((*IT).FinalMark(Average) < 5 && (*IT).FinalMark(Median) < 5)
                    FailedStudents.push_back(*IT);
                else
                    PassedStudents.push_back(*IT);
                IT++;
            }

            std::ofstream WriteToFailed;
            WriteToFailed.open("Failed.txt", std::ios::app);
            Print (WriteToFailed, FailedStudents, LongestName, LongestSurname);
            WriteToFailed.close();

            std::ofstream WriteToPassed;
            WriteToPassed.open("Passed.txt", std::ios::app);
            Print (WriteToPassed, PassedStudents, LongestName, LongestSurname);
            WriteToPassed.close();

            auto EndSorting = std::chrono::high_resolution_clock::now();
            std::cout << "Studentu skirstymas ir isvedimas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms."<< std::endl;
        }
    }
    return 0;
}

