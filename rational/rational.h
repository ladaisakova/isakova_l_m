#ifndef RATIONAL_H_2109
#define RATIONAL_H_2109
#include <iosfwd>
#include <iostream>

class Rational
{
public:
    Rational() = default;
    Rational(const int num) : num_(num) {}
    Rational::Rational(const int num, const int denum) : num_(num), denum_(denum)
    {
        if (denum == 0)
        {
            throw std::invalid_argument("Error!");
        }
    }
    void correct(Rational& t);
    ~Rational() = default;
    bool operator==(const Rational& rhs);
    bool operator!=(const Rational& rhs) { return !operator==(rhs); }
    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
    Rational& operator^(const int k);
    Rational& operator+=(const double k);
    Rational& operator-=(const double k);
    Rational& operator*=(const double k);
    Rational& operator/=(const double k);
    bool operator>(const Rational& rhs);
    bool operator<(const Rational& rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

public:
    int num_{ 0 };
    int denum_{ 1 };

    static const char leftBrace{ '{' };
    static const char separator{ '/' };
    static const char rightBrace{ '}' };
};
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}
#endif