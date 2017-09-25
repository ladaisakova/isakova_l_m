#include "rational.h"
#include <iostream>


Rational& Rational::operator+=(const Rational& rhs)
{
	num_ = num_*rhs.denum_ + rhs.num_*denum_;
	denum_ = denum_*rhs.denum_;
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num_ = num_*rhs.denum_ - rhs.num_*denum_;
	denum_ = denum_*rhs.denum_;
	return *this;
}
Rational operator-(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.num_*rhs.denum_ - rhs.num_*lhs.denum_, lhs.denum_ * rhs.denum_);
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.num_ * rhs.num_, lhs.denum_ * rhs.denum_);
}
Rational& Rational::operator*=(const Rational& rhs)
{
	num_ = rhs.num_*num_;
	denum_ = rhs.denum_*denum_;
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	num_ = num_*rhs.denum_;
	denum_ = rhs.num_*denum_;
	return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.num_*rhs.denum_, lhs.denum_*rhs.num_);
}

