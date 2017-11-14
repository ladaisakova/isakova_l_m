#ifndef VEC3DT_H_1110
#define VEC3DT_H_1110
#include <iosfwd>

template<typename T>
struct Vec3dt
{
public:
    Vec3dt<T>() = default;
    Vec3dt<T>(const T x, const T y, const T z) : x_(x), y_(y), z_(z)
    {
    }
    ~Vec3dt<T>() = default;
    Vec3dt(const Vec3dt<T>& v) : x_(v.x_), y_(v.y_), z_(v.z_)
    {
    }
    Vec3dt operator=(const Vec3dt<T>& v)
    {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
        return *this;
    }
    bool operator==(const Vec3dt<T>& rhs);
    bool operator!=(const Vec3dt<T>& rhs);
    double mod();
    double skal(Vec3dt<T>& t);
    Vec3dt<T> vec(Vec3dt<T>& t);
    double ugol(Vec3dt<T>& t);
    Vec3dt<T>& operator+=(const Vec3dt<T>& rhs);
    Vec3dt<T>& operator-=(const Vec3dt<T>& rhs);
    Vec3dt<T>& operator*=(const int k);
    Vec3dt<T>& operator/=(const int k);
    Vec3dt<T>& operator*=(const double k);
    Vec3dt<T>& operator/=(const double k);


    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

public:
    T x_{ 0 };
    T y_{ 0 };
    T z_{ 0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

template<typename T>
inline std::ostream& operator<<(std::ostream& ostrm, const Vec3dt<T>& rhs)
{
    return rhs.writeTo(ostrm);
}
template<typename T>
inline std::istream& operator >> (std::istream& istrm, Vec3dt<T>& rhs)
{
    return rhs.readFrom(istrm);
}

template<typename T>
bool Vec3dt<T>::operator==(const Vec3dt<T>& rhs)
{
    return ((abs(rhs.x_ - x_) < 0.001) && (abs(rhs.y_ - y_) < 0.001) && (abs(rhs.z_ - z_) < 0.001));
}
template<typename T>
bool Vec3dt<T>::operator!=(const Vec3dt<T>& rhs)
{
    return ((abs(rhs.x_ - x_) > 0.001) || (abs(rhs.y_ - y_) > 0.001) || (abs(rhs.z_ - z_) > 0.001));
}
template<typename T>
double Vec3dt<T>::mod()
{
    return double(sqrt(x_ * x_ + y_ * y_ + z_ * z_));
}
template<typename T>
double Vec3dt<T>::skal(Vec3dt<T>& t)
{
    return double(t.x_ * x_ + t.y_ * y_ + t.z_ * z_);
}
template<typename T>
Vec3dt<T> Vec3dt<T>::vec(Vec3dt<T>& t)
{
    Vec3dt<T> vec;
    vec.x_ = y_ * t.z_ - z_ * t.y_;
    vec.y_ = z_ * t.x_ - x_ * t.z_;
    vec.z_ = x_ * t.y_ - y_ * t.x_;
    return vec;
}
template<typename T>
double Vec3dt<T>::ugol(Vec3dt<T>& t)
{
    Vec3dt<T> h;
    double t1, h1, sk, cos, alfa;
    t1 = t.mod();
    h.x_ = x_; h.y_ = y_; h.z_ = z_;
    h1 = h.mod();
    sk = h.skal(t);
    cos = sk / (t1 * h1);
    alfa = acos(cos);
    return alfa;
}
template<typename T>
Vec3dt<T>& Vec3dt<T>:: operator+=(const Vec3dt<T>& rhs)
{
    x_ = rhs.x_ + x_;
    y_ = rhs.y_ + y_;
    z_ = rhs.z_ + z_;
    return *this;
}
template<typename T>
Vec3dt<T> operator+(const Vec3dt<T>& lhs, const Vec3dt<T>& rhs)
{
    Vec3dt<T> sum(lhs);
    sum += rhs;
    return sum;
}
template<typename T>
Vec3dt<T> operator-(const Vec3dt<T>& lhs, const Vec3dt<T>& rhs)
{
    Vec3dt<T> minus(lhs);
    minus -= rhs;
    return minus;
}
template<typename T>
Vec3dt<T> operator*(const Vec3dt<T>& lhs, const T d)
{
    Vec3dt<T> u(lhs);
    u *= d;
    return u;
}
template<typename T>
Vec3dt<T> operator/(const Vec3dt<T>& lhs, const T d)
{
    Vec3dt<T> del(lhs);
    del /= d;
    return del;
}
template<typename T>
Vec3dt<T>& Vec3dt<T>:: operator-=(const Vec3dt<T>& rhs)
{
    x_ = x_ - rhs.x_;
    y_ = y_ - rhs.y_;
    z_ = z_ - rhs.z_;
    return *this;
}
template<typename T>
Vec3dt<T>& Vec3dt<T>:: operator*=(const int k)
{
    x_ = x_ * k;
    y_ = y_ * k;
    z_ = z_ * k;
    return *this;
}
template<typename T>
Vec3dt<T>& Vec3dt<T>:: operator/=(const int k)
{
    x_ = x_ / k;
    y_ = y_ / k;
    z_ = z_ / k;
    return *this;
}
template<typename T>
Vec3dt<T>& Vec3dt<T>:: operator*=(const double k)
{
    x_ = x_ * k;
    y_ = y_ * k;
    z_ = z_ * k;
    return *this;
}
template<typename T>
Vec3dt<T>& Vec3dt<T>:: operator/=(const double k)
{
    x_ = x_ / k;
    y_ = y_ / k;
    z_ = z_ / k;
    return *this;
}
template<typename T>
std::ostream& Vec3dt<T>::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << y_ << separator << z_ << rightBrace;
    return ostrm;
}
template<typename T>
std::istream& Vec3dt<T>::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double x(0.0);
    char sep(0);
    double y(0.0);
    double z(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> x_ >> sep >> y_ >> sep >> z_ >> rightBrace;
    if (istrm.good())
    {
        if ((Vec3dt<T>::leftBrace == leftBrace) && (Vec3dt<T>::separator == sep)
            && (Vec3dt<T>::rightBrace == rightBrace))
        {
            x_ = x;
            y_ = y;
            z_ = z;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

#endif