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
istream &operator>>(istream& in, Zbor& zbor)
{
    cout << "Introduceti destinatia.\n";
    in >> zbor.destinatie;
    cout << "Introduceti data.\n";
    in >> zbor.data;
    cout << "Introduceti ora.\n";
    in >> zbor.ora;
    cout << "Introduceti durata.\n";
    in >> zbor.durata;
    cout << "Introduceti pret.\n";
    in >> zbor.pret;

    return in;
}

ostream &operator<<(ostream& out, const Zbor& zbor)
{

    out << "Destinatia: " << zbor.destinatie << "\n";
    out << "Data: " << zbor.data << "\n";
    out << "Ora: " << zbor.ora << "\n";
    out << "Durata: " << zbor.durata << "\n";
    out << "Pret: " << zbor.pret << "\n";



    return out;
}

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
istream &operator>>(istream& in, Charter& zbor)
{
    cout<< "Operator turism: ";
    in >> zbor.m_operator_turism ;
    cout<< "Pret suplimentar: ";
    in >> zbor.m_pret_suplimentar;
    return in;
}
ostream &operator<<(ostream& out, const Charter& zbor)
{
    out << zbor.m_operator_turism << " " << zbor.m_pret_suplimentar;
    return out;
}
class ZborLowCostCharter: public ZborLowCost, Charter
{
public:
    ZborLowCostCharter() {}
    ~ZborLowCostCharter() {}

    friend istream &operator>>(istream& in, ZborLowCostCharter& zbor);
    friend ostream &operator<<(ostream& out, const ZborLowCostCharter& zbor);
};
istream &operator>>(istream& in, ZborLowCostCharter& zbor)
{
    in >> dynamic_cast<ZborLowCost&>(zbor);
    in >> dynamic_cast<Charter&>(zbor);
    return in;
}
 ostream &operator<<(ostream& out, const ZborLowCostCharter& zbor)
 {
     out << dynamic_cast<const ZborLowCost&>(zbor);
     out << dynamic_cast<const Charter&>(zbor);
     return out;
 }

//TODO
//ZBOR CU ESCALE CARE E SI CHARTER

class ZborCuEscaleCharter: public ZborCuEscale, Charter
{
public:
    ZborCuEscaleCharter() {}
    ~ZborCuEscaleCharter() {}

    friend istream &operator >> (istream& in, ZborCuEscaleCharter& zbor);
    friend ostream &operator << (ostream& out, const ZborCuEscaleCharter& zbor);
};

istream &operator >>(istream& in, ZborCuEscaleCharter& zbor)
{
    in >> dynamic_cast<ZborCuEscale&>(zbor);
    in >> dynamic_cast<Charter&>(zbor);
    return in;
}

ostream &operator <<(ostream& out, const ZborCuEscaleCharter& zbor)
{
    out << dynamic_cast<const ZborCuEscale&>(zbor);
    out << dynamic_cast<const Charter&>(zbor);
    return out;
}

class ZborCharter: public Zbor, Charter
{
public:
    ZborCharter() {}
    ~ZborCharter() {}

    friend istream &operator>>(istream& in, ZborLowCostCharter& zbor);
    friend ostream &operator<<(ostream& out, const ZborLowCostCharter& zbor);
};

void AfiseazaOptiuniMeniu() {
    cout << "1. Adauga o companie" << endl
    << "2. Adauga un zbor" << endl
    << "3. Afiseaza toate companiile" << endl
    << "4. Afiseaza toate zborurile" <<endl;
}
void MeniuInteractiv(vector<Companie*>& companii, vector<Zbor*> zboruri)
{
    int option = -1;
    int stop_option = 0;
    while(option != 0)
    {
        AfiseazaOptiuniMeniu();
        cin >> option;
        if(option == 1)
        {
            //TODO
        }
        else if(option == 2)
        {
            //TODO
        }
        else if(option == 3)
        {
            //TODO
        }
        else if(option == 4)
        {
            //TODO
        }
    }

    //eliberare memorie
    for(int i=0; i < zboruri.size(); i++) delete zboruri[i];
    for(int i=0; i < companii.size(); i++) delete companii[i];
}

int main() {
    vector<Companie*> companii;
    vector<Zbor*> zboruri;
    MeniuInteractiv(companii, zboruri);
    return 0;
}
