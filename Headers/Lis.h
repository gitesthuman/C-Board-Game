#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
private:
    void losujPole(int &x, int &y) override;
    void rozmnazanie(int x, int y) override;

public:
    Lis(int X, int Y, Swiat* swiat);
};