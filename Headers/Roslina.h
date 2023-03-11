#pragma once
#include "Swiat.h"

class Roslina : public Organizm {
private:
    void losujPole(int &x, int &y) override;

public:
    void akcja() override;
    void kolizja(Organizm* napastnik) override;
};