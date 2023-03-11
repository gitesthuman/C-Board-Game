#include "../Headers/Antylopa.h"
#include <iostream>

using namespace std;

Antylopa::Antylopa(int X, int Y, Swiat *swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 4;
    this->inicjatywa = 4;
    this->znak = 'A';
}

void Antylopa::rozmnazanie(int x, int y) {
    Organizm* dziecko = new Antylopa(x,y,swiat);
    swiat->mapa[x][y] = dziecko;
    swiat->nowoNarodzone.add(dziecko);
}

void Antylopa::kolizja(Organizm* napastnik) {
    if (znak != napastnik->znak && rand() % 2 == 0) {//unik
        bool kierunki[4] = {false};//0-góra 1-dół 2-prawo 3-lewo
        if (Y < swiat->getWysoskosc() - 1 && swiat->mapa[X][Y + 1] == nullptr) kierunki[0] = true;
        if (Y > 0 && swiat->mapa[X][Y - 1] == nullptr) kierunki[1] = true;
        if (X < swiat->getSzerokosc() - 1 && swiat->mapa[X + 1][X] == nullptr) kierunki[2] = true;
        if (X > 0 && swiat->mapa[X - 1][Y] == nullptr) kierunki[3] = true;

        int ileKierunkow = 0;
        for (int i = 0; i < 4; ++i)
            if (kierunki[i]) ileKierunkow++;

        if (ileKierunkow > 0) {//unik udany
            cout << "Antylopa robi unik przed " << napastnik->nazwa() << "!\n";
            int kierunek = rand() % ileKierunkow; //index kierunku (spośród możliwych)
            int licznik = -1;
            int index;
            for (int i = 0; i < 4; ++i) {
                if (kierunki[i]) licznik++;
                if (licznik == kierunek) {
                    index = i;
                    break;
                }
            }
            int x = X, y = Y;
            switch (index) {
                case 0://góra
                    ruch(X, Y + 1);
                    break;
                case 1://dół
                    ruch(X, Y - 1);
                    break;
                case 2://prawo
                    ruch(X + 1, Y);
                    break;
                case 3://lewo
                    ruch(X - 1, Y);
                    break;
            }
            swiat->mapa[napastnik->X][napastnik->Y] = nullptr;
            swiat->organizmy.findElement(napastnik->X, napastnik->Y)->X = x;
            swiat->organizmy.findElement(x, napastnik->Y)->Y = y;
            napastnik->X = x;
            napastnik->Y = y;
            swiat->mapa[napastnik->X][napastnik->Y] = napastnik;
            return;
        }
    }
    Zwierze::kolizja(napastnik);
}

void Antylopa::losujPole(int &x, int &y) {
    bool kierunki[8] = {false};//0-góra 1-dół 2-prawo 3-lewo 4-góra2 5-dół2 6-prawo2 7-lewo2
    if (y < swiat->getWysoskosc() - 1) kierunki[0] = true;
    if (y > 0) kierunki[1] = true;
    if (x < swiat->getSzerokosc() - 1) kierunki[2] = true;
    if (x > 0) kierunki[3] = true;
    if (y < swiat->getWysoskosc() - 2) kierunki[4] = true;
    if (y > 1) kierunki[5] = true;
    if (x < swiat->getSzerokosc() - 2) kierunki[6] = true;
    if (x > 1) kierunki[7] = true;

    int ileKierunkow = 0;
    for (int i = 0; i < 8; ++i)
        if (kierunki[i]) ileKierunkow++;

    int kierunek = rand() % ileKierunkow; //index kierunku (spośród możliwych)
    int licznik = -1;
    int index = -1;
    for (int i = 0; i < 8; ++i) {
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
        case 4://góra2
            y += 2;
            break;
        case 5://dół2
            y -= 2;
            break;
        case 6://prawo2
            x += 2;
            break;
        case 7://lewo2
            x -= 2;
            break;
    }
}