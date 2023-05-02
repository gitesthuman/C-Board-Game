#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
    int czasTrwaniaUmiejetnosci;
    int coolDownUmiejetnosci;

    void rozmnazanie(int x, int y) override;
    void pal(int x, int y);

public:
    Czlowiek(int X, int Y, Swiat* swiat);
    ~Czlowiek();
    explicit Czlowiek(Organizm* &&organizm);
    void akcja() override;
    bool umiejetnoscTrwa();
    void specjalnaUmiejetnosc();

};