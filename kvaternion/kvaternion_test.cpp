#include "kvaternion.h"

#include <iostream>
#include <sstream>
int main()
{
    using namespace std;
    Kvaternion m(2.0, 3.0, 1.0, 4.0);
    cout << "m = " << m << endl;
    m += Kvaternion(2.0, 1.0, 7.0, 9.0);
    cout << " m += (2.0, 1.0, 7.0, 9.0) " << m << endl;
    m -= Kvaternion(1.0, 1.0, 4.0, 3.0);
    cout << " m -= (1.0, 1.0, 4.0, 3.0) " << m << endl;
    m *= Kvaternion(1.0, 1.0, 2.0, 1.0);
    cout << " m *= (1.0, 1.0, 2.0, 1.0) " << m << endl;
    m *= 2.0;
    cout << " m *= 2.0 " << m << endl;
    m /= 3.0;
    cout << " m /= 3.0 " << m << endl;
    m = 4.0 * m;
    cout << " 4.0 * m = " << m << endl;
    m = m*2.0;
    cout << " m * 2.0 = " << m << endl;
    m = m / 8.0;
    cout << " m / 8.0 = " << m << endl;
    Kvaternion n(1.0, 5.0, 4.0, 1.0);
    cout << " n = " << n << endl;
    Kvaternion k(1.0, 1.0, 4.0, 2.0);
    cout << " k = " << k << endl;
    m = n*k;
    cout << " n * k = " << m << endl;
    m = n - k;
    cout << " n - k = " << m << endl;
    m = n + k; 
    cout << " n + k = " << m << endl;
    double j;
    j = m.opredelitel();
    cout << " opredelitel m = " << j << endl;
    m.transponirovanie();
    cout << " transponirovanie m = " << m << endl;
    m.inverse();
    cout << " inverse m = " << m << endl;
    m = n / k;
    cout << " n / k = " << m << endl;
}
std::ostream& Kvaternion::writeTo(std::ostream& ostrm) const
{
    ostrm << left << a_ << separator << b_ << separator << c_ << separator << d_ << right;
    return ostrm;
}
std::istream& Kvaternion::readFrom(std::istream& istrm)
{
    char left(0);
    char s(0);
    char right(0);
    double a(0.0);
    double b(0.0);
    double c(0.0);
    double d(0.0);
    istrm >> left >> a_ >> s >> b_ >> s >> c_ >> s >> d_ >> right;
    if (istrm.good())
    {
        if ((Kvaternion::left == left) && (Kvaternion::separator == s)
            && (Kvaternion::right == right))
        {
            a_ = a;
            b_ = b;
            c_ = c;
            d_ = d;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}