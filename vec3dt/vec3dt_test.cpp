#include "vec3dt.h"
#include <iostream>
#include <sstream>

template<typename T>
bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Vec3dt<T> v;
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
    cout << "for double" << endl;
    testParse<double>("{0.0, 0.0, 0.0}");
    testParse<double>("{1, 2,2, 3.0}");
    bool n = Vec3dt<double>(0.8, 0.6, 1.9) == Vec3dt<double>(1.1, 7.4, 3.2);
    bool k = Vec3dt<double>(1.2, 0.7, 6.4) != Vec3dt<double>(1.2, 0.7, 6.4);
    cout << "(0.8, 0.6, 1.9) == (1.1, 7.4, 3.2) =" << n << endl;
    cout << "(1.2, 0.7, 6.4) != (1.2, 0.7, 6.4) =" << k << endl;
    Vec3dt<double> a(1.2, 3.1, 2.3);
    cout << a << endl;
    a += Vec3dt<double>(0.1, 0.6, 0.0);
    cout << "a + (0.1, 0.6, 0.0) =" << a << endl;
    a -= Vec3dt<double>(1.2, 3.8, 0.2);
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
    b = a.mod();
    cout << "Modul a =" << b << endl;
    Vec3dt<double> c(1.3, 4.4, 5.1);
    d = a.skal(c);
    cout << "Skal a * (1.3, 4.4, 5.1) =" << d << endl;
    Vec3dt<double> h;
    h = a.vec(c);
    cout << "Vec a * (1.3, 4.4, 5.1) =" << h << endl;
    double s;
    s = a.ugol(c);
    cout << "Ugol mezhdu a and (1.3, 4.4, 5.1) =" << s << endl;
    Vec3dt<double> e(1.2, 1.0, 2.3);
    cout << "e= " << e << endl;
    Vec3dt<double> f(1.1, 3.4, 2.1);
    cout << "f= " << f << endl;
    Vec3dt<double> sum(e + f);
    cout << " e + f = " << sum << endl;
    Vec3dt<double> minus(e - f);
    cout << " e - f = " << minus << endl;
    Vec3dt<double> u(e*2.0);
    cout << " e * 2 = " << u << endl;
    Vec3dt<double> del(e / 1.2);
    cout << " e / 1.2 = " << del << endl;


    cout << "for int" << endl;
    testParse<double>("{0, 1, 4}");
    testParse<double>("{1, 2,2, 3.0}");
    bool n1 = Vec3dt<int>(1, 2, 4) == Vec3dt<int>(1, 2, 4);
    bool k1 = Vec3dt<int>(1, 2, 4) != Vec3dt<int>(3, 7, 1);
    cout << "(1, 2, 4) == (1, 2, 4) =" << n1 << endl;
    cout << "(1, 2, 4) != (3, 7, 1) =" << k1 << endl;
    Vec3dt<int> w(4, 7, 1);
    cout << "w= " << w << endl;
    w += Vec3dt<int>(1, 1, 2);
    cout << "w + (1, 1, 2) =" << w << endl;
    w -= Vec3dt<int>(3, 4, 4);
    cout << "w - (3, 4, 4) =" << w << endl;
    w *= 2;
    cout << "w * 2 =" << w << endl;
    w /= 3;
    cout << "w / 3 =" << w << endl;
    w *= 3.2;
    cout << "w * 3.2 =" << w << endl;
    w /= 1.5;
    cout << "w / 1.5 =" << w << endl;
    double b1, d1;
    b1 = w.mod();
    cout << "Modul w =" << b1 << endl;
    Vec3dt<int> q(1, 9, 0);
    d1 = w.skal(q);
    cout << "Skal w * (1, 9, 0) =" << d1 << endl;
    Vec3dt<int> p;
    p = w.vec(q);
    cout << "Vec w * (1, 9, 0) =" << p << endl;
    double s1;
    s1 = w.ugol(q);
    cout << "Ugol mezhdu w and (1, 9, 0) =" << s1 << endl;
    Vec3dt<int> e1(1, 3, 5);
    cout << "e1= " << e1 << endl;
    Vec3dt<int> f1(1, 7, 8);
    cout << "f1= " << f1 << endl;
    Vec3dt<int> sum1(e1 + f1);
    cout << " e1 + f1 = " << sum1 << endl;
    Vec3dt<int> minus1(e1 - f1);
    cout << " e1 - f1 = " << minus1 << endl;
    Vec3dt<int> u1(e1 * 4);
    cout << " e1 * 4 = " << u1 << endl;
    Vec3dt<int> del1(e1 / 2);
    cout << " e1 / 2 = " << del1 << endl;
}
