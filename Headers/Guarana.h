#pragma once
#include "Roslina.h"

class Guarana : public Roslina{
private:
    void rozmnazanie(int x, int y) override;

public:
    Guarana(int X, int Y, Swiat* swiat);
    void kolizja(Organizm* napastnik) override;
};