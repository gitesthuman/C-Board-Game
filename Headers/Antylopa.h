#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
private:
    void losujPole(int &x, int &y) override;
    void rozmnazanie(int x, int y) override;

public:
    Antylopa(int X, int Y, Swiat* swiat);
    void kolizja(Organizm* napastnik) override;
};
