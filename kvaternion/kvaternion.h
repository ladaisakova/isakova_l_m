#ifndef KVATERNION_H_1910
#define KVATERNION_H_1910

#include<iostream>
struct Kvaternion
{
public:
    Kvaternion() = default;
    Kvaternion::Kvaternion(const double a, const double b, const double c, const double d) : a_(a), b_(b), c_(c), d_(d)
    {

    }
    ~Kvaternion() = default;
    Kvaternion(const Kvaternion& s) : a_(s.a_), b_(s.b_), c_(s.c_), d_(s.d_)
    {
    }
    Kvaternion operator=(const Kvaternion& s)
    {
        a_ = s.a_;
        b_ = s.b_;
        c_ = s.c_;
        d_ = s.d_;
        return *this;
    }
    double a_{ 0.0 };
    double b_{ 0.0 };
    double c_{ 0.0 };
    double d_{ 0.0 };

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    static const char left{ '{' };
    static const char separator{ ',' };
    static const char right{ '}' };

    bool operator==(const Kvaternion& s);
    bool operator!=(const Kvaternion& s) { return !operator==(s); }
    Kvaternion operator+=(const Kvaternion& s);
    Kvaternion operator-=(const Kvaternion& s);
    Kvaternion operator*=(const Kvaternion& s);
    Kvaternion operator*=(const double q);
    Kvaternion operator/=(const double q);
    double opredelitel();
    Kvaternion transponirovanie();
    Kvaternion inverse();

};
Kvaternion operator+(const Kvaternion& s, const Kvaternion& r);
Kvaternion operator-(const Kvaternion& s, const Kvaternion& r);
Kvaternion operator*(const Kvaternion& s, const Kvaternion& r);
Kvaternion operator*(const Kvaternion& s, const double q);
Kvaternion operator*(const double q, const Kvaternion& s);
Kvaternion operator/(const Kvaternion& s, const double q);
Kvaternion operator/(const Kvaternion& s, const Kvaternion& r);
inline std::ostream& operator<<(std::ostream& ostrm, const Kvaternion& rhs)
{
    return rhs.writeTo(ostrm);
}
inline std::istream& operator >> (std::istream& istrm, Kvaternion& rhs)
{
    return rhs.readFrom(istrm);
}

#endif