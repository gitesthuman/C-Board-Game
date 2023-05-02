#include "../Headers/Zwierze.h"
#include <iostream>

using namespace std;

void Zwierze::ruch(int x, int y) {
    swiat->mapa[this->X][this->Y] = nullptr;
    swiat->organizmy.findElement(this->X, this->Y)->X = x;
    swiat->organizmy.findElement(x, this->Y)->Y = y;
    this->X = x;
    this->Y = y;
    swiat->mapa[this->X][this->Y] = this;
}

void Zwierze::losujPole(int &x, int &y) {
    bool kierunki[4]={false};//0-góra 1-dół 2-prawo 3-lewo
    if(y < swiat->getWysoskosc()-1) kierunki[0] = true;
    if (y > 0) kierunki[1] = true;
    if (x < swiat->getSzerokosc()-1) kierunki[2] = true;
    if (x > 0) kierunki[3] = true;

    int ileKierunkow=0;
    for (int i = 0 ; i < 4 ; ++i)
        if (kierunki[i]) ileKierunkow++;

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

void Zwierze::kolizja(Organizm* napastnik) {
    if (znak == napastnik->znak) {//rozmnażanie
        bool kierunki[6]={false};
        int x2=napastnik->X,y2=napastnik->Y;
        if (X + 1 == napastnik->X || X - 1 == napastnik->X) {//obok siebie
            //0-góraprawo 1-góralewo 2-dółprawo 3-dółlewo 4-prawo 5-lewo
            if (x2 > X) {
                if (Y < swiat->getWysoskosc()-1) {
                    if (swiat->mapa[x2][Y+1] == nullptr) kierunki[0] = true;
                    if (swiat->mapa[X][Y+1] == nullptr) kierunki[1] = true;
                }
                if (Y > 0)  {
                    if (swiat->mapa[x2][Y-1] == nullptr) kierunki[2] = true;
                    if (swiat->mapa[X][Y-1] == nullptr) kierunki[3] = true;
                }
                if (x2 < swiat->getSzerokosc() - 1 && swiat->mapa[x2+1][Y] == nullptr) kierunki[4] = true;
                if (X > 0 && swiat->mapa[X-1][Y] == nullptr) kierunki[5] = true;
            }
            else {
                if (Y < swiat->getWysoskosc()-1) {
                    if (swiat->mapa[X][Y+1] == nullptr) kierunki[0] = true;
                    if (swiat->mapa[x2][Y+1] == nullptr) kierunki[1] = true;
                }
                if (Y > 0)  {
                    if (swiat->mapa[X][Y-1] == nullptr) kierunki[2] = true;
                    if (swiat->mapa[x2][Y-1] == nullptr) kierunki[3] = true;
                }
                if (X < swiat->getSzerokosc() - 1 && swiat->mapa[X+1][Y] == nullptr) kierunki[4] = true;
                if (x2 > 0 && swiat->mapa[x2-1][Y] == nullptr) kierunki[5] = true;
            }
        }
        else {//nad sobą
            //0-góra 1-dół 2-prawogóra 3-prawodół 4-lewogóra 5-lewodół
            if (y2 > Y) {
                if (y2 < swiat->getSzerokosc() - 1 && swiat->mapa[X][y2+1] == nullptr) kierunki[0] = true;
                if (Y > 0 && swiat->mapa[X][Y-1] == nullptr) kierunki[1] = true;
                if (X < swiat->getWysoskosc()-1) {
                    if (swiat->mapa[X+1][y2] == nullptr) kierunki[2] = true;
                    if (swiat->mapa[X+1][Y] == nullptr) kierunki[3] = true;
                }
                if (X > 0)  {
                    if (swiat->mapa[X-1][y2] == nullptr) kierunki[4] = true;
                    if (swiat->mapa[X-1][Y] == nullptr) kierunki[5] = true;
                }
            }
            else {
                if (Y < swiat->getSzerokosc() - 1 && swiat->mapa[X][Y+1] == nullptr) kierunki[0] = true;
                if (y2 > 0 && swiat->mapa[X][y2-1] == nullptr) kierunki[1] = true;
                if (X < swiat->getWysoskosc()-1) {
                    if (swiat->mapa[X+1][Y] == nullptr) kierunki[2] = true;
                    if (swiat->mapa[X+1][y2] == nullptr) kierunki[3] = true;
                }
                if (X > 0)  {
                    if (swiat->mapa[X-1][Y] == nullptr) kierunki[4] = true;
                    if (swiat->mapa[X-1][y2] == nullptr) kierunki[5] = true;
                }
            }
        }

        int ileKierunkow=0;
        for (int i = 0 ; i < 4 ; ++i)
            if (kierunki[i]) ileKierunkow++;

        if (ileKierunkow > 0) {
            int kierunek = rand() % ileKierunkow; //index kierunku (spośród możliwych)
            int licznik = -1;
            int index;
            for (int i = 0; i < 6 ; ++i) {
                if (kierunki[i]) licznik++;
                if (licznik == kierunek) {
                    index = i;
                    break;
                }
            }

            if (X + 1 == napastnik->X || X - 1 == napastnik->X) {
                switch (index) {
                    case 0://góraprawo
                        if (x2>X) rozmnazanie(x2,Y+1);
                        else rozmnazanie(X,Y+1);
                        break;
                    case 1://góralewo
                        if (x2>X) rozmnazanie(X,Y+1);
                        else rozmnazanie(x2,Y);
                        break;
                    case 2://dółprawo
                        if (x2>X) rozmnazanie(x2,Y-1);
                        else rozmnazanie(X,Y-1);
                        break;
                    case 3://dółlewo
                        if (x2>X) rozmnazanie(X,Y-1);
                        else rozmnazanie(x2,Y-1);
                        break;
                    case 4://prawo
                        if (x2>X) rozmnazanie(x2+1,Y);
                        else rozmnazanie(X+1,Y);
                        break;
                    case 5://lewo
                        if (x2>X) rozmnazanie(X-1,Y);
                        else rozmnazanie(x2-1,Y);
                        break;
                }
            }
            else {
                switch (index) {
                    case 0://góra
                        if (y2>Y) rozmnazanie(X,y2+1);
                        else rozmnazanie(X,Y+1);
                        break;
                    case 1://dół
                        if (y2>Y) rozmnazanie(X,Y-1);
                        else rozmnazanie(X,y2-1);
                        break;
                    case 2://prawogóra
                        if (y2>Y) rozmnazanie(X+1,y2);
                        else rozmnazanie(X+1,Y);
                        break;
                    case 3://prawodół
                        if (y2>Y) rozmnazanie(X+1,Y);
                        else rozmnazanie(X+1,y2);
                        break;
                    case 4://lewogóra
                        if (y2>Y) rozmnazanie(X-1,y2);
                        else rozmnazanie(X-1,Y);
                        break;
                    case 5://lewodół
                        if (y2>Y) rozmnazanie(X-1,Y);
                        else rozmnazanie(X-1,y2);
                        break;
                }
            }
        }
    }
    else {//walka
        cout<<"Fight! ";
        if (napastnik->sila >= this->sila) {
            if (znak == 'H') swiat->killHuman();
            cout<<napastnik->nazwa()<<" defeats "<<this->nazwa()<<"!\n";
            if (swiat->organizmy.findElement(X,Y)) swiat->organizmy.delElement(X,Y);
            else swiat->nowoNarodzone.delElement(X,Y);
            swiat->mapa[X][Y] = napastnik;
            swiat->mapa[napastnik->X][napastnik->Y] = nullptr;
            swiat->organizmy.findElement(napastnik->X,napastnik->Y)->X = X;
            swiat->organizmy.findElement(X,napastnik->Y)->Y = Y;
            swiat->mapa[X][Y]->X = X;
            swiat->mapa[X][Y]->Y = Y;
        }
        else {
            cout<<this->nazwa()<<" defeats "<<napastnik->nazwa()<<"!\n";
            if (napastnik->znak == 'H') swiat->killHuman();
            swiat->mapa[napastnik->X][napastnik->Y] = nullptr;
            if (swiat->organizmy.findElement(napastnik->X,napastnik->Y))
                swiat->organizmy.delElement(napastnik->X,napastnik->Y);
            else swiat->nowoNarodzone.delElement(napastnik->X,napastnik->Y);
        }
    }
}

void Zwierze::akcja() {
    int X2=X,Y2=Y;
    losujPole(X2,Y2);
    if (X2 != X || Y2 != Y) {
        if (swiat->mapa[X2][Y2] == nullptr) ruch(X2, Y2);
        else swiat->mapa[X2][Y2]->kolizja(this);
    }
}