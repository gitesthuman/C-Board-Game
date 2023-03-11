#include <iostream>
#include <ctime>
#include "Headers/Antylopa.h"
#include "Headers/BarszczSosnowskiego.h"
#include "Headers/Guarana.h"
#include "Headers/Lis.h"
#include "Headers/Mlecz.h"
#include "Headers/Owca.h"
#include "Headers/Trawa.h"
#include "Headers/WilczeJagody.h"
#include "Headers/Wilk.h"
#include "Headers/Zolw.h"
#include "Headers/Czlowiek.h"

using namespace std;

int main() {
    srand((unsigned) time(0));
    Swiat nowyswiat = Swiat(30,30);
    nowyswiat.dodajOrganizm(new Wilk(2,4,&nowyswiat));
    nowyswiat.dodajOrganizm(new Owca(7,17,&nowyswiat));
    nowyswiat.dodajOrganizm(new Trawa(5,8,&nowyswiat));
    nowyswiat.dodajOrganizm(new Antylopa(22,5,&nowyswiat));
    nowyswiat.dodajOrganizm(new BarszczSosnowskiego(25,20,&nowyswiat));
    nowyswiat.dodajOrganizm(new Guarana(10,5,&nowyswiat));
    nowyswiat.dodajOrganizm(new Mlecz(29,29,&nowyswiat));
    nowyswiat.dodajOrganizm(new WilczeJagody(19,19,&nowyswiat));
    nowyswiat.dodajOrganizm(new Zolw(12,29,&nowyswiat));
    nowyswiat.dodajOrganizm(new Lis(14,5,&nowyswiat));
    nowyswiat.dodajOrganizm(new Czlowiek(15,15,&nowyswiat));
    nowyswiat.rysujSwiat();
    cout<<"\n";
    for (int i = 0 ; i < 1000; i++)
    {
        nowyswiat.wykonajTure();
    }
    return 0;
}
