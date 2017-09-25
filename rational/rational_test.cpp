#include "rational.h"
#include <iostream>
#include <sstream>
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
	r.Correct(r);
	cout << r << endl;
	r += Rational(1, 4);
	r.Correct(r);
	cout << r << endl;
	r -= Rational(2, 3);
	r.Correct(r);
	cout << r << endl;
	r *= Rational(3, 5);
	r.Correct(r);
	cout << r << endl;
	r /= Rational(7, 9);
	r.Correct(r);
	cout << r << endl;
	Rational s(4, 3);
	Rational k(5, 6);
	bool h = k > Rational(3, 8);
	cout << h << endl;
	bool n = s < Rational(5, 6);
	cout << n << endl;
	bool f = s == k;
	cout << f << endl;
	bool w = k != Rational(1, 6);
	cout << w << endl;
	Rational a(1, 8);
	Rational* b(&a);
	Rational c(*b);
	cout << c << endl;
	Rational p(4, 5);
	Rational& u(p);
	cout << u << endl;
	testParse("{3/7}");
	testParse("{0/ 9}");
	testParse("{3/ 5");
	return 0;
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