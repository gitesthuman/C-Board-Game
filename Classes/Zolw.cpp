#include "../Headers/Zolw.h"
#include <iostream>

using namespace std;

Zolw::Zolw(int X, int Y, Swiat *swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 2;
    this->inicjatywa = 1;
    this->znak = 'Z';
}

void Zolw::akcja() {
    if (rand() % 4 == 0) Zwierze::akcja();
}

void Zolw::kolizja(Organizm* napastnik) {
    if (znak != napastnik->znak && napastnik->sila < 5) {//obrona
        cout << "Zolw broni sie przed " << napastnik->nazwa() << "!\n";
        return;
    }
    Zwierze::kolizja(napastnik);
}

void Zolw::rozmnazanie(int x, int y) {
    Organizm* dziecko = new Zolw(x,y,swiat);
    swiat->mapa[x][y] = dziecko;
    swiat->nowoNarodzone.add(dziecko);
}