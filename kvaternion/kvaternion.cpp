#include "kvaternion.h"
bool Kvaternion::operator==(const Kvaternion& s)
{
    return ((a_ == s.a_) && (b_ == s.b_) && (c_ == s.c_) && (d_ == s.d_));
}
Kvaternion Kvaternion::operator+=(const Kvaternion& s)
{
    a_ += s.a_;
    b_ += s.b_;
    c_ += s.c_;
    d_ += s.d_;
    return *this;
}
Kvaternion operator+(const Kvaternion& s, const Kvaternion& r)
{
    Kvaternion t(s);
    return (t += r);
}
Kvaternion Kvaternion::operator-=(const Kvaternion& s)
{
    a_ -= s.a_;
    b_ -= s.b_;
    c_ -= s.c_;
    d_ -= s.d_;
    return *this;
}
Kvaternion operator-(const Kvaternion& s, const Kvaternion& r)
{
    Kvaternion t(s);
    return (t -= r);
}
Kvaternion Kvaternion::operator*=(const Kvaternion& s)
{
    Kvaternion r(a_*s.a_ + b_*s.c_, a_*s.b_ + b_*s.d_, c_*s.a_ + d_*s.c_, c_*s.b_ + d_*s.d_);
    a_ = r.a_;
    b_ = r.b_;
    c_ = r.c_;
    d_ = r.d_;
    return *this;
}
Kvaternion operator*(const Kvaternion& s, const Kvaternion& r)
{
    Kvaternion t(s);
    return(t *= r);
}
Kvaternion Kvaternion::operator*=(const double q)
{
    a_ *= q;
    b_ *= q;
    c_ *= q;
    d_ *= q;
    return *this;
}

Kvaternion operator*(const Kvaternion& s, const double q)
{
    Kvaternion t(s);
    return(t *= q);
}

Kvaternion operator*(const double q, const Kvaternion& s)
{
    Kvaternion t(s);
    return(t *= q);
}
Kvaternion Kvaternion::operator/=(const double q)
{
    a_ /= q;
    b_ /= q;
    c_ /= q;
    d_ /= q;
    return *this;
}

Kvaternion operator/(const Kvaternion& s, const double q)
{
    Kvaternion t(s);
    return(t /= q);
}
double Kvaternion::opredelitel()
{
    return(a_*d_ - b_*c_);
}
Kvaternion Kvaternion::transponirovanie()
{
    double k(c_);
    c_ = d_;
    d_ = k;
    return *this;
}
Kvaternion Kvaternion::inverse()
{
    Kvaternion t(a_, b_, c_, d_);
    double det = t.opredelitel();
    Kvaternion dopolnenie(d_, -b_, -c_, a_);
    t = det*dopolnenie;
    a_ = t.a_; b_ = t.b_; c_ = t.c_; d_ = t.d_;
    return *this;
}
Kvaternion operator/(const Kvaternion& s, const Kvaternion& r)
{
    Kvaternion t(s);
    Kvaternion h(r);
    h.inverse();
    return (t *= h);
}