#include <iostream>

using namespace std;

template <typename T>
T GetMax(T x, T y)
{
    return (x > y) ? x : y;
}

class A
{
    int m_x;
public:
    A(int x): m_x(x) {}
    int GetX() const {return m_x;}
    A& operator=(const A& a)
    {
        //conditie necesara daca am memorie dinamica la care trebuie sa dau delete inainte sa o realoc
        if(this != &a) {
            m_x = a.m_x;
        }
        return *this;
    }
    virtual ~A() {}

    friend istream &operator>> (istream& in, A& a);
};

ostream &operator<<(ostream& out, const A& a)
{
    out << a.GetX();
    return out;
}

bool operator<= (A a, A b)
{
    return (a.GetX() <= b.GetX());
}

template <class T>
bool operator> (T a, T b)
{
    return !(a <= b);
}

istream &operator>> (istream& in, A& a)
{
    in >> a.m_x;
    return in;
}

class B: public A
{
    int m_y;
public:
    B(int x, int y): A(x), m_y(y) {}
    void Afisare() {cout << GetX() << " " << m_y;}

    friend istream &operator>> (istream& in, B& b);
};

istream &operator>> (istream& in, B& b)
{
    in >> dynamic_cast<A&>(b);
    in >> b.m_y;
    return in;
}

int main() {
//    int x = 5, y = 6;
//    cout << GetMax(x, y) << endl;
//    A a(5), b(10);
//    cout << GetMax(a, b);
//    a=a;
    B b(0,0);
    cin >> b;
    b.Afisare();
    return 0;
}
