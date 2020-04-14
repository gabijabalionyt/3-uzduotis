# 2 uzduotis
## Programos tikslas
Programa nuskaito mokinio duomenis, paskaičiuoja galutinį studento pažymį naudojant vidurkį ir medianą.
Yra du versijos V0.1 [Releases]( https://github.com/gabijabalionyt/2-uzduotis/releases) vienas su vektoriais, kitas su dinaminiais masyvais, tačiau abu atlieka visiškai vienodą funkciją.
Nuo V0.2 versijos visi veiksmai yra atliekami tik su vektoriais bei atsiranda galimybė duomenis nuskaityti iš failo.
Nuo V0.4 yra galimybė generuoti atsitiktinius failus ir yra skaičiuojamas programos laikas.

## Įdiegimo ir naudojimosi instrukcija
• *Norinti gauti programą pirmiausia reikia parsisiųsti vieną iš jos versijų iš [Releases](https://github.com/gabijabalionyt/2-uzduotis/releases) *

• *Parsisiųsti ir įsidiegti C++ kompiliatorių (pvz. GCC)*

• *Atsidaryti terminalą ir jame įvesti programos vietą diske*

• *Sukompiliuoti programą, pvz*

  *Jei naudojate GCC su GNU Make, įrašykite komandą make*
  *Jei naudojate GCC be GNU Make, įrašykite:*
  
  *g++ -c main.cpp funkcijos.cpp*

  *g++ -o main main.o funkcijos.o*

• *Programos naudojimasis bus paprastas, nes visi nurodymai bus parodomi ekrane.*

## Programos realizacija
## [Versija V0.1](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V0%2C1 )

Šią programos versiją prašyta realizuoti dviem būdais: naudojant C tipo masyvą bei std::vector tipo konteinerį. Šioje vesrsijoje nuskaitomi studentų duomenys: vardas ir pavardė, namų darbų rezultatai (vartotojas gali pasirinkti, ar už namų darbus gauti pažymiai bus sugeneruoti atsitiktinai, ar vartotojas juos įves pats/pati) bei egzamino pažymys dešimtbalėje sistemoje. Galutinis studento pažymys apskaičiuojamas naudojant studento namų darbų pažymių vidurkį ir medianą. Įvykdžius programą, vartotojui pateikiama lentelė, kurioje atspausdinamas studento vardas, pavardė bei galutinis pažymys.

## [Versija V0.2](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V0.2)

Šioje programos versijoje tęsiama programos realizacija, kurioje buvo naudojamas std::vector tipo konteineris. Vartotojas pasirenka kokius duomenis naudoti - įvestus paties/pačios ar nuskaitytus iš tekstinio duomenų failo pavadinimu kursiokai.txt.

Išvedant duomenis studentai išrikiuojami alfabetiškai pagal vardus.

## [Versija V0.3](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V0.3)

Programoje naudojamos funkcijos perkeltos į atskirą funkcijų failą pavadinimu **funkcijos.cpp**, o bibliotekos, funkcijų deklaracijos ir struktūra, kuri buvo naudojama ir ankstesnėse programos realizacijose, aprašyta **biblioteka.h** faile. Šioje versijoje kartą panaudojamas išimčių valdymas (angl. Exception Handling) try/catch - tikrinama, ar tekstinis duomenų failas *kursiokai.txt* egzistuoja.


***try
{
  if (!ReadFile.good())
      throw "Toks failas neegzistuoja."; 
}
catch (const char *Message)
{
      cout << Message << endl;
}***


Išvedant duomenis studentai rikiuojami alfabetiškai, tik šįkart pagal studentų pavardes.


## [Versija V0.4](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V04)

Šioje programos realizacijoje pridėta galimybė sugeneruoti penkis skirtingo dyžio failus, kuriuose studentų vardai ir pavardės pateikiami šabloniškai, o namų darbai bei jų kiekis sugeneruojami atsitiktinai. 


Studentai, kurių galutinis balas mažesnis nei 5.0, įrašomi į Protingi.txt failą, egzaminą išlaikiusieji (gavę 5.0 ar daugiau) - į Kvaili.txt.

Atlikus spartos analizę, gaunami į apačioje pateiktą pavyzdį panašūs reluztatai:

File10.txt generavimas užtruko 1 ms.

File10.txt nuskaitymas užtruko 1 ms.

Duomenu isskaidymas i dvi dalisuztruko: 7 ms.

Duomenu isspausdinimas i du failus uztruko: 25 ms.

...

## [Versija V0.5](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V05)
Šioje programos versijoje testuojami trys skirtingi konteineriai: 
 **std::vector \<Student>, std::deque\<Student> bei std::list\<Student>,**
 ir kokią įtaką jų pritaikymas daro programos veikimo spartai.
**Generavimo greitis:**
|Konteineris|1000  | 10000  | 100000 | 1000000  | 10000000 |
| --------- |:----:| :-----:|:------:|:--------:|---------:|
|Std::vector| 19 ms| 244 ms | 2660 ms| 25054 ms | 310421 ms|
|Std::Deque | 28 ms| 261 ms | 3101 ms| 29567 ms | 287850 ms|
|Std::list  | 25 ms| 257 ms | 3383 ms| 32487 ms | 281628 ms|

**Skirstymo ir spausdinimo greitis:**
|Konteineris| 1000  |10000    | 100000   |1000000      | 10000000   |
| --------- |:-----:| :------:|:--------:|:-----------:|-----------:|
|Std::vector| 165 ms| 13415 ms| 214515 ms| 3985024 ms  | 41862459 ms|
|Std::Deque | 80 ms | 6027 ms | 568355ms | 60781423 ms | 51472143 ms|
|Std::List  | 31 ms | 252 ms  | 2909 ms  | 29210ms     | 274550 ms  |


**Std::vector naudojimo metu CPU buvo naudojamas 40%,o atmintis 67%**

**Std::deque naudojimo metu CPU buvo naudojamas 45%, o atmintis 65%**

**Std::list naudojimo metu CPU buvo naudojamas 35%, o atmintis 60%**

*(Naudojamas dvieju fiziniu branduoliu procesorius.)*


## [Versija V1.0](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V0.1-baigta)
**Pirmoji strategija** (t.y. studentų išskaidymas į du tipus, tačiau taip pat jų palikimas pradiniame konteineryje) yra pateikiamas [nebaigtoje V1.0](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V1.0-nebaigta) versijoje, tačiau jo spartos analizės pateikti negaliu, nes mano kompiuteryje buvo per mažai atminties vykdyti tokią programą. Tad akivaizdu, jog tai labai neefektyvus būdas. 


**Antroji strategija** (t.y. studentų perkėlimas tik į vieną naują konteinerį šalinat perkeltuosiuos iš pradinio konteinerio) buvo įvykdytas jau [V0.5](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V05), tad jos spartą galite pažiūrėti šiek tiek aukščiau esančiose lentelėse. 

 **Pirmoji strategija yra geresnė laiko atžvilgniu (tą sugebėjau pastebėti iš to, kiek failų sugeneravo prieš užlūžtant kompiuteriui), nes užtruka trumpiau, bet antroji yra žymiai geresnės atminties atžvilgiu. **

**Programos sparta naudojant antrąją strategiją, ir naudojant algoritmus( *std::remove_copy_if, std::remove_if*):**

**Generavimo greitis:**
|Konteineris| 1000 | 10000 | 100000 | 1000000 |10000000 |
| --------- |:----:|:-----:|:------:|:-------:|--------:|
|Std::vector| 37 ms|354 ms | 4285 ms|52680 ms |590948 ms|

**Skirstymo ir spausdinimo greitis:**
|Konteineris| 1000 |10000  | 100000 |1000000  | 10000000 |
| --------- |:----:| :----:|:------:|:-------:|---------:|
|Std::vector|33 ms |286  ms| 3219 ms|43210  ms|492473  ms|

Taigi, algoritmai programos veikimą pagrietino beveik net 90 kartų. 
