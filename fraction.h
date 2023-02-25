#include <iostream>
using namespace std;

class fraction
{
private:
    int numerator, denominator;

public:
    /* Constructores */
    fraction(int _numerador = 1, int _denominador = 1);
    fraction(double);
    fraction(float);
    fraction(int);
    /* Otras funciones */
    int gcd(int, int);
    void fix_symbols();
    void simplify();
    
    fraction to_fraction(double);
    fraction to_fraction(float);
    
    double to_double();
    float to_float();

    /* Funciones de operadores */
    fraction operator+(fraction);
    fraction operator-(fraction);
    fraction operator*(fraction);
    fraction operator/(fraction);

    fraction operator++(int);

    fraction operator+(double);
    fraction operator-(double);
    fraction operator*(double);
    fraction operator/(double);
    
    fraction operator+(float);
    fraction operator-(float);
    fraction operator*(float);
    fraction operator/(float);
    
    fraction operator+(int);
    fraction operator-(int);
    fraction operator*(int);
    fraction operator/(int);

    fraction operator=(double);
    fraction operator=(float);
    fraction operator=(int);
    
    fraction operator+=(fraction);
    fraction operator-=(fraction);
    fraction operator*=(fraction);
    fraction operator/=(fraction);
    
    fraction operator+=(double);
    fraction operator-=(double);
    fraction operator*=(double);
    fraction operator/=(double);
    
    fraction operator+=(float);
    fraction operator-=(float);
    fraction operator*=(float);
    fraction operator/=(float);
    
    fraction operator+=(int);
    fraction operator-=(int);
    fraction operator*=(int);
    fraction operator/=(int);

    /* Operadores logicos */
    bool operator==(fraction);
    bool operator!=(fraction);
    bool operator>(fraction);
    bool operator<(fraction);
    bool operator>=(fraction);
    bool operator<=(fraction);
    
    /* Metodos para convertir de fraction a otros tipos */
    operator double() { return this->to_double(); };
    operator float() { return this->to_float(); };
    operator int() { return ((int) this->to_double()); };

    /* Funciones externas*/
    friend ostream &operator<<(ostream &, fraction);
    
    friend double operator+=(double &, fraction);
    friend double operator-=(double &, fraction);
    friend double operator*=(double &, fraction);
    friend double operator/=(double &, fraction);
    
    friend float operator+=(float &, fraction);
    friend float operator-=(float &, fraction);
    friend float operator*=(float &, fraction);
    friend float operator/=(float &, fraction);
    
    friend int operator+=(int &, fraction);
    friend int operator-=(int &, fraction);
    friend int operator*=(int &, fraction);
    friend int operator/=(int &, fraction);
    friend int operator%=(int &, fraction);
};

fraction operator+(double, fraction);
fraction operator-(double, fraction);
fraction operator*(double, fraction);
fraction operator/(double, fraction);

bool operator==(double, fraction);
bool operator!=(double, fraction);
bool operator>(double, fraction);
bool operator<(double, fraction);
bool operator>=(double, fraction);
bool operator<=(double, fraction);

fraction operator+(float, fraction);
fraction operator-(float, fraction);
fraction operator*(float, fraction);
fraction operator/(float, fraction);

bool operator==(float, fraction);
bool operator!=(float, fraction);
bool operator>(float, fraction);
bool operator<(float, fraction);
bool operator>=(float, fraction);
bool operator<=(float, fraction);

fraction operator+(int, fraction);
fraction operator-(int, fraction);
fraction operator*(int, fraction);
fraction operator/(int, fraction);

bool operator==(int, fraction);
bool operator!=(int, fraction);
bool operator>(int, fraction);
bool operator<(int, fraction);
bool operator>=(int, fraction);
bool operator<=(int, fraction);
