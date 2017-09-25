#include "rational.h"
#include <iostream>


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
void Rational::Correct(Rational& t)
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
bool Rational::operator>(const Rational& rhs)
{
	return(num_*rhs.denum_ > rhs.num_*denum_);
}
bool Rational::operator<(const Rational& rhs)
{
	return(num_*rhs.denum_ < rhs.num_*denum_);
}
bool Rational::operator==(const Rational& rhs)
{
	return(num_ *rhs.denum_== rhs.num_*denum_);
}
