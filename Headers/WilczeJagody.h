#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina {
private:
    void rozmnazanie(int x, int y) override;

public:
    WilczeJagody(int X, int Y, Swiat* swiat);
    void kolizja(Organizm* przeciwnik) override;
};