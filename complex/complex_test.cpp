#include "complex.h"
#include <iostream>
#include <sstream>
bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else
	{
		cout << "Read error: " << str << " -> " << z << endl;
	}
	return istrm.good();
}
int main()
{
	using namespace std;
	Complex z(0.0, 0);
	cout << z << endl;
	z += Complex(8.0, 1);
	cout << z << endl;
	z -= Complex(5.0, 2);
	cout << z << endl;
	z *= 7.0;
	cout << z << endl;
	z *= Complex(2.0, 2);
	cout << z << endl;
	z /= 2.0;
	cout << z << endl;
	z /= Complex(4.0, 3);
	cout << z << endl;
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9, 9");
	z += 2.0;
	cout << z << endl;
	z -= 3.1;
	cout << z << endl;
	z += 1;
	cout << z << endl;
	z -= 4;
	cout << z << endl;
	z *= 3;
	cout << z << endl;
	z /= 2;
	cout << z << endl;
	z += Complex(2);
	cout << z << endl;
	z += Complex(3.4);
	cout << z << endl;
	z += Complex(-1);
	cout << z << endl;
	z += Complex(-2.8);
	cout << z << endl;
	z ^= Complex(3);
	char* string = "z=";
	char* string1 = "*(cos";
	char* string2 = "+i*sin";
	printf("%s", string);
	printf("%lf", m);
	printf("%s", string1);
	printf("%lf", a);
	printf("%s", string2);
	printf("%lf", a);
	return 0;
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good())
	{
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace))
		{
			re = real;
			im = imaginary;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}