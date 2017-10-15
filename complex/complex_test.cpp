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
    cout << "z + (8.0 +i) =" << z << endl;
    z -= Complex(5.0, 2);
    cout << "z - (5.0 + 2*i) =" << z << endl;
    z *= 7.0;
    cout << "z * 7.0 =" << z << endl;
    z *= Complex(2.0, 2);
    cout << "z * (2.0 + 2*i) =" << z << endl;
    z /= 2.0;
    cout << " z / 2.0 =" << z << endl;
    z /= Complex(4.0, 3);
    cout << " z / (4.0 + 3*i) =" << z << endl;
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9, 9");
    z += 2.0;
    cout << " z + 2.0 =" << z << endl;
    z -= 3.1;
    cout << " z - 3.1 =" << z << endl;
    z += 1;
    cout << " z + 1 =" << z << endl;
    z -= 4;
    cout << " z - 4 =" << z << endl;
    z *= 3;
    cout << "z * 3 =" << z << endl;
    z /= 2;
    cout << " z / 2 =" << z << endl;
    z += Complex(2);
    cout << "z + 2 =" << z << endl;
    z += Complex(3.4);
    cout << " 3.4 + z =" << z << endl;
    z += Complex(-1);
    cout << " (-1) + z =" << z << endl;
    z += Complex(-2.8);
    cout << " (-2.8) + z =" << z << endl;
    Complex sum(z + Complex(1.0, 2));
    cout << " z + (1.0, 2) =" << sum << endl;
    Complex minus(z - Complex(2.0, 2));
    cout << " z - (2.0, 2) =" << minus << endl;
    Complex u(z * Complex(1.0, 2));
    cout << " z * (1.0, 2) =" << u << endl;
    Complex del(z / Complex(1.0, 2));
    cout << " z / (1.0, 2) =" << del << endl;
    Complex l(7, 5);
    bool w = z == l;
    cout << " z == (7 + 5*i) =" << w << endl;
    Complex h(2, 8);
    bool s = z != h;
    cout << " z != (2 + 8*i) =" << s << endl;
    Complex t(4.0, 2);
    Complex p(t ^= 2);
    cout << " t^2 =" << p << endl;
    Complex r(z ^= 3);
    cout << "z^3=" << r << endl;
    Complex g;
    g = r.sopr_();
    cout << "sopr for r = " << g << endl;
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