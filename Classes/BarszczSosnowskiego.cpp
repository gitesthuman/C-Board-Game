#include "../Headers/BarszczSosnowskiego.h"
#include "../Headers/Zwierze.h"
#include <iostream>

using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(int X, int Y, Swiat* swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 10;
    this->inicjatywa = 0;
    this->znak = 'b';
}

void BarszczSosnowskiego::rozmnazanie(int x, int y) {
    Organizm* sadzonka = new BarszczSosnowskiego(x,y,swiat);
    swiat->mapa[x][y] = sadzonka;
    swiat->nowoNarodzone.add(sadzonka);
}

void BarszczSosnowskiego::zabij(int x, int y) {
    cout<<"Barszcz Sosnowskiego zabija "<<swiat->mapa[x][y]->nazwa()<<"!\n";
    if (swiat->organizmy.findElement(x,y)) swiat->organizmy.delElement(x,y);
    else swiat->nowoNarodzone.delElement(x,y);
    swiat->mapa[x][y] = nullptr;
}

void BarszczSosnowskiego::akcja() {
    Roslina::akcja();
    if (Y < swiat->getWysoskosc()-1 && dynamic_cast<Zwierze*>(swiat->mapa[X][Y+1])) zabij(X,Y+1);
    if (Y > 0 && dynamic_cast<Zwierze*>(swiat->mapa[X][Y-1])) zabij(X,Y-1);
    if (X < swiat->getSzerokosc()-1 && dynamic_cast<Zwierze*>(swiat->mapa[X+1][Y])) zabij(X+1,Y);
    if (X > 0 && dynamic_cast<Zwierze*>(swiat->mapa[X-1][Y])) zabij(X-1,Y);
}

void BarszczSosnowskiego::kolizja(Organizm* napastnik) {
    Roslina::kolizja(napastnik);
    cout<<"Barszcz Sosnowskiego zabija "<<napastnik->nazwa()<<"!\n";
    if (swiat->organizmy.findElement(X,Y)) swiat->organizmy.delElement(X,Y);
    else swiat->nowoNarodzone.delElement(X,Y);
    swiat->mapa[X][Y] = nullptr;
}
