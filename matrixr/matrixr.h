#ifndef MATRIXR_H_0211
#define MATRIXR_H_0211

#include <iostream>
#include <cstddef>
class Matrixr
{
public:
    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
    Matrixr()
    {
        pRows_ = new int*[nRow_];
        pRows_[0] = new int[nRow_*nCol_];
        for (ptrdiff_t i = 0; i < nCol_-2; i++)
        {
            pRows_[i + 1] = pRows_[i] + nCol_;
        }
    }
    ~Matrixr()
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
            delete[] pRows_[i];
        delete[] pRows_;
    }
    Matrixr(const Matrixr& a) //конструктор копирования
    {
        nCol_ = a.nCol_;
        nRow_ = a.nRow_;
        pRows_ = new int*[nRow_];
        for (ptrdiff_t i = 0; i < nRow_; i++)
            pRows_[i] = new int[nCol_];
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pRows_[i][j] = a.pRows_[i][j];
            }
        }
    }
    Matrixr operator=(const Matrixr& a) // оператор присваивания
    {
        nCol_ = a.nCol_;
        nRow_ = a.nRow_;
        pRows_ = new int*[nRow_];
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            pRows_[i] = new int[nCol_];
        }
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pRows_[i][j] = a.pRows_[i][j];
            }
        }
        return *this;
    }
    Matrixr(const ptrdiff_t n, const ptrdiff_t k) //создание массива с заданным размером
    {
        nRow_ = n;
        nCol_ = k;
        pRows_ = new int*[nRow_];
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            pRows_[i] = new int[nCol_];
        }
    }
    std::ostream& writeTo(std::ostream& ostrm) const;
    const ptrdiff_t getRow() const;
    const ptrdiff_t getCol() const;
    bool size(const Matrixr& a);
    const bool RowCol(const Matrixr& a) const;
    Matrixr& operator+=(const Matrixr& a);
    Matrixr& operator-=(const Matrixr& a);
    Matrixr& operator*=(const int k);
    Matrixr& operator/=(const int k);
private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int** pRows_{ nullptr };
};
Matrixr operator+(const Matrixr& a, const Matrixr& b);
Matrixr operator-(const Matrixr& a, const Matrixr& b);
Matrixr operator*(const Matrixr& a, const Matrixr& b);
inline std::ostream& operator<<(std::ostream& ostrm, const Matrixr& a)
{
    return a.writeTo(ostrm);
}
#endif // !MATRIXR_H_0211