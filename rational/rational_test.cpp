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