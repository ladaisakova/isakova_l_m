#ifndef VEC3D_H_0510 
#define VEC3D_H_0510

#include <iosfwd>
#include <iostream>
struct Vec3d
{
public:
	Vec3d() = default;
	Vec3d::Vec3d(const double x, const double y, const double z) : x_(x), y_(y), z_(z)
	{

	}
	~Vec3d() = default;
	Vec3d(const Vec3d& v) : x_(v.x_), y_(v.y_), z_(v.z_)
	{

	}
	Vec3d operator=(const Vec3d& v)
	{
		x_ = v.x_;
		y_ = v.y_;
		z_ = v.z_;
		return *this;
	}
	bool operator==(const Vec3d& rhs);
	bool operator!=(const Vec3d& rhs);
	double Mod();
	double Skal(Vec3d&t);
	Vec3d Vec(Vec3d& t);
	double Ugol(Vec3d& t);
	Vec3d& operator+=(const Vec3d& rhs);
	Vec3d& operator-=(const Vec3d& rhs);
	Vec3d& operator*=(const int k);
	Vec3d& operator/=(const int k);
	Vec3d& operator*=(const double k);
	Vec3d& operator/=(const double k);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	double x_{ 0.0 };
	double y_{ 0.0 };
	double z_{ 0.0 };


	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};
inline std::ostream& operator<<(std::ostream& ostrm, const Vec3d& rhs)
{
	return rhs.writeTo(ostrm);
}
inline std::istream& operator >> (std::istream& istrm, Vec3d& rhs)
{
	return rhs.readFrom(istrm);
}
#endif 
