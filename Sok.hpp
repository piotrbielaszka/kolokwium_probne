#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Napoj
{
public:
    virtual void wypij() {}
    static Napoj *rozdaj_napoj(string imie);
};

class Sok : public Napoj
{
private:
    string smak;
    double V;

public:
    void set_smak(string s) { smak = s; }
    string get_smak() { return smak; }
    void set_V(double v) { V = v; }
    double get_V() { return V; }

    Sok(string s, double v) : smak(s), V(v) {}
    Sok()
    {
        smak = "jablkowy";
        V = 1;
    }

    void wypij() override { cout << "pije sok " << smak << " o obj. " << V << "\n"; }
};

class Lemoniada : public Napoj
{
    void wypij() override { cout << "pije lemoniade\n"; }
};

Napoj *Napoj::rozdaj_napoj(string imie)
{
    if (imie.length() <= 4)
        return new Lemoniada();
    else
        return new Sok("multiwitamina", 42);
}

template <typename T1, typename T2>
class Dwupak
{
    T1 sok1;
    T2 sok2;

public:
    Dwupak(T1 s1, T2 s2) : sok1(s1), sok2(s2) {}
    void wypij()
    {
        sok1.wypij();
        sok2.wypij();
    }
};

auto operator+(Sok s1, Sok s2)
{
    return Dwupak<Sok, Sok>(s1, s2);
}

vector<Sok> daj_soki(unsigned int n)
{
    vector<Sok> ret;
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
            ret.push_back(Sok("jab", i + 1));
        else if (i % 3 == 1)
            ret.push_back(Sok("pom", i + 1));
        else
            ret.push_back(Sok("multiv", i + 1));
    }
    return ret;
}

bool czy_zawiera_pom(vector<Sok> in)
{
    return any_of(in.begin(), in.end(), [](Sok i)
                  { return i.get_smak() == "pom"; });
}