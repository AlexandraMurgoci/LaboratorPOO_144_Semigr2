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

    friend Complex operator* (Complex complex1, Complex complex2);

    friend Complex operator/ (Complex complex1, Complex complex2);

    friend std::istream& operator>> (std::istream& in, Complex& complex);
    friend std::ostream& operator<< (std::ostream& out, const Complex& complex);

    //TODO: meniu interactiv
};

Complex operator+  (Complex complex1, Complex complex2)
{
    Complex result;
    result.m_real = complex1.m_real + complex2.m_real;
    result.m_imaginary = complex1.m_imaginary + complex2.m_imaginary;
    return result;
}

Complex operator* (Complex complex1, Complex complex2)
{
    Complex result;
    result.m_real = complex1.m_real * complex2.m_real - complex1.m_imaginary * complex2.m_imaginary; // i*i = -1
    result.m_imaginary = complex1.m_real * complex2.m_imaginary + complex1.m_imaginary * complex2.m_real;
    return result;
}

Complex operator/(Complex complex1, Complex complex2)
{
    // ((a1*a2+b1*b2)+(a2*b1-a1*b2)i) / a2^2+b2^2
    Complex result;
    double numitor = complex2.m_real * complex2.m_real + complex2.m_imaginary * complex2.m_imaginary;
    result.m_real = (complex1.m_real * complex2.m_real + complex1.m_imaginary * complex2.m_imaginary) / numitor;
    result.m_imaginary = (complex2.m_real * complex1.m_imaginary - complex1.m_real * complex2.m_imaginary) / numitor;
    return result;
}

std::istream& operator>> (std::istream& in, Complex& complex)
{
    in >> complex.m_real >> complex.m_imaginary;
    return in;
}

std::ostream& operator<< (std::ostream& out, const Complex& complex)
{
<<<<<<< HEAD
    //"a", "i*v", "-i*b", "a+i*b", "a-i*b"
    if(complex.m_real && complex.m_imaginary)
    {
        if(complex.m_imaginary > 0)
            out << complex.m_real << "+i*" << complex.m_imaginary;
        else
            out << complex.m_real << "-i*" << complex.m_imaginary;
    }
    else if(complex.m_real == 0)
    {
       if(complex.m_imaginary > 0)
            out << "+i*" << complex.m_imaginary;
       else
            out << "-i*" << complex.m_imaginary;
    }
    else
    {
        out << complex.m_real;
    }
=======
    out << complex.m_real << ' ' << complex.m_imaginary;
    //    "a", "i*a", "-i*a", "a+i*b", "a-i*b"
>>>>>>> parent of 8ab7353... inceput meniu interactiv
    return out;
}

Complex* readNComplexNumbers()
{
    std::cout << "Number of complex numbers to read:" << std::endl;
    int n;
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

int main() {
    Complex complex(1,2.5);
    complex.SetReal(5.2);

    Complex complex2(complex);
    std::cout << complex2.GetReal() << ' ' << complex2.GetImaginary() << std::endl;
    std::cout << complex2.Abs() << std::endl;
    double x,y,z;
    z = x + y;

    //eroare: de explicat peste cateva saptamani in detaliu, daca e nevoie
//    Complex c3(complex + complex2);

    std::cout << (complex + complex2).GetReal() << ' ' << (complex + complex2).GetImaginary() << std::endl;

//    Complex c4;
//    std::cin >> c4;
//    std::cout << c4;
    readNComplexNumbers();
    return 0;
}
