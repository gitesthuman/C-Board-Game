#pragma once
#include "Swiat.h"

class Zwierze : public Organizm {
protected:
    virtual void ruch(int x, int y);
    void losujPole(int &x, int &y) override;

public:
    void akcja() override;
    void kolizja(Organizm* napastnik) override;
};