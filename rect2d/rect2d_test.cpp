#include "rect2d.h"
#include <iostream>
#include <sstream>

int main()
{
    using namespace std;
    Rect2d p1(1.0, 2.0, 4.0, 6.0);
    cout << "p1=" << p1 << endl;
    Rect2d p2(3.0, 3.0, 7.0, 7.0);
    cout << "p2=" << p2 << endl;
    double s1, s2;
    s1 = p1.ploshad();
    cout << "ploshchad p1" << s1 << endl;
    s2 = p1.peresechenie(p2);
    cout << "ploshchad  peresecheniya p1 i p2" << s2 << endl;
    Rect2d k;
    k = p1.perkoordinata(p2);
    cout << " koordinaty peresecheniya p1 i p2 " << k << endl;
    Rect2d j;
    j = p1.obedinenie(p2);
    cout << "koordinaty obedineniya p1 i p2 " << j << endl;
    Rect2d p3(6.0, 3.0, 8.0, 6.0);
    cout << "p3=" << p3 << endl;
    Rect2d p4(3.0, 4.0, 7.0, 7.0);
    cout << "p4=" << p4 << endl;
    double s3, s4;
    s3 = p3.ploshad();
    cout << "ploshchad p3" << s3 << endl;
    s4 = p3.peresechenie(p4);
    cout << "ploshchad  peresecheniya p3 i p4" << s4 << endl;
    Rect2d k1;
    k1 = p3.perkoordinata(p4);
    cout << " koordinaty peresecheniya p3 i p4 " << k1 << endl;
    Rect2d j1;
    j1 = p3.obedinenie(p4);
    cout << "koordinaty obedineniya p3 i p4 " << j1 << endl;
    Rect2d p5(6.0, 3.0, 10.0, 6.0);
    cout << "p5=" << p5 << endl;
    Rect2d p6(7.0, 4.0, 9.0, 5.0);
    cout << "p6=" << p6 << endl;
    double s5, s6;
    s5 = p5.ploshad();
    cout << "ploshchad p5" << s5 << endl;
    s6 = p5.peresechenie(p6);
    cout << "ploshchad  peresecheniya p5 i p6" << s6 << endl;
    Rect2d k2;
    k2 = p5.perkoordinata(p6);
    cout << " koordinaty peresecheniya p5 i p6 " << k2 << endl;
    Rect2d j2;
    j2 = p5.obedinenie(p6);
    cout << "koordinaty obedineniya p5 i p6 " << j2 << endl;
    Rect2d p7(6.0, 3.0, 10.0, 6.0);
    cout << "p7=" << p7 << endl;
    Rect2d p8(10.0, 6.0, 12.0, 9.0);
    cout << "p8=" << p8 << endl;
    double s7, s8;
    s7 = p7.ploshad();
    cout << "ploshchad p7" << s7 << endl;
    s8 = p7.peresechenie(p8);
    cout << "ploshchad  peresecheniya p7 i p8" << s8 << endl;
    Rect2d k3;
    k3 = p7.perkoordinata(p8);
    cout << " koordinaty peresecheniya p7 i p8 " << k3 << endl;
    Rect2d j3;
    j3 = p7.obedinenie(p8);
    cout << "koordinaty obedineniya p7 i p8 " << j3 << endl;
    bool i(p1 == p2);
    cout << i << endl;
    bool h(p3 != p4);
    cout << h << endl;
}
std::ostream& Rect2d::writeTo(std::ostream& ostrm) const
{
    ostrm << left << x_ << separator << y_ << separator << x1_ << separator << y1_ << right;
    return ostrm;
}
std::istream& Rect2d::readFrom(std::istream& istrm)
{
    char left(0);
    double x(0.0);
    char s(0);
    double y(0.0);
    double x1(0.0);
    double y1(0.0);
    char right(0);
    istrm >> left >> x_ >> s >> y_ >> s >> x1_ >> s >> y1_ >> right;
    if (istrm.good())
    {
        if ((Rect2d::left == left) && (Rect2d::separator == s) && (Rect2d::right == right))
        {
            x_ = x;
            y_ = y;
            x1_ = x1;
            y1_ = y1;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}