#include "../Headers/Lis.h"
#include <iostream>

Lis::Lis(int X, int Y, Swiat *swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 3;
    this->inicjatywa = 7;
    this->znak = 'L';
}

void Lis::losujPole(int &x, int &y) {
    bool kierunki[4]={false};//0-góra 1-dół 2-prawo 3-lewo
    if (y < swiat->getWysoskosc()-1 && (swiat->mapa[X][Y+1] == nullptr || swiat->mapa[X][Y+1]->sila <= sila || swiat->mapa[X][Y+1]->znak == 'L')) kierunki[0] = true;
    if (y > 0 && (swiat->mapa[X][Y-1] == nullptr || swiat->mapa[X][Y-1]->sila <= sila || swiat->mapa[X][Y-1]->znak == 'L')) kierunki[1] = true;
    if (x < swiat->getSzerokosc()-1 && (swiat->mapa[X+1][Y] == nullptr || swiat->mapa[X+1][Y]->sila <= sila || swiat->mapa[X+1][Y]->znak == 'L')) kierunki[2] = true;
    if (x > 0 && (swiat->mapa[X-1][Y] == nullptr || swiat->mapa[X-1][Y]->sila <= sila || swiat->mapa[X-1][Y]->znak == 'L')) kierunki[3] = true;

    int ileKierunkow=0;
    for (int i = 0 ; i < 4 ; ++i)
        if (kierunki[i]) ileKierunkow++;

    if (ileKierunkow > 0) {
        int kierunek = rand() % ileKierunkow; //index kierunku (spośród możliwych)
        int licznik = -1;
        int index = -1;
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

void Lis::rozmnazanie(int x, int y) {
    Organizm* dziecko = new Lis(x,y,swiat);
    swiat->mapa[x][y] = dziecko;
    swiat->nowoNarodzone.add(dziecko);
}