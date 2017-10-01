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
	cout << r << endl;
	r += Rational(1, 4);
	cout << "r+1/4=" << r << endl;
	r -= Rational(2, 3);
	cout << "r-2/3=" << r << endl;
	r *= Rational(3, 5);
	cout << "r*(3/5)=" << r << endl;
	r /= Rational(7, 9);
	cout << "r/(7/9)=" << r << endl;
	bool h = r > Rational(3, 8);
	cout << "r > 3/8 =" << h << endl;
	bool n = r < Rational(5, 6);
	cout << "r < 5/6 =" << n << endl;
	bool f = r == Rational(4, 3);
	cout << "r == 4/3 =" << f << endl;
	bool w = r != Rational(1, 6);
	cout << "r != 1/6 =" << w << endl;
	Rational a(1, 8);
	Rational* b(&a);
	Rational c(*b);
	cout << "Ukazatel" << c << endl;
	Rational p(4, 5);
	Rational& u(p);
	cout << "Ssylka" << u << endl;
	testParse("{3/7}");
	testParse("{0/ 9}");
	testParse("{3/ 5");
	r += Rational(1);
	cout << "r + 1 =" << r << endl;
	r -= Rational(2);
	cout << "r - 2 =" << r << endl;
	r += Rational(2.1);
	cout << "r + 2.1 =" << r << endl;
	Rational j(r ^ 4);
	cout << "r^4=" << j << endl;
	r *= 2;
	cout << "r * 2 =" << r << endl;
	r /= 7;
	cout << "r / 7 =" << r << endl;
	r += 4.2;
	cout << "r + 4.2 =" << r << endl;
	r -= 3.5;
	cout << "r - 3.5 =" << r << endl;
	r *= 1.2;
	cout << "r * 1.2 =" << r << endl;
	r /= 2.2;
	cout << "r / 2.2 =" << r << endl;
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