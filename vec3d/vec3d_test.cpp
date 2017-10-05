#include "vec3d.h"
#include <iostream>
#include <sstream>
bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Vec3d v;
	istrm >> v;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << v << endl;
	}
	else
	{
		cout << "Read error: " << str << " -> " << v << endl;
	}
	return istrm.good();
}
int main()
{
	using namespace std;
	Vec3d a(1.2, 3.1, 2.3);
	cout << a << endl;
	a+=Vec3d(0.1, 0.6, 0.0);
	cout << "a + (0.1, 0.6, 0.0) ="<< a << endl;
	a -= Vec3d(1.2, 3.8, 0.2);
	cout << "a - (1.2, 3.8, 0.2) =" << a << endl;
	a *= 2;
	cout << "a * 2 =" << a << endl;
	a /= 3;
	cout << "a / 3 =" << a << endl;
	a *= 3.2;
	cout << "a * 3.2 =" << a << endl;
	a /= 1.5;
	cout << "a / 1.5 =" << a << endl;
	double b, d;
	b = a.Mod();
	cout << "Modul a =" << b << endl;
	Vec3d c(1.3, 4.4, 5.1);
	d = a.Skal(c);
	cout << "Skal a * (1.3, 4.4, 5.1) =" << d << endl;
	Vec3d h;
	h = a.Vec(c);
	cout << "Vec a * (1.3, 4.4, 5.1) =" << h << endl;
	double s;
	s = a.Ugol(c);
	cout << "Ugol mezhdu a and (1.3, 4.4, 5.1) =" << s << endl;
}
std::ostream& Vec3d::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << x_ << separator << y_ << separator << z_ <<rightBrace;
	return ostrm;
}

std::istream& Vec3d::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	int x(0);
	char s(0);
	int y(0);
	int z(0);
	char rightBrace(0);
	istrm >> leftBrace >> x_ >> s >> y_ >> s >> z_ >> rightBrace;
	if (istrm.good())
	{
		if ((Vec3d::leftBrace == leftBrace) && (Vec3d::separator == s)
			&& (Vec3d::rightBrace == rightBrace))
		{
			x_ = x;
			y_ = y;
			z_ = z;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}