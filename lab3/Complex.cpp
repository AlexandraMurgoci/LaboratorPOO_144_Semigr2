#include <iostream>
#include <cmath>

class Complex {
    double m_real;
    double m_imaginary;
public:
    Complex(){}
    Complex(double real): m_real(real), m_imaginary(0) {}
    Complex(double real, double imaginary): m_real(real), m_imaginary(imaginary){}
    Complex(Complex &complex): m_real(complex.m_real), m_imaginary(complex.m_imaginary) {}
    ~Complex(){}

    double GetReal() {return m_real;}
    double GetImaginary() {return m_imaginary;}
    void SetReal(double real) {m_real = real;}
    void SetImaginary(double imaginary) {m_imaginary = imaginary;}

    double Abs()
    {
        return sqrt(m_real * m_real + m_imaginary * m_imaginary);
    }

    //TODO: operatorul +
//    Complex operator+ (Complex complex)
//    {
//        Complex result;
//        result.m_real = m_real + complex.m_real;
//        result.m_imaginary = m_imaginary + complex.m_imaginary;
//        return result;
//    }
    friend Complex operator+ (Complex complex1, Complex complex2);

    //TODO: operatorul *

    //TODO: operatorul /

    friend std::istream& operator>> (std::istream& in, Complex& complex);
    friend std::ostream& operator<< (std::ostream& out, const Complex& complex);
};

Complex operator+  (Complex complex1, Complex complex2)
{
    Complex result;
    result.m_real = complex1.m_real + complex2.m_real;
    result.m_imaginary = complex1.m_imaginary + complex2.m_imaginary;
    return result;
}

std::istream& operator>> (std::istream& in, Complex& complex)
{
    in >> complex.m_real >> complex.m_imaginary;
    return in;
}

std::ostream& operator<< (std::ostream& out, const Complex& complex)
{
    //TODO:
    out << complex.m_real << ' ' << complex.m_imaginary;
    //    "a", "i*a", "-i*a", "a+i*b", "a-i*b"
    return out;
}

Complex* readNComplexNumbers(int &n)
{
    std::cout << "Number of complex numbers to read:" << std::endl;
    std::cin >> n;
    std::cout << "Write n complex numbers." << std::endl;
    Complex *numbers = new Complex[n];
    for(int i=0; i<n; i++) {
        std::cin>>numbers[i];
    }

    std:: cout << "You read the following " << n << " numbers:" <<std::endl;
    for(int i=0; i<n; i++) {
        std::cout<<numbers[i]<<std::endl;
    }

    return numbers;
}

void printMenuOptions() {
    std::cout << "1. Cititi, memorati si afisati n numere complexe." << std::endl;
    std::cout << "2. Adunati 2 numere din cele citire mai devreme." << std::endl;
    std::cout << "3. Rulati demo pentru si inmultire impartire." << std::endl;
    std::cout << "4. Oprire" << std::endl;
    std::cout << std::endl;
}

void interactiveMenu() {
    std::cout << "Alegeti dintre urmatoarele optiuni: " << std::endl;
    printMenuOptions();
    int option = 0;
    int exit_option = 4;
    int n = 0;
    Complex *numbers = nullptr;

    std::cin >> option;
    while(option != exit_option) {
        if(option == 1)
        {
            numbers = readNComplexNumbers(n);
        }
        else if(option == 2)
        {
            std::cout << "Scrieti pozitiile celor 2 numere in lista:" << std::endl;
            int poz1, poz2;
            std::cin >> poz1 >> poz2;
            if(poz1 >= n || poz2 >= n)
            {
                std::cout << "Pozitii invalide! Nu se poate aduna." << std::endl;
            }
            else
            {
                std::cout << numbers[poz1] + numbers[poz2];
            }
        }
        else if(option == 3)
        {
            //TODO
            //de completat dupa terminarea operatorilor
        }

        //reafisam meniul
        std::cout << std::endl;
        printMenuOptions();
        std::cin >> option;
    }
}

int main() {
//    Complex complex(1,2.5);
//    complex.SetReal(5.2);
//
//    Complex complex2(complex);
//    std::cout << complex2.GetReal() << ' ' << complex2.GetImaginary() << std::endl;
//    std::cout << complex2.Abs() << std::endl;
//    double x,y,z;
//    z = x + y;

    //eroare: de explicat peste cateva saptamani in detaliu, daca e nevoie
//    Complex c3(complex + complex2);

//    std::cout << (complex + complex2).GetReal() << ' ' << (complex + complex2).GetImaginary() << std::endl;

//    Complex c4;
//    std::cin >> c4;
//    std::cout << c4;
//    readNComplexNumbers();
    interactiveMenu();
    return 0;
}
