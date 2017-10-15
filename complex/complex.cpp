#include <iostream>
#include "complex.h"


bool Complex::operator==(const Complex& rhs) const
{
    return (abs(re - rhs.re)<0.0001) && (abs(im - rhs.im)<0.0001);
}
Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.im * rhs.re - rhs.im * lhs.re);
}
Complex& Complex::operator*=(const double rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
}
Complex& Complex::operator*=(const Complex& rhs)
{
    double h(re);
    re = rhs.re*h - rhs.im*im;
    im = rhs.re*im + rhs.im*h;
    return *this;
}

Complex& Complex::operator/=(const double rhs)
{
    re /= rhs;
    im /= rhs;
    return *this;
}
Complex& Complex::operator/=(const Complex& rhs)
{
    double h(re); double k(im);
    re = (rhs.re*h + rhs.im*k) / (rhs.re*rhs.re + rhs.im*rhs.im);
    im = (rhs.im*h - rhs.re*k) / (rhs.re*rhs.re + rhs.im*rhs.im);
    return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    return Complex((rhs.re*lhs.re + rhs.im*lhs.im) / (lhs.re*lhs.re + lhs.im*lhs.im), (rhs.im*lhs.re - rhs.re*lhs.im) / (lhs.re*lhs.re + lhs.im*lhs.im));
}
Complex operator+(const double k, const Complex& rhs)
{
    Complex sum(rhs);
    sum += k;
    return sum;
}
Complex& Complex::operator^=(const int k)
{
    Complex result;
    double x;
    x = sqrt((re)*(re)+(im)*(im));
    double f;
    f = atan(im / re);
    double m;
    m = pow(x, k);
    result.re = m*cos(f*k);
    result.im = m*sin(f*k);
    return result;
}
Complex Complex::sopr_()
{
    Complex result;
    result.re = re;
    result.im = -im;
    return result;
}



