#include <iostream>
#include <vector>

using namespace std;

class Forma
{
    static const double S_MAX_INALTIME;
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
    virtual istream &Citire(istream& in) = 0;
    virtual double Aria() = 0;
    double Volum() {return m_inaltime * Aria();}
    double Suprafata()
    {
        //TODO
        return 0;
    }
    double CantitateGem()
    {
        return Volum() * 2;
    }
    double CantitateFrisca()
    {
        //GRESIT!: defapt cantitatea de frisca depinde de suprafata
        //TODO: implementeaza cu suprafata
        return Volum();
    }
    virtual ~Forma(){}
    static double GetMaxInaltime() {return S_MAX_INALTIME;}
};

const double Forma::S_MAX_INALTIME = 10;

class Cerc: public Forma
{
    double m_raza;
    static int s_nr_cercuri;
public:
    Cerc(): Forma(), m_raza(0) {s_nr_cercuri++;}
    Cerc(double inaltime, double raza): Forma(inaltime), m_raza(raza) {s_nr_cercuri++;}
    Cerc(const Cerc& cerc): m_raza(cerc.m_raza), Forma(cerc.m_inaltime) {s_nr_cercuri++;}
    ~Cerc() {s_nr_cercuri--;}
    double GetRaza() {return m_raza;}
    void Afisare()
    {
        std::cout << "Cerc: inaltime " << m_inaltime << " raza: " << m_raza << std::endl;
    }
    istream &Citire(istream& in)
    {
        in >> m_inaltime >> m_raza;
        if(m_inaltime > Forma::GetMaxInaltime()) cout << "Inaltime mai mare decat max<<endl";
        return in;
    }
    double Aria()
    {
        return 3.14 * m_raza * m_raza;
    }
    static int GetNrCercuri() {return s_nr_cercuri;}
};

int Cerc::s_nr_cercuri = 0;

class Dreptunghi: public Forma
{
    double m_latura_mica;
    double m_latura_mare;
public:
    istream &Citire(istream& in)
    {
        in >> m_inaltime >> m_latura_mica >> m_latura_mare;
        return in;
    }
    void Afisare()
    {
        std::cout << "Dreptunghi: inaltime " << m_inaltime << " latura mica: " << m_latura_mica << " latura mare: " << m_latura_mare << std::endl;
    }
    double Aria()
    {
        return m_latura_mica * m_latura_mare;
    }
};

class Patrat: public Forma
{
    double m_latura;
public:
    double GetLatura() {return m_latura;}
    istream &Citire(istream& in)
    {
        in >> m_inaltime >> m_latura;
        return in;
    }
    void Afisare()
    {
        std::cout << "Patrat: inaltime " << m_inaltime << " latura: " << m_latura << std::endl;
    }
    double Aria()
    {
        return m_latura * m_latura;
    }
};

class Triunghi: public Forma
{
    double m_cateta_mica;
    double m_cateta_mare;
public:
    istream &Citire(istream& in)
    {
        in >> m_inaltime >> m_cateta_mica >> m_cateta_mare;
        return in;
    }
    void Afisare()
    {
        std::cout << "Triunghi: inaltime " << m_inaltime << " cateta mica: " << m_cateta_mica << " cateta mare: " << m_cateta_mare << std::endl;
    }
    double Aria()
    {
        return m_cateta_mica * m_cateta_mare;
    }
};

istream& operator>>(std::istream& in, Forma& forma) {
    return forma.Citire(in);
}

void demo()
{
    //    Forma formaGenerica(5);
//    formaGenerica.Afisare();
//
//    Cerc cerc(5,2);
//    cerc.Afisare();

//    Forma *formaGenerica2 = new Forma(4);
//    formaGenerica2 -> Afisare();

//    Forma *cerc2 = new Cerc(3,7);
//    cerc2 -> Afisare();

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
        cerc -> Citire(cin);
        forma = cerc;
    }
    else if(tipForma == 2) {
        Dreptunghi *dreptunghi = new Dreptunghi();
        dreptunghi -> Citire(cin);
        forma = dreptunghi;
    }
    else if(tipForma == 3) {
        Patrat *patrat = new Patrat();
        patrat -> Citire(cin);
        forma = patrat;
    }
    else if(tipForma == 4) {
        Triunghi *triunghi = new Triunghi();
        triunghi -> Citire(cin);
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

void MeniuInteractiv()
{
    vector<Forma *> formeleBunicutei = citimCeleNFormeInitiale();
    for(int i=0; i<formeleBunicutei.size(); i++) formeleBunicutei[i] -> Afisare();

    int comanda = 0;
    int comanda_stop = 6;

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
        else if(comanda == 5) {
            cout << Cerc::GetNrCercuri() << endl;
        }
    }

    for(int i=0; i<formeleBunicutei.size(); i++) delete formeleBunicutei[i];
}

void demo1()
{
    Forma *forma = new Cerc(1,2);
    //vreau forma -> GetRaza()

    if(Cerc *cerc = dynamic_cast<Cerc *>(forma))
    {
        cout << cerc -> GetRaza();
    }

    if(Patrat *patrat = dynamic_cast<Patrat *>(forma))
    {
        cout << patrat -> GetLatura();
    }
}

void demo2(){
    Cerc cerc;
    cin >> cerc;
    cerc.Afisare();
    cout << endl;

    Dreptunghi dreptunghi;
    cin >> dreptunghi;
    dreptunghi.Afisare();
}

class DemoStaticVariable
{
public:
    DemoStaticVariable() {cout << "CI" << endl;}
    ~DemoStaticVariable() {cout << "D" << endl;}
};

int main() {
//    demo();
//    MeniuInteractiv();
//    demo1();
//    demo2();

    if(0 == 0)
    {
        static DemoStaticVariable obj;
    }

    cout << "Finalul programului" << endl;

    return 0;
}
