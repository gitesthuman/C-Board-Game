#pragma once

class Swiat;

class Organizm {
public:
    double sila;
    double inicjatywa;
    int X;
    int Y;
    Swiat* swiat;
    int wiek = 0;
    char znak;

    Organizm();
    virtual void akcja() = 0;
    virtual void kolizja(Organizm* napastnik) = 0;
    void rysowanie() const;
    const char* nazwa() const;

protected:
    virtual void losujPole(int &x, int &y) = 0;
    virtual void rozmnazanie(int x, int y) = 0;
};