#include <iostream>
#include <stdexcept>
#include <sstream>
#include "fraction.h"

using namespace std;

/* Constructores */

fraction::fraction(int _numerator, int _denominator)
{
    if (_denominator == 0)
        throw invalid_argument("The fraction denominator must be different than 0");
    numerator = _numerator;
    denominator = _denominator;
    fix_symbols();
}

fraction::fraction(double initializer)
{
    *this = initializer;
}

fraction::fraction(float initializer)
{
    *this = initializer;
}

fraction::fraction(int initializer)
{
    *this = initializer;
}

/* Funciones para simplificar */

int fraction::gcd(int a, int b)
{
    // Se convierten los argumentos a positivos en caso de que no lo sean
    a = a < 0 ? a * -1 : a;
    b = b < 0 ? b * -1 : b;

    int menor = a < b ? a : b; // Se determina el menor
    /* Se empieza a iterar desde el menor descendentemente hasta 1 */
    int iterador = menor;
    while (iterador >= 1)
    {
        /* Si el iterador divide de forma exacta a los dos numeros */
        if (a % iterador == 0 && b % iterador == 0)
            return iterador; // es el maximo comun divisor

        if (iterador == menor)
            iterador /= 2; // Si es la primera iteracion se divide entre 2
        else
            iterador--; // De lo contrario se va restando 1 hasta llegar a 1
    }
    // Si no se encontro un mcd
    return 1;
}

void fraction::fix_symbols()
{
    if (denominator > 0)
        return;
    numerator *= -1;
    denominator *= -1;
}

void fraction::simplify()
{
    fix_symbols();
    // Se obtiene el maximo comun divisor
    int gcd = fraction::gcd(numerator, denominator);
    // Se divide tanto el numerador como el denominador entre el m.c.d
    numerator /= gcd;
    denominator /= gcd;
}

fraction fraction::to_fraction(double initializer)
{
    fraction result;
    int converted = initializer;
    double temp_converted = initializer;
    int multiplier = 1;
    while (converted != temp_converted)
    {
        multiplier *= 10;
        temp_converted = initializer * multiplier;
        converted = temp_converted;
    }
    result.numerator = converted;
    result.denominator = multiplier;
    result.simplify();
    return result;
}

fraction fraction::to_fraction(float initializer)
{
    fraction result;
    int converted = initializer;
    float temp_converted = initializer;
    int multiplier = 1;
    while (converted != temp_converted)
    {
        multiplier *= 10;
        temp_converted = initializer * multiplier;
        converted = temp_converted;
    }
    result.numerator = converted;
    result.denominator = multiplier;
    result.simplify();
    return result;
}

double fraction::to_double()
{
    return ((double)numerator / (double)denominator);
}

float fraction::to_float()
{
    return ((float)numerator / (float)denominator);
}

/* Funciones de operadores */

fraction fraction::operator+(fraction addend)
{
    fraction result;
    // Suma de fracciones de igual denominador
    if (denominator == addend.denominator)
    {
        result.numerator = numerator + addend.numerator;
        result.denominator = denominator;
        result.simplify();
        return result;
    }

    // Suma de fracciones de diferente denominador
    result.numerator = numerator * addend.denominator + denominator * addend.numerator;
    result.denominator = denominator * addend.denominator;
    result.simplify();
    return result;
}

fraction fraction::operator-(fraction subtrahend)
{
    fraction result;
    // Resta de fracciones de igual denominador
    if (denominator == subtrahend.denominator)
    {
        result.numerator = numerator - subtrahend.numerator;
        result.denominator = denominator;
        result.simplify();
        return result;
    }

    // Resta de fracciones de diferente denominador
    result.numerator = numerator * subtrahend.denominator - denominator * subtrahend.numerator;
    result.denominator = denominator * subtrahend.denominator;
    result.simplify();
    return result;
}

fraction fraction::operator*(fraction multiplicand)
{
    fraction result;
    // Multiplicacion de fracciones
    result.numerator = numerator * multiplicand.numerator;
    result.denominator = denominator * multiplicand.denominator;
    result.simplify();
    return result;
}

fraction fraction::operator/(fraction divisor)
{
    fraction result;
    // Multiplicacion de fracciones
    result.numerator = numerator * divisor.denominator;
    result.denominator = denominator * divisor.numerator;
    result.simplify();
    return result;
}

fraction fraction::operator+(double addend)
{
    return *this + fraction(addend);
}
fraction fraction::operator-(double subtrahend)
{
    return *this - fraction(subtrahend);
}
fraction fraction::operator*(double multiplicand)
{
    return *this * fraction(multiplicand);
}
fraction fraction::operator/(double divisor)
{
    return *this / fraction(divisor);
}

fraction fraction::operator+(float addend)
{
    return *this + fraction(addend);
}
fraction fraction::operator-(float subtrahend)
{
    return *this - fraction(subtrahend);
}
fraction fraction::operator*(float multiplicand)
{
    return *this * fraction(multiplicand);
}
fraction fraction::operator/(float divisor)
{
    return *this / fraction(divisor);
}

fraction fraction::operator+(int addend)
{
    return *this + addend;
}
fraction fraction::operator-(int subtrahend)
{
    return *this - subtrahend;
}
fraction fraction::operator*(int multiplicand)
{
    return *this * multiplicand;
}
fraction fraction::operator/(int divisor)
{
    return *this / divisor;
}

fraction fraction::operator=(double initializer)
{
    fraction result = to_fraction(initializer);
    numerator = result.numerator;
    denominator = result.denominator;
    return *this;
}

fraction fraction::operator=(float initializer)
{
    fraction result = to_fraction(initializer);
    numerator = result.numerator;
    denominator = result.denominator;
    return *this;
}

fraction fraction::operator=(int initializer)
{
    numerator = initializer;
    denominator = 1;
    return *this;
}

fraction fraction::operator+=(fraction operate)
{
    *this = *this + operate;
    return *this;
}

fraction fraction::operator-=(fraction operate)
{
    *this = *this - operate;
    return *this;
}

fraction fraction::operator*=(fraction operate)
{
    *this = *this * operate;
    return *this;
}

fraction fraction::operator/=(fraction operate)
{
    *this = *this / operate;
    return *this;
}

fraction fraction::operator+=(double operate)
{
    *this = *this + fraction(operate);
    return *this;
}

fraction fraction::operator-=(double operate)
{
    *this = *this - fraction(operate);
    return *this;
}

fraction fraction::operator*=(double operate)
{
    *this = *this * fraction(operate);
    return *this;
}

fraction fraction::operator/=(double operate)
{
    *this = *this / fraction(operate);
    return *this;
}

fraction fraction::operator+=(float operate)
{
    *this = *this + fraction(operate);
    return *this;
}

fraction fraction::operator-=(float operate)
{
    *this = *this - fraction(operate);
    return *this;
}

fraction fraction::operator*=(float operate)
{
    *this = *this * fraction(operate);
    return *this;
}

fraction fraction::operator/=(float operate)
{
    *this = *this / fraction(operate);
    return *this;
}

fraction fraction::operator+=(int operate)
{
    *this = *this + operate;
    return *this;
}

fraction fraction::operator-=(int operate)
{
    *this = *this - operate;
    return *this;
}

fraction fraction::operator*=(int operate)
{
    *this = *this * operate;
    return *this;
}

fraction fraction::operator/=(int operate)
{
    *this = *this / operate;
    return *this;
}

bool fraction::operator==(fraction to_compare)
{
    return ((numerator == to_compare.numerator) && (denominator == to_compare.denominator));
}

bool fraction::operator!=(fraction to_compare)
{
    return (!(*this == to_compare));
}

bool fraction::operator>(fraction to_compare)
{
    return (this->to_double() > to_compare.to_double());
}

bool fraction::operator<(fraction to_compare)
{
    return (this->to_double() < to_compare.to_double());
}

bool fraction::operator>=(fraction to_compare)
{
    return (*this > to_compare || *this == to_compare);
}

bool fraction::operator<=(fraction to_compare)
{
    return (*this < to_compare || *this == to_compare);
}

/* Funciones externas */

ostream &operator<<(ostream &out, fraction instance)
{
    out << instance.numerator << " / " << instance.denominator;
    return out;
}

fraction operator+(double to_convert, fraction addend)
{
    return fraction(to_convert) + addend;
}
fraction operator-(double to_convert, fraction subtrahend)
{
    return fraction(to_convert) - subtrahend;
}
fraction operator*(double to_convert, fraction multiplicand)
{
    return fraction(to_convert) * multiplicand;
}
fraction operator/(double to_convert, fraction divisor)
{
    return fraction(to_convert) / divisor;
}

fraction fraction::operator++(int)
{
    fraction current = *this;
    *this += 1;
    return current;
}

double operator+=(double &num, fraction addend)
{
    num += addend.to_double();
    return num;
}

double operator-=(double &num, fraction subtrahend)
{
    num -= subtrahend.to_double();
    return num;
}

double operator*=(double &num, fraction multiplicand)
{
    num *= multiplicand.to_double();
    return num;
}

double operator/=(double &num, fraction divisor)
{
    num /= divisor.to_double();
    return num;
}

bool operator==(double num, fraction to_compare)
{
    return (fraction(num) == to_compare);
}
bool operator!=(double num, fraction to_compare)
{
    return (fraction(num) != to_compare);
}
bool operator>(double num, fraction to_compare)
{
    return (fraction(num) > to_compare);
}
bool operator<(double num, fraction to_compare)
{
    return (fraction(num) < to_compare);
}
bool operator>=(double num, fraction to_compare)
{
    return (fraction(num) >= to_compare);
}
bool operator<=(double num, fraction to_compare)
{
    return (fraction(num) <= to_compare);
}

fraction operator+(float to_convert, fraction addend)
{
    return fraction(to_convert) + addend;
}
fraction operator-(float to_convert, fraction subtrahend)
{
    return fraction(to_convert) - subtrahend;
}
fraction operator*(float to_convert, fraction multiplicand)
{
    return fraction(to_convert) * multiplicand;
}
fraction operator/(float to_convert, fraction divisor)
{
    return fraction(to_convert) / divisor;
}

bool operator==(float num, fraction to_compare)
{
    return (fraction(num) == to_compare);
}
bool operator!=(float num, fraction to_compare)
{
    return (fraction(num) != to_compare);
}
bool operator>(float num, fraction to_compare)
{
    return (fraction(num) > to_compare);
}
bool operator<(float num, fraction to_compare)
{
    return (fraction(num) < to_compare);
}
bool operator>=(float num, fraction to_compare)
{
    return (fraction(num) >= to_compare);
}
bool operator<=(float num, fraction to_compare)
{
    return (fraction(num) <= to_compare);
}

float operator+=(float &num, fraction addend)
{
    num += addend.to_float();
    return num;
}

float operator-=(float &num, fraction subtrahend)
{
    num -= subtrahend.to_float();
    return num;
}

float operator*=(float &num, fraction multiplicand)
{
    num *= multiplicand.to_float();
    return num;
}

float operator/=(float &num, fraction divisor)
{
    num /= divisor.to_float();
    return num;
}

fraction operator+(int to_convert, fraction addend)
{
    return to_convert + addend;
}
fraction operator-(int to_convert, fraction subtrahend)
{
    return to_convert - subtrahend;
}
fraction operator*(int to_convert, fraction multiplicand)
{
    return to_convert * multiplicand;
}
fraction operator/(int to_convert, fraction divisor)
{
    return to_convert / divisor;
}

bool operator==(int num, fraction to_compare)
{
    return (fraction((float)num) == to_compare);
}
bool operator!=(int num, fraction to_compare)
{
    return (fraction((float)num) != to_compare);
}
bool operator>(int num, fraction to_compare)
{
    return (fraction((float)num) > to_compare);
}
bool operator<(int num, fraction to_compare)
{
    return (fraction((float)num) < to_compare);
}
bool operator>=(int num, fraction to_compare)
{
    return (fraction((float)num) >= to_compare);
}
bool operator<=(int num, fraction to_compare)
{
    return (fraction((float)num) <= to_compare);
}

int operator+=(int &num, fraction addend)
{
    num += int(addend.to_double());
    return num;
}

int operator-=(int &num, fraction subtrahend)
{
    num -= int(subtrahend.to_double());
    return num;
}

int operator*=(int &num, fraction multiplicand)
{
    num *= int(multiplicand.to_double());
    return num;
}

int operator/=(int &num, fraction divisor)
{
    num /= int(divisor.to_double());
    return num;
}

int operator%=(int &num, fraction divisor)
{
    num %= int(divisor.to_double());
    return num;
}
