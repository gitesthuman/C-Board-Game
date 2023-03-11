#include "../Headers/Organizm.h"
#include <iostream>

using namespace std;

Organizm::Organizm() = default;

void Organizm::rysowanie() const {
    cout<<znak;
}

const char * Organizm::nazwa() const {
    switch (znak) {
        case 'A':
            return "Antylopa";
        case 'b':
            return "Barszcz Sosnowskiego";
        case 'g':
            return "Guarana";
        case 'L':
            return "Lis";
        case 'm':
            return "Mlecz";
        case 'O':
            return "Owca";
        case 't':
            return "Trawa";
        case 'w':
            return "Wilcze Jagody";
        case 'W':
            return "Wilk";
        case 'Z':
            return "Zolw";
        case 'C':
            return "Czlowiek";
        default:
            return "None";
    }
}