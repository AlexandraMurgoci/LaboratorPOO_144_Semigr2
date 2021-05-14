#include <iostream>
#include <vector>

using namespace std;

class Companie
{
protected:
    string m_denumire;
    int m_an_infiintare;
    string m_cod_icao_iata;
    vector<string> m_destinatii;
public:
    Companie() {}
    virtual ~Companie() {}

    friend istream &operator>>(istream& in, Companie& companie);
    friend ostream &operator<<(ostream& out, const Companie& companie);
};

istream &operator>>(istream& in, Companie& companie)
{
    in >> companie.m_denumire >> companie.m_an_infiintare >> companie.m_cod_icao_iata;
    int nr_destinatii;
    in >> nr_destinatii;
    companie.m_destinatii.resize(nr_destinatii);
    for(int i=0; i< nr_destinatii; i++)
    {
        string destinatie;
        in >> destinatie;
        companie.m_destinatii[i] = destinatie;
    }
    return in;
}

ostream &operator<<(ostream& out, const Companie& companie)
{
    out << companie.m_denumire << ' ' << companie.m_an_infiintare << ' ' << companie.m_cod_icao_iata << endl;
    out << "Destinatii: ";
    for(int i=0; i < companie.m_destinatii.size(); i++) out << companie.m_destinatii[i] << ' ';
    return out;
}

class CompanieLowCost: public Companie
{
    double pretPerKg;
//    vector<ZborLowCost*>
public:
    CompanieLowCost(){}
    ~CompanieLowCost(){}

    friend istream &operator>>(istream& in, CompanieLowCost& companie);
    friend ostream &operator<<(ostream& out, const CompanieLowCost& companie);
};

istream &operator>>(istream& in, CompanieLowCost& companie)
{
    in >> dynamic_cast<Companie&>(companie);
    in >> companie.pretPerKg;
    return in;
}

ostream &operator<<(ostream& out, const CompanieLowCost& companie)
{
    out << dynamic_cast<const Companie&>(companie);
    out << endl << companie.pretPerKg;
    return out;
}

class CompanieDeLinie: public Companie
{
//    vector<ZborEscala*>
public:
    CompanieDeLinie(){}
    ~CompanieDeLinie(){}

    friend istream &operator>>(istream& in, CompanieDeLinie& companie);
    friend ostream &operator<<(ostream& out, const CompanieDeLinie& companie);
};

istream &operator>>(istream& in, CompanieDeLinie& companie)
{
    in >> dynamic_cast<Companie&>(companie);
    return in;
}

ostream &operator<<(ostream& out, const CompanieDeLinie& companie)
{
    out << dynamic_cast<const Companie&>(companie);
    return out;
}

class Zbor
{
protected:
    int m_id;
    string destinatie;
    string data;
    string ora;
    double durata;
    double pret;
    Companie *companie;
    static int s_next_id;
public:
    Zbor()
    {
        m_id = s_next_id;
        s_next_id ++;
        companie = nullptr;
    }
    //un zbor din CC nu este un zbor nou pentru aplicatie => nu incrementam si nu schimbam codul

    virtual ~Zbor()
    {
        //nu trebuie stearsa compania cand se sterge un zbor
        companie = nullptr;
    }

    friend istream &operator>>(istream& in, Zbor& zbor);
    friend ostream &operator<<(ostream& out, const Zbor& zbor);
};
int Zbor::s_next_id = 1;

class ZborLowCost: public Zbor
{
protected:
    double greutate_maxima_bagaj_de_cala;
public:
    ZborLowCost() {}
    ~ZborLowCost() {}

    friend istream &operator>>(istream& in, ZborLowCost& zbor);
    friend ostream &operator<<(ostream& out, const ZborLowCost& zbor);
};

class ZborCuEscale: public Zbor
{
protected:
    //pot avea 0 escale => un zbor simplu fara escale
    vector<string> escale;
public:
    ZborCuEscale() {}
    ~ZborCuEscale() {}

    friend istream &operator>>(istream& in, ZborCuEscale& zbor);
    friend ostream &operator<<(ostream& out, const ZborCuEscale& zbor);
};

class Charter
{
protected:
    string m_operator_turism;
    double m_pret_suplimentar;
public:
    Charter() {}
    virtual ~Charter() {}

    friend istream &operator>>(istream& in, Charter& zbor);
    friend ostream &operator<<(ostream& out, const Charter& zbor);
};

class ZborLowCostCharter: public ZborLowCost, Charter
{
public:
    ZborLowCostCharter() {}
    ~ZborLowCostCharter() {}

    friend istream &operator>>(istream& in, ZborLowCostCharter& zbor);
    friend ostream &operator<<(ostream& out, const ZborLowCostCharter& zbor);
};

//TODO
//ZBOR CU ESCALE CARE E SI CHARTER

class ZborCharter: public Zbor, Charter
{
public:
    ZborCharter() {}
    ~ZborCharter() {}

    friend istream &operator>>(istream& in, ZborLowCostCharter& zbor);
    friend ostream &operator<<(ostream& out, const ZborLowCostCharter& zbor);
};

void MeniuInteractiv(vector<Companie*>& companii, vector<Zbor*> zboruri)
{
    //ADAUGARE/STERGERE COMPANII
    //ADAUGARE/STERGERE ZBORURI
    //AFISARE COMPANII
    //AFISARE ZBORURI
}

int main() {
    vector<Companie*> companii;
    vector<Zbor*> zboruri;
    return 0;
}
