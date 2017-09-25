#ifndef RATIONAL_H_2109
#define RATIONAL_H_2109
#include <iosfwd>
class Rational
{
public:
	Rational() = default;
	Rational(const int num) : num_(num) {}
	Rational::Rational(const int num, const int denum)
		: num_(num), denum_(denum)
	{
		if (0 == denum_) {}
		//сократить, если нужно(алгоритм Эвклида) 
		//перенести минус из знаменателя в числитель 
	}
	~Rational() = default;
	bool operator==(const Rational& rhs) const { return (num_ == rhs.num_) && (denum_ == rhs.denum_); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const double rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);
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