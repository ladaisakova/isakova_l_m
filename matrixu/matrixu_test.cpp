#include "matrixu.h"
int main()
{
    using namespace std;
    Matrixu m(3, 2);
    m.at(0, 0) = 0; m.at(0, 1) = 1;
    m.at(1, 0) = 4; m.at(1, 1) = 5;
    m.at(2, 0) = 8; m.at(2, 1) = 9;
    cout << "m = " << "\n" << m << endl;
    Matrixu k(3, 2);
    k.at(0, 0) = 1; k.at(0, 1) = 3;
    k.at(1, 0) = 1; k.at(1, 1) = 1;
    k.at(2, 0) = 8; k.at(2, 1) = 5;
    cout << "k = " << "\n" << k << endl;
    m += k;
    cout << " m + k = " << "\n" << m << endl;
    Matrixu l(2, 3);
    l.at(0, 0) = 1; l.at(0, 1) = 3; l.at(0, 2) = 0;
    l.at(1, 0) = 2; l.at(1, 1) = 7; l.at(1, 2) = 3;
    cout << " l = " << "\n" << l << endl;
    Matrixu res(m * l);
    cout << " m * res = " << "\n" << res << endl;
    res *= 3;
    cout << " res * 3 = " << "\n" << res << endl;
    res /= 2;
    cout << " res / 2 = " << "\n" << res << endl;
}
std::ostream& Matrixu::writeTo(std::ostream& ostrm) const
{
    int t;
    for (int i = 0; i < nRow_; i += 1)
    {
        t = i;
        for (int j = t * nCol_; j < nCol_ + t * nCol_; j += 1)
        {
            ostrm << pdata_[j] << " ";
        }
        ostrm << "\n";
    }
    return ostrm;
}