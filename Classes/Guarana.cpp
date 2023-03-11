#include "../Headers/Guarana.h"

Guarana::Guarana(int X, int Y, Swiat* swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 0;
    this->inicjatywa = 0;
    this->znak = 'g';
}

void Guarana::rozmnazanie(int x, int y) {
    Organizm* sadzonka = new Guarana(x,y,swiat);
    swiat->mapa[x][y] = sadzonka;
    swiat->nowoNarodzone.add(sadzonka);
}

void Guarana::kolizja(Organizm* napastnik) {
    Roslina::kolizja(napastnik);
    swiat->organizmy.findElement(X,Y)->sila += 3;
    swiat->mapa[X][Y]->sila += 3;
}

