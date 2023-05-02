#pragma warning(disable: 4996)
#include "../Headers/Czlowiek.h"
#include <conio.h>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define SPECIAL_X 120

using namespace std;

void Czlowiek::rozmnazanie(int x, int y) {}

void Czlowiek::pal(int x, int y) {
    cout<<"Human burns "<<swiat->mapa[x][y]->nazwa()<<"!\n";
    if (swiat->organizmy.findElement(x,y)) swiat->organizmy.delElement(x,y);
    else swiat->nowoNarodzone.delElement(x,y);
    swiat->mapa[x][y] = nullptr;
}

void Czlowiek::specjalnaUmiejetnosc() {
    if (Y < swiat->getWysoskosc()-1 && swiat->mapa[X][Y+1] != nullptr) pal(X,Y+1);
    if (Y > 0 && swiat->mapa[X][Y-1] != nullptr) pal(X,Y-1);
    if (X < swiat->getSzerokosc()-1 && swiat->mapa[X+1][Y] != nullptr) pal(X+1,Y);
    if (X > 0 && swiat->mapa[X-1][Y] != nullptr) pal(X-1,Y);
}

Czlowiek::Czlowiek(int X, int Y, Swiat *swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 5;
    this->inicjatywa = 4;
    this->znak = 'H';
    this->czasTrwaniaUmiejetnosci = 0;
    this->coolDownUmiejetnosci = 0;
}

void Czlowiek::akcja() {
    int c;
    bool stop = false;
    int x2=X,y2=Y;
    if (czasTrwaniaUmiejetnosci > 0) czasTrwaniaUmiejetnosci--;
    else if (coolDownUmiejetnosci > 0) coolDownUmiejetnosci--;
    swiat->rysujSwiat();
    while (c=getch()) {
        switch (c) {
            case KEY_UP:
                if (y2 < swiat->getWysoskosc()-1) {
                    y2++;
                    stop = true;
                }
                break;
            case KEY_DOWN:
                if (y2 > 0) {
                    y2--;
                    stop = true;
                }
                break;
            case KEY_RIGHT:
                if (x2 < swiat->getSzerokosc()-1) {
                    x2++;
                    stop = true;
                }
                break;
            case KEY_LEFT:
                if (x2 > 0) {
                    x2--;
                    stop = true;
                }
                break;
            case SPECIAL_X:
                if (coolDownUmiejetnosci == 0 && czasTrwaniaUmiejetnosci == 0) {
                    czasTrwaniaUmiejetnosci = 5;
                    coolDownUmiejetnosci = 5;
                    cout<<"Holocaust activated!\n";
                    specjalnaUmiejetnosc();
                }
                break;
            default:
                break;
        }
        if (stop) break;
    }
    system("cls");
    if (swiat->mapa[x2][y2] == nullptr) ruch(x2, y2);
    else swiat->mapa[x2][y2]->kolizja(this);
}

bool Czlowiek::umiejetnoscTrwa() {
    if (czasTrwaniaUmiejetnosci > 0) return true;
    else return false;
}

Czlowiek::Czlowiek(Organizm* &&organizm) {
    this->X = organizm->X;
    this->Y = organizm->Y;
    this->swiat = organizm->swiat;
    this->sila = 5;
    this->inicjatywa = 4;
    this->znak = 'H';
    this->czasTrwaniaUmiejetnosci = 0;
    this->coolDownUmiejetnosci = 0;
}

Czlowiek::~Czlowiek() {
    cout << "GAME OVER";
    //swiat->killHuman();
}