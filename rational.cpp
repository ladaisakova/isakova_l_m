#include <iostream> 
#include <sstream> 


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

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational r;
	istrm >> r;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << r << endl;
	}
	else
	{
		cout << "Read error: " << str << " -> " << r << endl;
	}
	return istrm.good();
}

int main()
{
	using namespace std;
	Rational r(1, 2);
	cout << r << endl;
	r += Rational(1, 4);
	cout << r << endl;
	r -= Rational(2, 3);
	cout << r << endl;
	r *= Rational(3, 5);
	cout << r << endl;
	r /= Rational(7, 9);
	cout << r << endl;
	testParse("{3/7}");
	testParse("{0/ 9}");
	testParse("{3/ 5");
	return 0;
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num_ = num_*rhs.denum_+rhs.num_*denum_;
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

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << num_ << separator << denum_ << rightBrace;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	int num(0);
	char s(0);
	int denum(0);
	char rightBrace(0);
	istrm >> leftBrace >> num_ >> s >> denum_ >> rightBrace;
	if (istrm.good())
	{
		if ((Rational::leftBrace == leftBrace) && (Rational::separator == s)
			&& (Rational::rightBrace == rightBrace))
		{
			num_ = num;
			denum_ = denum;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}