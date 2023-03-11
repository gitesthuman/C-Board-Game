#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
private:
    void rozmnazanie(int x, int y) override;

public:
    Owca(int X, int Y, Swiat* swiat);
};