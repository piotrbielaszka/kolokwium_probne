#include "Sok.hpp"

int main()
{
    Sok s("pomarańczowy", 3.5);

    Sok s1;
    Sok s2("gejfrut", 2);
    Dwupak<Sok, Sok> moj_dwupak = s1 + s2;
    moj_dwupak.wypij();

    vector<Sok> vs = daj_soki(10);
    for (Sok i : vs)
    {
        i.wypij();
    }

    cout << (czy_zawiera_pom(vs) ? "Zawiera pom\n" : "nie zawiera\n");
}