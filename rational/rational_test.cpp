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
int nod(int a, int b)
{
	int c, d;
	while (a && b)
		if (a >= b)
		{
			c = a%b;
			if (c == 0) { a /= b;  b /= b; break; }
			d = b%c;
			if (d == 0) { a /= c; b /= c; break; }
		}
		else {
			c = b%a;
			if (c == 0) { b /= a;  a /= a; break; }
			d = a%c;
			if (d == 0) { a /= c; b /= c; break; }
		}
		return a & b;
}
//Rational bigger(Rational a, Rational b)
//{
//	a.num_ = a.num_*b.denum_;
//	b.num_ = b.num_*a.denum_;
//	if (a.num_ == b.num_) { cout << "numbers equal" << endl; break; }
//	if (a.num_ > b.num_) { a.num_ /= b.denum_; cout << a << endl; }
//	else { b.num_ /= a.denum_; cout << b << endl; }
//}
//Rational less1(Rational a, Rational b)
//{
//	a.num_ = a.num_*b.denum_;
//	b.num_ = b.num_*a.denum_;
//	if (a.num_ == b.num_) { cout << "numbers equal" << endl; break; }
//	if (a.num_ < b.num_) { a.num_ /= b.denum_; cout << a << endl; }
//	else { b.num_ /= a.denum_; cout << b << endl; }
//}
int main()
{
	using namespace std;
	Rational r(1, 2);
	/*nod(r.num_, r.denum_);*/
	cout << r << endl;
	r += Rational(1, 4);
	/*nod(r.num_, r.denum_);*/
	cout << r << endl;
	r -= Rational(2, 3);
	/*nod(r.num_, r.denum_);*/
	cout << r << endl;
	r *= Rational(3, 5);
	/*nod(r.num_, r.denum_);*/
	cout << r << endl;
	r /= Rational(7, 9);
	/*nod(r.num_, r.denum_);*/
	cout << r << endl;
	/*Rational s(2, 3);
	Rational k(5, 6);
	bigger(s, k);
	Rational m(2, 7);
	Rational l(2, 7);
	less1(m, l);*/
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