#include "array.h"
int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "rus");
    Array m(5);
    m[0] = 0; m[1] = 1; m[2] = 2; m[3] = 3; m[4] = 4;
    cout << "массив m = " << m << endl;
    int s = m.getsize();
    cout << "размер массива m = " << s << endl;
    m.resize(3);
    cout << "массив m с измененным размером = " << m << endl;
    m.insert(5, 2);
    cout << "массив m и элемент 5 на 2 место = " << m << endl;
    m.remove(1);
    cout << "массив m без 1-го элемента = " << m << endl;
    Array k(3);
    cout << " массив k = " << k << endl;
    k[0] = 3; k[1] = 7; k[2] = 1;
    m.insertarray(k, 1);
    cout << " массив m + массив k на 1-ое место = " << m << endl;
    m.removearray(2, 2);
    cout << "массив m без удаленного массива = " << m << endl;
}
std::ostream& Array::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace;
    for (int i = 0; i < size - 1; i += 1)
    {
        ostrm << pdata_[i] << separator;
    }
    ostrm << pdata_[size - 1];
    ostrm << rightBrace;
    return ostrm;
}