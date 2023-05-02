#include "../Headers/Czlowiek.h"
#include <iostream>

using namespace std;

Swiat::Swiat(const int wysokosc, const int szerokosc) {
    this->M = szerokosc;
    this->N = wysokosc;
    czlowiek = nullptr;
    mapa = new Organizm**[M];
    for (int i = 0; i < N; ++i) mapa[i] = new Organizm*[N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            mapa[j][i] = nullptr;
}

void Swiat::wykonajTure() {
    for (int i = 0; i < organizmy.getSize(); ++i) {
        organizmy.getBeg()->wiek++;
        if (organizmy.getBeg()->wiek > 0) organizmy.getBeg()->akcja();
        organizmy.naKoniec();
        if (czlowiek != nullptr) {
            if (czlowiek->umiejetnoscTrwa()) czlowiek->specjalnaUmiejetnosc();
        }
        else return;
    }
    cout<<'\n';
    while (nowoNarodzone.getSize() > 0) {
        Organizm* tmp = nowoNarodzone.getBeg();
        organizmy.add(tmp);
        nowoNarodzone.delElement(tmp->X,tmp->Y);
    }
}

void Swiat::rysujSwiat() const {
    for (int i = 0; i < 2*M + 3; ++i) cout << char(220);
    cout << '\n';
    for (int i = N-1; i >= 0; --i) {
        cout << char(219)<<' ';
        for (int j = 0; j < M; ++j) {
            if (mapa[j][i] == nullptr) cout<<'_';
            else mapa[j][i]->rysowanie();
            cout<<' ';
        }
        cout <<char(219)<< '\n';
    }
    for (int i = 0; i < 2*M + 3; ++i) cout << char(223);
    cout << "\n\n";
}

void Swiat::dodajOrganizm(Organizm* organizm) {
    if (Czlowiek* c = dynamic_cast<Czlowiek*>(organizm)) this->czlowiek = c;
    organizmy.add(organizm);
    mapa[organizm->X][organizm->Y] = organizm;
}

int Swiat::getWysoskosc() const {
    return N;
}

int Swiat::getSzerokosc() const {
    return M;
}

bool Swiat::isHumanAlive() {
    return czlowiek != nullptr;
}

void Swiat::killHuman() {
    czlowiek = nullptr;
}

Swiat::~Swiat() {
    delete mapa;
}
