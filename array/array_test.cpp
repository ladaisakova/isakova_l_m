#include "array.h"
int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "rus");
    Array m(5);
    m[0] = 0; m[1] = 1; m[2] = 2; m[3] = 3; m[4] = 4;
    cout << "������ m = " << m << endl;
    int s = m.getsize();
    cout << "������ ������� m = " << s << endl;
    m.resize(3);
    cout << "������ m � ���������� �������� = " << m << endl;
    m.insert(5, 2);
    cout << "������ m � ������� 5 �� 2 ����� = " << m << endl;
    m.remove(1);
    cout << "������ m ��� 1-�� �������� = " << m << endl;
    Array k(3);
    cout << " ������ k = " << k << endl;
    k[0] = 3; k[1] = 7; k[2] = 1;
    m.insertarray(k, 1);
    cout << " ������ m + ������ k �� 1-�� ����� = " << m << endl;
    m.removearray(2, 2);
    cout << "������ m ��� ���������� ������� = " << m << endl;
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