#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
private:
    void rozmnazanie(int x, int y) override;

public:
    Wilk(int X, int Y, Swiat* swiat);
};