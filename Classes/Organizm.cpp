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
            return "Antelope";
        case 'b':
            return "Pine Borscht";
        case 'G':
            return "Guarana";
        case 'F':
            return "Fox";
        case 'd':
            return "Dandelion";
        case 'S':
            return "Sheep";
        case 'g':
            return "Grass";
        case 'n':
            return "Deadly Nightshade";
        case 'W':
            return "Wolf";
        case 'T':
            return "Turtoise";
        case 'H':
            return "Human";
        default:
            return "Undefined";
    }
}