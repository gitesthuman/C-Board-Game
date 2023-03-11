#include "../Headers/WilczeJagody.h"
#include <iostream>

using namespace std;

WilczeJagody::WilczeJagody(int X, int Y, Swiat* swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 99;
    this->inicjatywa = 0;
    this->znak = 'w';
}

void WilczeJagody::rozmnazanie(int x, int y) {
    Organizm* sadzonka = new WilczeJagody(x,y,swiat);
    swiat->mapa[x][y] = sadzonka;
    swiat->nowoNarodzone.add(sadzonka);
}

void WilczeJagody::kolizja(Organizm* przeciwnik) {
    Roslina::kolizja(przeciwnik);
    cout<<"Wilcze Jagody zabijaja "<<przeciwnik->nazwa()<<"!\n";
    if (swiat->organizmy.findElement(X,Y)) swiat->organizmy.delElement(X,Y);
    else swiat->nowoNarodzone.delElement(X,Y);
    swiat->mapa[X][Y] = nullptr;
}