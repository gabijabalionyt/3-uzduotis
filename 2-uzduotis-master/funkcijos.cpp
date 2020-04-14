#include "biblioteka.h"

double Vidurkis (vector<int> Grade, int n)
{
    int Sum = 0;

    for (int i = 0; i < n; i++)
        Sum += Grade[i];

    return 1.0*Sum/n;
}
double Mediana (vector<int> Grade, int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (Grade[j] < Grade[i])
                swap (Grade[j], Grade[i]);

    if (n%2 == 0)
        return 1.0*(Grade[n/2] + Grade[n/2-1])/2;
    else
        return 1.0*Grade[n/2];
}
//-----------------------------

bool AllLetters (string Input)  //patikrina ar visur raides
{
    for (int i = 0; i < Input.length(); i++)
    {
        int UppercaseCharacter = toupper(Input[i]); //Kad nereiketu tikrint ar didziosios ar mazosios

        if (UppercaseCharacter < 'A' || UppercaseCharacter > 'Z')
        {
            if (UppercaseCharacter != 32)
                return false;
        }
    }
    return true;
}
//-----------------------------

bool Digits (const string & str)    //patikrina ar skaiciai
{
    return all_of (str.begin(), str.end(), ::isdigit);
}
///-----------
void Conversion (string & Text) //pavercia string tezta i Aaaa  tipa
{
    if (islower(Text.at(0)))
        Text.at(0) = toupper (Text.at(0));

    for (int i = 1; i < Text.length(); i++)
        if (isupper(Text.at(i)))
            Text.at(i) = tolower (Text.at(i));
}

///-----------------------------
void NewLine () //kad palengvintu rasyma visur
{
    cout << endl;
}

void Rikiavimas (vector <Student> &S)
{
    for(int i=0; i<S.size()-1; i++)
        for (int j=i;j<S.size();j++)
        if (S[i].vardas>S[j].vardas)
        swap (S[i], S[j]);

}

void rezultatu_skaidymas(vector<Student> &S, vector<Student> &silpni, vector<Student> &kieti)
 {

            auto Start = std::chrono::high_resolution_clock::now();

    for (int j=0; j<5; j++)
    {
        for (int i=0; i<S.size(); i++)
        {

            if (S[i].gv>=5 or S[i].gm>=5) {
               kieti.push_back(S[i]);
            }

            if (S[i].gv<5 or S[i].gm<5) {
                silpni.push_back(S[i]);
            }
        }

    }
  auto End = std::chrono::high_resolution_clock::now();
cout << "Duomenu isskaidymas i dvi dalis uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() << " ms."<< endl;

    S.clear();
}
//------------------------
void rasymas ( vector<Student> silpni, vector<Student> kieti, int Value )
{  auto Start = std::chrono::high_resolution_clock::now();

    string file_name[2] = {"Protingi" + std::to_string(Value) + ".txt", "Kvaili."+ std::to_string(Value) + ".txt"};

    std::ofstream outfile(file_name[0]);
    std::ofstream outfil(file_name[1]);

    for (int i=0; i<kieti.size(); i++)
    {
        outfile << kieti[i].pavarde << " " << kieti[i].vardas << " " << std::fixed << std::setprecision(2) << kieti[i].gv << " " << std::fixed << std::setprecision(2)<< kieti[i].gm << endl;
    }

    kieti.clear();

    for (int i=0; i<silpni.size(); i++)
    {
        outfil << silpni[i].pavarde << " " << silpni[i].vardas << " " << std::fixed << std::setprecision(2) << silpni[i].gv<< " "  << std::fixed << std::setprecision(2)<< silpni[i].gm << endl;
    }

    silpni.clear();

    outfile.close();
    outfil.close();
auto End = std::chrono::high_resolution_clock::now();
            cout << "Duomenu isspausdinimas i du failus uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() << " ms."<< endl;

}
void rasymas ( vector<Student> silpni, vector<Student> kieti)
{  auto Start = std::chrono::high_resolution_clock::now();

    string file_name[2] = {"Protingi.txt", "Kvaili.txt" };

    std::ofstream outfile(file_name[0]);
    std::ofstream outfil(file_name[1]);

    for (int i=0; i<kieti.size(); i++)
    {
        outfile << kieti[i].pavarde << " " << kieti[i].vardas << " " << std::fixed << std::setprecision(2) << kieti[i].gv << " " << std::fixed << std::setprecision(2)<< kieti[i].gm << endl;
    }

    kieti.clear();

    for (int i=0; i<silpni.size(); i++)
    {
        outfil << silpni[i].pavarde << " " << silpni[i].vardas << " " << std::fixed << std::setprecision(2) << silpni[i].gv<< " "  << std::fixed << std::setprecision(2)<< silpni[i].gm << endl;
    }

    silpni.clear();

    outfile.close();
    outfil.close();
auto End = std::chrono::high_resolution_clock::now();
            cout << "Duomenu isspausdinimas i du failus uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() << " ms."<< endl;

}

void versija1 (vector <Student> &S ,vector <Student> &silpni, vector <Student> &kieti )
{
    {
        int vari;
        string Entry;
        int Nr =-1;
        NewLine();
        string var,pav;
        cout << "Kaip norite apskaiciuoti studento galutini pazymi?\nSpauskite 1, jei norite, jog butu naudojamas studento rezultatu vidurkis,\n2, jei norite, jog butu naudojama mediana." << endl;

        while (true)
        {
            cin >> Entry;

            if (Entry == "1")
            {
                vari = 1;
                break;
            }
            else if (Entry == "2")
            {
                vari = 2;
                break;
            }
            else
                cout << Error << endl;
        }
        cin.ignore();

        while (true)
        {

            NewLine();
            cout << "Iveskite " << Nr + 2 << "-o studento varda bei pavarde, pavyzdziui, Vardenis Pavardenis, baige paspauskite Enter" << endl;
            getline (cin, Entry);

            if(!Entry.empty())
            {
                int Position = Entry.find(" "); //atskiriam varda nuo pavardes

                if(Entry.length()-1 > Position && AllLetters(Entry) == true)
                {
                    S.push_back(Student());
                    Nr++;
                    S[Nr].vardas = Entry.substr(0, Position);
                    Conversion (S[Nr].vardas);
                    S[Nr].pavarde = Entry.substr(Position+1);
                    Conversion(S[Nr].pavarde);
                    NewLine();

                    cout << "Kokiu formatu bus pateikiami studento namu darbu rezultatai?\nSpauskite 1, jei rezultatus ivesite Jus,\n2, jei norite, jog duomenys butu sugeneruoti atsitiktinai." << endl;

                    int Kiekis = 0;
                    vector <int> Pazymiai;

                    while(true)
                    {
                        cin >> Entry;

                        if (Entry == "1")
                        {
                            NewLine();
                            cout << "Veskite skaièius nuo 1-o iki 10-ies, norëdami baigti vedimà áveskite bet koká kità skaièiø." << endl;
                            while (true)
                            {
                                cin >> Entry;

                                if (Digits(Entry) == true)
                                {
                                    int Pazymys = stoi(Entry);

                                    if (Pazymys > 0 && Pazymys < 11)
                                    {
                                        Pazymiai.push_back(int());
                                        Pazymiai[Kiekis] = Pazymys;
                                        Kiekis++;
                                    }

                                    else
                                    {
                                        if (Kiekis != 0)
                                            break;
                                        else
                                            cout << "Iveskite skaiciu." << endl;
                                    }
                                }
                                else
                                    cout << Error << endl;
                            }
                            break;
                        }

                        if (Entry == "2")
                        {

                            NewLine();
                            cout << "Kiek skaiciu generuoti?" << endl;
                            while (true)
                            {
                                cin >> Entry;

                                if (Digits(Entry) == true)
                                {
                                    int Pazymys = stoi(Entry);

                                    if (Pazymys > 0)
                                    {
                                        for (int i = 0; i < Pazymys; i++)
                                        {
                                            Pazymiai.push_back(int());
                                            Pazymiai[Kiekis] = int(round(1+1.0*rand()/RAND_MAX*10));
                                            Kiekis++;
                                        }
                                        break;
                                    }
                                    else
                                    {
                                        if (Kiekis != 0)
                                            break;
                                        else
                                            cout << "Truksta duomenu." << endl;
                                    }
                                }
                                else
                                    cout << Error << endl;
                            }
                            break;
                        }

                        else
                        {
                            cin.ignore();
                            cin.clear();
                            cout << Error << endl;
                        }
                    }
                    NewLine();
                    cout << "Iveskite studento egzamino rezultata:" << endl;
                    int Exam;

                    while (true)
                    {
                        string EntryString;
                        cin >> EntryString;
                        int    Entry;

                        if (Digits(EntryString) == false)
                            Entry = -1;
                        else
                            Entry = stoi(EntryString);

                        if (Entry < 0 || Entry > 10)
                            cout << Error << endl;
                        else
                        {
                            Exam = Entry;
                            break;
                        }
                    }
                    double Av;

                    if (vari == 1)
                        Av = Vidurkis(Pazymiai, Kiekis);
                    else
                        Av = Mediana(Pazymiai, Kiekis);

                    S[Nr].gv = 1.0*(0.4*Av+0.6*Exam);
                    cin.ignore();
                    cin.clear();
                }
                else
                    cout << Error << endl;
            }

            else
            {
                if (Nr == -1)
                    cout << "Iveskite bent vieno studento duomenis." <<  endl;
else break;
            }
        }
        Rikiavimas(S);
        rezultatu_skaidymas(S, silpni, kieti);
        rasymas(silpni, kieti);
    }
}




void versija2 (vector <Student> &S ,vector <Student> &silpni, vector <Student> &kieti )

{
    {
        string  EntryLine,
                Var,
                Pav, Entry;
        int  Nr = -1;
        auto Start = std::chrono::high_resolution_clock::now();
        ifstream ReadFile ("kursiokai.txt");
         try
        {
            if (!ReadFile.good())
                throw "Toks failas neegzistuoja.";
        }
        catch(const char *Message)
        {
            cout << Message << endl;
        }
        {
            while (getline (ReadFile, EntryLine))
            {
                S.push_back(Student());
                istringstream ReadLine(EntryLine);
                ReadLine >> Var >> Pav;

                //if (AllLetters(Var) && AllLetters(Pav))
                {
                    Nr++;
                    S[Nr].vardas = Var;
                    S[Nr].pavarde = Pav;
                    Conversion (S[Nr].vardas);
                    Conversion (S[Nr].pavarde);

                    int Kiekis = 0;
                    vector <int> Pazymiai;

                    while (ReadLine >> Entry)
                    {
                        if (Digits(Entry))
                        {
                            int Pazymys = stoi (Entry);

                            if (Pazymys > 0 && Pazymys <11)
                            {
                                Pazymiai.push_back(int());
                                Pazymiai[Kiekis] = Pazymys;
                                Kiekis++;
                            }
                        }
                    }
                    ReadLine.end;
                  int Exam = 0;

                    if (Kiekis > 0)
                    {
                        Exam = Pazymiai[Kiekis-1];
                        S[Nr].gv = 1.0*(0.4*Vidurkis(Pazymiai, Kiekis-1)+0.6*Exam);
                        S[Nr].gm = 1.0*(0.4*Mediana(Pazymiai, Kiekis-1)+0.6*Exam);
                    }

                    else
                        cout << Error << endl;
                }
            }auto End = std::chrono::high_resolution_clock::now();
cout << "Duomenu nuskaitymas is failo uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() << " ms."<< endl;


        }

        ReadFile.end;
    }
    Rikiavimas(S);
      rezultatu_skaidymas(S, silpni, kieti);
        rasymas(silpni, kieti);
}

//-----------------------------

int pasirinkimas ()
{
    int var;
    cout << "Ar norite duomenis suvesti pats( iveskite 1) ar norite, kad jie butu nuskaityti is failo (iveskite 2), ar norite generuoti 5 tekstinius failus (iveskite 3)" << endl;
label:
    cin >> var;

    while(cin.fail())      //jeigu ne int tipo
    {
        cout << "Klaida, turite ivesti 1 arba 2 arba 3" << std::endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> var;
    }
    if(var<1 or var>3)
    {
        cout << "Toks pasirinkimas negalimas, iveskite 1 arba 2 arba 3" << endl;
        goto label;
    }
    return var;
}
void versija3 (size_t Value)
{
    /*atsitiktinių skaičių generavimui*/
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution <int> Interval (1, 10), Amount(10, 20);

    int NumberOfStudents = Value,
        AmountOfResults = Amount(eng);

    std::ofstream Write;
    Write.open("File" + std::to_string(Value) + ".txt");

    for (size_t j = 1; j <= NumberOfStudents; j++)
    {
        Write << "Vardas" + std::to_string(j) << " Pavarde" + std::to_string(j) << " " << Interval(eng);   //egzamino pažymys įrašomas PRIEŠ namų darbų rezultatus

        vector <int> Results;
        vector <int>::iterator IT;

        for (size_t k = 0; k < AmountOfResults; k++)
            Results.push_back(Interval(eng));

        for (IT = Results.begin(); IT < Results.end(); IT++)
            Write << " " << *IT;

        Write << endl;
    }
    Write.close();
}





///-----------------
void versija3pro (vector <Student> S, vector <Student> silpni, vector <Student> kieti)
{
        for (size_t i = 10; i <= 100000; i *= 10)
        {
            S.clear();

            auto Start = std::chrono::high_resolution_clock::now();
            versija3(i);
            auto End = std::chrono::high_resolution_clock::now();
            cout << "File" + std::to_string(i) + ".txt generavimas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() << " ms."<< endl;
            {
        string  EntryLine,
                Var,
                Pav, Entry;
        int  Nr = -1;
        auto Start = std::chrono::high_resolution_clock::now();


        ifstream ReadFile ("File" + std::to_string(i) + ".txt");

         try
        {
            if (!ReadFile.good())
                throw "Toks failas neegzistuoja.";
        }
        catch(const char *Message)
        {
            cout << Message << endl;
        }
        {
            while (getline (ReadFile, EntryLine))
            {
                S.push_back(Student());
                istringstream ReadLine(EntryLine);
                ReadLine >> Var >> Pav;

                //if (AllLetters(Var) && AllLetters(Pav))
                {
                    Nr++;
                    S[Nr].vardas = Var;
                    S[Nr].pavarde = Pav;
                    Conversion (S[Nr].vardas);
                    Conversion (S[Nr].pavarde);

                    int Kiekis = 0;
                    vector <int> Pazymiai;

                    while (ReadLine >> Entry)
                    {
                        if (Digits(Entry))
                        {
                            int Pazymys = stoi (Entry);

                            if (Pazymys > 0 && Pazymys <11)
                            {
                                Pazymiai.push_back(int());
                                Pazymiai[Kiekis] = Pazymys;
                                Kiekis++;
                            }
                        }
                    }
                    ReadLine.end;

                    int Exam = 0;

                    if (Kiekis > 0)
                    {
                        Exam = Pazymiai[Kiekis-1];
                        S[Nr].gv = 1.0*(0.4*Vidurkis(Pazymiai, Kiekis-1)+0.6*Exam);
                        S[Nr].gm = 1.0*(0.4*Mediana(Pazymiai, Kiekis-1)+0.6*Exam);
                    }

                    else
                        cout << Error << endl;
                }
            }
            auto End = std::chrono::high_resolution_clock::now();
            cout << "File" + std::to_string(i) + ".txt nuskaitymas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() << " ms."<< endl;

        }

        ReadFile.end;
    }Rikiavimas(S);
      rezultatu_skaidymas(S, silpni, kieti);
        rasymas(silpni, kieti, i);
        NewLine();
        }
    }

