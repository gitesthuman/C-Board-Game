#include "../Headers/Roslina.h"
#include <iostream>

using namespace std;

void Roslina::kolizja(Organizm* napastnik) {
    cout<<napastnik->nazwa()<<" zjada "<<this->nazwa()<<"!\n";
    if (swiat->organizmy.findElement(X,Y)) swiat->organizmy.delElement(X,Y);
    else swiat->nowoNarodzone.delElement(X,Y);
    swiat->mapa[X][Y] = napastnik;
    swiat->mapa[napastnik->X][napastnik->Y] = nullptr;
    swiat->organizmy.findElement(napastnik->X,napastnik->Y)->X = X;
    swiat->organizmy.findElement(X,napastnik->Y)->Y = Y;
    swiat->mapa[X][Y]->X = X;
    swiat->mapa[X][Y]->Y = Y;
}

void Roslina::losujPole(int &x, int &y) {
    bool kierunki[4]={false};//0-góra 1-dół 2-prawo 3-lewo
    if (y < swiat->getWysoskosc()-1  && swiat->mapa[x][y+1] == nullptr) kierunki[0] = true;
    if (y > 0  && swiat->mapa[x][y-1] == nullptr) kierunki[1] = true;
    if (x < swiat->getSzerokosc()-1  && swiat->mapa[x+1][y] == nullptr) kierunki[2] = true;
    if (x > 0  && swiat->mapa[x-1][y] == nullptr) kierunki[3] = true;

    int ileKierunkow=0;
    for (int i = 0 ; i < 4 ; ++i)
        if (kierunki[i]) ileKierunkow++;

    if (ileKierunkow > 0) {
        int kierunek = rand() % ileKierunkow; //index kierunku (spośród możliwych)
        int licznik = -1;
        int index;
        for (int i = 0; i < 4 ; ++i) {
            if (kierunki[i]) licznik++;
            if (licznik == kierunek) {
                index = i;
                break;
            }
        }

        switch (index) {
            case 0://góra
                y++;
                break;
            case 1://dół
                y--;
                break;
            case 2://prawo
                x++;
                break;
            case 3://lewo
                x--;
                break;
        }
    }
}

void Roslina::akcja() {
    if (rand() % 20 == 0) {
        int X2=X,Y2=Y;
        losujPole(X2,Y2);
        if (X2 != X || Y2 != Y) rozmnazanie(X2,Y2);
    }
}
