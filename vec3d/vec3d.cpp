#include "vec3d.h"
#include <iostream>

bool Vec3d::operator==(const Vec3d& rhs)
{
	if ((rhs.x_ == x_) && (rhs.y_ == y_) && (rhs.z_ == z_))
	{
		return true;
	}
	else { return false; }
}
bool Vec3d::operator!=(const Vec3d& rhs)
{
	if ((rhs.x_ != x_) || (rhs.y_ != y_) || (rhs.z_ != z_))
	{
		return true;
	}
	else { return false; }
}
double Vec3d::Mod()
{
	return double(sqrt(x_*x_ + y_*y_ + z_*z_));
}

double Vec3d::Skal(Vec3d& t)
{
	return double(t.x_*x_ + t.y_*y_ + t.z_*z_);
}
Vec3d Vec3d::Vec(Vec3d& t)
{
	Vec3d vec;
	vec.x_ = y_*t.z_ - z_*t.y_;
	vec.y_ = z_*t.x_ - x_*t.z_;
	vec.z_ = x_*t.y_ - y_*t.x_;
	return vec;
}
double Vec3d::Ugol(Vec3d& t )
{
	Vec3d h;
	double t1, h1, sk, cos, alfa;
	t1 = t.Mod();
	h.x_ = x_; h.y_ = y_; h.z_ = z_;
	h1 = h.Mod();
	sk = h.Skal(t);
	cos = sk / (t1*h1);
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
	x_ = x_*k;
	y_ = y_*k;
	z_ = z_*k;
	return *this;
}
Vec3d& Vec3d:: operator/=(const int k)
{
	x_ = x_/k;
	y_ = y_/k;
	z_ = z_/k;
	return *this;
}
Vec3d& Vec3d:: operator*=(const double k)
{
	x_ = x_*k;
	y_ = y_*k;
	z_ = z_*k;
	return *this;
}
Vec3d& Vec3d:: operator/=(const double k)
{
	x_ = x_/k;
	y_ = y_/k;
	z_ = z_/k;
	return *this;
}