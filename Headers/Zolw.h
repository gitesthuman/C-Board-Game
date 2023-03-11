#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
    Zolw(int X, int Y, Swiat* swiat);
    void akcja() override;
    void kolizja(Organizm* napastnik) override;

private:
    void rozmnazanie(int x, int y) override;
};