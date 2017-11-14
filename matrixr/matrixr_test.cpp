#include "matrixr.h"
int main()
{
    using namespace std;
    Matrixr m(3, 2);
    m.at(0, 0) = 0; m.at(0, 1) = 1;
    m.at(1, 0) = 4; m.at(1, 1) = 5;
    m.at(2, 0) = 8; m.at(2, 1) = 9;
    cout << "m = " << "\n" << m << endl;
    Matrixr k(3, 2);
    k.at(0, 0) = 1; k.at(0, 1) = 3;
    k.at(1, 0) = 1; k.at(1, 1) = 1;
    k.at(2, 0) = 8; k.at(2, 1) = 5;
    cout << "k = "  << "\n" << k << endl;
    m += k;
    cout << " m + k = " << "\n" << m << endl;
    Matrixr l(2, 3);
    l.at(0, 0) = 1; l.at(0, 1) = 3; l.at(0, 2) = 0;
    l.at(1, 0) = 2; l.at(1, 1) = 7; l.at(1, 2) = 3;
    cout << " l = " << "\n" << l << endl;
    Matrixr res(m * l);
    cout << " m * res = " << "\n" << res << endl;
    res *= 3;
    cout << " res * 3 = " << "\n" << res << endl;
    res /= 2;
    cout << " res / 2 = " << "\n" << res << endl;
}
std::ostream& Matrixr::writeTo(std::ostream& ostrm) const
{
    for (int i = 0; i < nRow_; i += 1)
    {
        for (int j = 0; j < nCol_; j += 1)
        {
            ostrm << pRows_[i][j] << " ";
        }
        ostrm << "\n";
    }
    return ostrm;
}