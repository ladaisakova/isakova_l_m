#include "rational.h"
#include <iostream>

double e = 0.0001;

int nod(int& a, int& b)
{
    int c, d, a1, b1;
    c = a; d = b;
    a1 = a;
    b1 = b;
    while (c%d != 0)
        if (a1 >= b1)
        {
            c = a1%b1;
            if (c == 0) { return a; break; }
            d = b1%c;
            if (d == 0) { return c; break; }
            a1 = c;
            b1 = d;
        }
        else {
            c = b1%a1;
            if (c == 0) { return a; break; }
            d = a1%c;
            if (d == 0) { return c; break; }
            a1 = c;
            b1 = d;
        }
}
void Rational::correct(Rational& t)
{
    int k = nod(t.num_, t.denum_);
    t = Rational(t.num_ / k, t.denum_ / k);
    if (t.denum_ < 0)
    {
        t.denum_ *= -1;
        t.num_ *= -1;
    }
}
Rational& Rational::operator+=(const Rational& rhs)
{
    num_ = num_ * rhs.denum_ + rhs.num_ * denum_;
    denum_ = denum_ * rhs.denum_;
    correct(*this);
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    num_ = num_ * rhs.denum_ - rhs.num_ * denum_;
    denum_ = denum_ * rhs.denum_;
    correct(*this);
    return *this;
}
Rational operator-(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.num_ * rhs.denum_ - rhs.num_ * lhs.denum_, lhs.denum_ * rhs.denum_);
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.num_ * rhs.num_, lhs.denum_ * rhs.denum_);
}
Rational& Rational::operator*=(const Rational& rhs)
{
    num_ = rhs.num_ * num_;
    denum_ = rhs.denum_ * denum_;
    correct(*this);
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
    num_ = num_ * rhs.denum_;
    denum_ = rhs.num_ * denum_;
    correct(*this);
    return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.num_ * rhs.denum_, lhs.denum_ * rhs.num_);
}
bool Rational::operator>(const Rational& rhs)
{
    return((num_ * rhs.denum_ - rhs.num_ * denum_) >= e);
}
bool Rational::operator<(const Rational& rhs)
{
    return((num_ * rhs.denum_ < rhs.num_ * denum_) <= -e);
}
bool Rational::operator==(const Rational& rhs)
{
    return(abs(num_ * rhs.denum_ - rhs.num_ * denum_)< e);
}
Rational& Rational::operator^(const int k)
{
    Rational result;
    result.num_ = pow(num_, k);
    result.denum_ = pow(denum_, k);
    correct(result);
    return result;
}
Rational& Rational::operator+=(const double k)
{
    Rational b;
    double a(k);
    double t;
    int i = 1;
    double j = modf(a, &t);
    while (j < 1 && j != 0)
    {
        a *= 10;
        i *= 10;
        j = modf(a, &t);
    }
    b = Rational(a, i);
    num_ = num_ * i + a * denum_;
    denum_ = denum_ * i;
    correct(*this);
    return *this;
}

Rational& Rational::operator-=(const double k)
{
    Rational b;
    double a(k);
    double t;
    int i = 1;
    double j = modf(a, &t);
    while (j < 1 && j != 0)
    {
        a *= 10;
        i *= 10;
        j = modf(a, &t);
    }
    b = Rational(a, i);
    num_ = num_ * i - a * denum_;
    denum_ = denum_ * i;
    correct(*this);
    return *this;
}
Rational& Rational::operator*=(const double k)
{
    Rational b;
    double a(k);
    double t;
    int i = 1;
    double j = modf(a, &t);
    while (j < 1 && j != 0)
    {
        a *= 10;
        i *= 10;
        j = modf(a, &t);
    }
    b = Rational(a, i);
    num_ = a * num_;
    denum_ = i * denum_;
    correct(*this);
    return *this;
}
Rational& Rational::operator/=(const double k)
{
    Rational b;
    double a(k);
    double t;
    int i = 1;
    double j = modf(a, &t);
    while (j < 1 && j != 0)
    {
        a *= 10;
        i *= 10;
        j = modf(a, &t);
    }
    b = Rational(a, i);
    num_ = i * num_;
    denum_ = a * denum_;
    correct(*this);
    return *this;
}