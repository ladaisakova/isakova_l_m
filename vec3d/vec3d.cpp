#include "vec3d.h"
#include <iostream>
double e = 0.001;
bool Vec3d::operator==(const Vec3d& rhs)
{
    return((abs(rhs.x_ - x_) < e) && (abs(rhs.y_ - y_) < e) && (abs(rhs.z_ - z_) < e));
}
bool Vec3d::operator!=(const Vec3d& rhs)
{
    return ((abs(rhs.x_ - x_) > e) || (abs(rhs.y_ - y_) > e) || (abs(rhs.z_ - z_) > e));
}
double Vec3d::mod()
{
    return double(sqrt(x_ * x_ + y_ * y_ + z_ * z_));
}

double Vec3d::skal(Vec3d& t)
{
    return double(t.x_ * x_ + t.y_ * y_ + t.z_ * z_);
}
Vec3d Vec3d::vec(Vec3d& t)
{
    Vec3d vec;
    vec.x_ = y_ * t.z_ - z_ * t.y_;
    vec.y_ = z_ * t.x_ - x_ * t.z_;
    vec.z_ = x_ * t.y_ - y_ * t.x_;
    return vec;
}
double Vec3d::ugol(Vec3d& t)
{
    Vec3d h;
    double t1, h1, sk, cos, alfa;
    t1 = t.mod();
    h.x_ = x_; h.y_ = y_; h.z_ = z_;
    h1 = h.mod();
    sk = h.skal(t);
    cos = sk / (t1 * h1);
    alfa = acos(cos);
    return alfa;
}
Vec3d& Vec3d:: operator+=(const Vec3d& rhs)
{
    x_ = rhs.x_ + x_;
    y_ = rhs.y_ + y_;
    z_ = rhs.z_ + z_;
    return *this;
}
Vec3d& Vec3d:: operator-=(const Vec3d& rhs)
{
    x_ = x_ - rhs.x_;
    y_ = y_ - rhs.y_;
    z_ = z_ - rhs.z_;
    return *this;
}
Vec3d& Vec3d:: operator*=(const int k)
{
    x_ = x_ * k;
    y_ = y_ * k;
    z_ = z_ * k;
    return *this;
}
Vec3d& Vec3d:: operator/=(const int k)
{
    x_ = x_ / k;
    y_ = y_ / k;
    z_ = z_ / k;
    return *this;
}
Vec3d& Vec3d:: operator*=(const double k)
{
    x_ = x_ * k;
    y_ = y_ * k;
    z_ = z_ * k;
    return *this;
}
Vec3d& Vec3d:: operator/=(const double k)
{
    x_ = x_ / k;
    y_ = y_ / k;
    z_ = z_ / k;
    return *this;
}
Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs)
{
    Vec3d sum(lhs);
    sum += rhs;
    return sum;
}
Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs)
{
    Vec3d minus(lhs);
    minus -= rhs;
    return minus;
}
Vec3d operator*(const Vec3d& lhs, const double d)
{
    Vec3d u(lhs);
    u *= d;
    return u;
}
Vec3d operator/(const Vec3d& lhs, const double d)
{
    Vec3d del(lhs);
    del /= d;
    return del;
}