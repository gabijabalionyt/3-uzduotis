#include "biblioteka.h"


int main ()

{
    srand (time(NULL));
    vector <Student> S;
        vector <Student> kieti;
    vector <Student> silpni;
 std::ofstream o("Kvaili.txt", std::ofstream::out);
  std::ofstream ou("Protingi.txt" , std::ofstream::trunc);
  o.close();
  ou.close();
    int pas;
    pas=pasirinkimas();
    if(pas==1)
        versija1(S, silpni, kieti);
    else if (pas ==2) versija2 (S, silpni, kieti);
    else versija3pro (S, silpni, kieti);
;
    return 0;
}



