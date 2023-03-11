#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {
private:
    void rozmnazanie(int x, int y) override;

public:
    Mlecz(int X, int Y, Swiat* swiat);
    void akcja() override;
};