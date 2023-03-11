#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {
private:
    void rozmnazanie(int x, int y) override;
    void zabij(int x, int y);

public:
    BarszczSosnowskiego(int X, int Y, Swiat* swiat);
    void akcja() override;
    void kolizja(Organizm* napastnik) override;
};