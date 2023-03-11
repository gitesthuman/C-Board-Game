#pragma once
#include "Roslina.h"

class Trawa : public Roslina{
private:
    void rozmnazanie(int x, int y) override;

public:
    Trawa(int X, int Y, Swiat* swiat);
};