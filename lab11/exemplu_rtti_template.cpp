#include <iostream>
#include <vector>

using namespace std;

class Baza
{
    int x;
public:
    Baza(int x): x(x) {}
    int GetX() const {return x;}
    friend ostream& operator<<(ostream& out, const Baza& b);
    virtual ~Baza() {}
};

ostream& operator<<(ostream& out, const Baza& b)
{
    out << b.x << endl;
    return out;
}

class Derivata : public Baza
{
    string y;
public:
    Derivata(int x, string y): Baza(x), y(y) {}
    friend ostream& operator<<(ostream& out, const Derivata& d);
};

ostream& operator<<(ostream& out, const Derivata& d)
{
    out << d.GetX() << ' ' << d.y << endl;
    return out;
}

template <class T>
class Gestiune
{
    vector<T*> obiecte;
public:
    void adauga(T* obj) {obiecte.push_back(obj);}
    void afisare()
    {
        for(int i=0; i<obiecte.size(); i++)
        {
            if(Derivata *d = dynamic_cast<Derivata *>(obiecte[i]))
            {
                cout << *d << ' ';
            }
            else
            {
                cout << *obiecte[i] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
};


int main() {
    Gestiune<Baza> gestiune;
    Baza* oBaza = new Baza(5);
    Derivata* oDerivata = new Derivata(10, "abc");

    gestiune.adauga(oBaza);
    gestiune.adauga(oDerivata);

    gestiune.afisare();

    return 0;
}
