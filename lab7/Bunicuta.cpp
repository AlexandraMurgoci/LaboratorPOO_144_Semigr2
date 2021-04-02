#include <iostream>
#include <vector>

using namespace std;

class Forma
{
protected:
    double m_inaltime;
public:
    Forma(): m_inaltime(0) {}
    Forma(double inaltime): m_inaltime(inaltime) {}
    double GetInaltime() {return m_inaltime;}
    //virtual se fol pentru a determina la runtime clasa obiectului din pointer/referinta si a folosi metoda suprascrisa
    virtual void Afisare()
    {
        std::cout << "Forma: inaltimea " << m_inaltime << std::endl;
    }
    virtual double Volum() {return 0;}
    double CantitateGem()
    {
        return Volum() * 2;
    }
    double CantitateFrisca()
    {
        return Volum();
    }
    virtual ~Forma(){}
};

class Cerc: public Forma
{
    double m_raza;
public:
    Cerc(): Forma(), m_raza(0) {}
    Cerc(double inaltime, double raza): Forma(inaltime), m_raza(raza) {}
    void Afisare()
    {
//        Forma::Afisare();
//        std::cout << "Cerc: inaltime " << GetInaltime() << " raza: " << m_raza << std::endl;
        std::cout << "Cerc: inaltime " << m_inaltime << " raza: " << m_raza << std::endl;
    }
    void Citire()
    {
        cin >> m_inaltime >> m_raza;
    }
    double Volum()
    {
//        cout << "Fol volum din cerc!!" << endl;
        return m_inaltime * 3.14 * m_raza * m_raza;
    }
};

class Dreptunghi: public Forma
{
    double m_latura_mica;
    double m_latura_mare;
public:
    void Citire()
    {
        cin >> m_inaltime >> m_latura_mica >> m_latura_mare;
    }
    void Afisare()
    {
        std::cout << "Dreptunghi: inaltime " << m_inaltime << " latura mica: " << m_latura_mica << " latura mare: " << m_latura_mare << std::endl;
    }
    double Volum()
    {
        return m_inaltime * m_latura_mica * m_latura_mare;
    }
};

class Patrat: public Forma
{
    double m_latura;
public:
    void Citire()
    {
        cin >> m_inaltime >> m_latura;
    }
    void Afisare()
    {
        std::cout << "Patrat: inaltime " << m_inaltime << " latura: " << m_latura << std::endl;
    }
    double Volum()
    {
        return m_inaltime * m_latura;
    }
};

class Triunghi: public Forma
{
    double m_cateta_mica;
    double m_cateta_mare;
public:
    void Citire()
    {
        cin >> m_inaltime >> m_cateta_mica >> m_cateta_mare;
    }
    void Afisare()
    {
        std::cout << "Triunghi: inaltime " << m_inaltime << " cateta mica: " << m_cateta_mica << " cateta mare: " << m_cateta_mare << std::endl;
    }
    double Volum()
    {
        return m_inaltime * m_cateta_mica * m_cateta_mare;
    }
};

void demo()
{
    //    Forma formaGenerica(5);
//    formaGenerica.Afisare();
//
//    Cerc cerc(5,2);
//    cerc.Afisare();

    Forma *formaGenerica2 = new Forma(4);
    formaGenerica2 -> Afisare();

    Forma *cerc2 = new Cerc(3,7);
    cerc2 -> Afisare();

//    Cerc cerc3(5, 3);
//    Forma& forma = cerc3;
//    forma.Afisare();

//    Forma **formeleBunicutei = new Forma*[100];
//    formeleBunicutei[0] = new Cerc(1,3);
//    formeleBunicutei[1] = new Dreptunghi();
//
//    for(int i=0; i<100; i++) formeleBunicutei[i] -> Afisare();
}


Forma * citireForma()
{
    int tipForma;
    Forma * forma;

    cin >> tipForma;
    if(tipForma == 1) {
        Cerc *cerc = new Cerc();
        cerc -> Citire();
        forma = cerc;
    }
    else if(tipForma == 2) {
        Dreptunghi *dreptunghi = new Dreptunghi();
        dreptunghi -> Citire();
        forma = dreptunghi;
    }
    else if(tipForma == 3) {
        Patrat *patrat = new Patrat();
        patrat -> Citire();
        forma = patrat;
    }
    else if(tipForma == 4) {
        Triunghi *triunghi = new Triunghi();
        triunghi -> Citire();
        forma = triunghi;
    }
    return forma;
}

vector<Forma *> citimCeleNFormeInitiale()
{
    int n;
    cin >> n;

    vector<Forma *> forme;

    for(int i=0; i<n; i++)
    {
        forme.push_back(citireForma());
    }

    return forme;
}

int main() {
//    demo();

    vector<Forma *> formeleBunicutei = citimCeleNFormeInitiale();
    for(int i=0; i<formeleBunicutei.size(); i++) formeleBunicutei[i] -> Afisare();

    int comanda = 0;
    int comanda_stop = 5;

    while(comanda != comanda_stop)
    {
        cin >> comanda;
        if(comanda == 1)
        {
            Forma * forma = citireForma();
            formeleBunicutei.push_back(forma);
        }
        else if(comanda == 2)
        {
            int pozitia;
            cin >> pozitia;
            if(0 <= pozitia < formeleBunicutei.size())
            {
                delete formeleBunicutei[pozitia];
                formeleBunicutei.erase(formeleBunicutei.begin() + pozitia);
            }
        }
        else if(comanda == 3)
        {
            double sumGem = 0;
            double sumFrisca = 0;
            for(int i=0; i<formeleBunicutei.size(); i++)
            {
                sumGem += formeleBunicutei[i] -> CantitateGem();
                sumFrisca += formeleBunicutei[i] -> CantitateFrisca();
            }
            cout << "Gem: " << sumGem << " Frisca: " << sumFrisca << endl;
        }
        else if(comanda == 4) {
            for(int i=0; i<formeleBunicutei.size(); i++) formeleBunicutei[i] -> Afisare();
        }
    }

    for(int i=0; i<formeleBunicutei.size(); i++) delete formeleBunicutei[i];

    return 0;
}
