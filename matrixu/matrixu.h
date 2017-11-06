#ifndef MATRIXU_H_0211
#define MATRIXU_H_0211

#include <iostream>
#include <cstddef>
class Matrixu 
{
public:
    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
    ~Matrixu()
    {
        delete[] pdata_;
    }
    Matrixu()
    {
        pdata_ = new int[nCol_*nRow_];
    }
    Matrixu(const Matrixu& a) //конструктор копирования
    {
        nCol_ = a.nCol_;
        nRow_ = a.nRow_;
        pdata_ = new int[nCol_*nRow_];
        for (ptrdiff_t i = 0; i < nCol_*nRow_; i++)
            pdata_[i] = a.pdata_[i];
    }
    Matrixu operator=(const Matrixu& a) // оператор присваивания
    {
        nCol_ = a.nCol_;
        nRow_ = a.nRow_;
        for (ptrdiff_t i = 0; i < nCol_*nRow_; i++)
        {
            a.pdata_[i] = pdata_[i];
        }
        return *this;
    }
    Matrixu(int n, int k) //создание массива с заданным размером
    {
        nRow_ = n;
        nCol_ = k;
        pdata_ = new int[nRow_*nCol_];
        for (ptrdiff_t i = 0; i < nRow_*nCol_; i++)
        {
            pdata_[i] = 0;
        }
    }

    std::ostream& writeTo(std::ostream& ostrm) const;
    bool size(const Matrixu& a);
    bool RowCol(const Matrixu& a) const;
    Matrixu operator+=(const Matrixu& a);
    Matrixu& operator-=(const Matrixu& a);
    Matrixu& operator*=(const int k);
    Matrixu& operator/=(const int k);
    const ptrdiff_t getRow() const;
    const ptrdiff_t getCol() const;
private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int* pdata_{ nullptr };
};
Matrixu operator+(const Matrixu& a, const Matrixu& b);
Matrixu operator-(const Matrixu& a, const Matrixu& b);
Matrixu operator*(const Matrixu& a, const Matrixu& b);
inline std::ostream& operator<<(std::ostream& ostrm, const Matrixu& a)
{
    return a.writeTo(ostrm);
}
#endif // !MATRIXU_H_0211
