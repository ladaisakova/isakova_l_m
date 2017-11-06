#include "matrixu.h"
int& Matrixu::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow <= nRow_ && iCol <= nCol_)
    {
        return pdata_[nCol_*iRow + iCol];
    }
    else
    {
        throw std::invalid_argument("Error!");
    }
}
const int& Matrixu::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow >= 0 && iCol >= 0 && iRow <= nRow_ && iCol <= nCol_)
    {
        return pdata_[nCol_*iRow + iCol];
    }
    else
    {
        throw std::invalid_argument("Error!");
    }
}
bool Matrixu::size(const Matrixu& a)
{
    return(a.nRow_ == nRow_ && a.nCol_ == nCol_);
}
bool Matrixu::RowCol(const Matrixu& a) const
{
    return(nCol_ == a.nRow_);
}
const ptrdiff_t Matrixu::getRow() const
{
    return nRow_;
}
const ptrdiff_t Matrixu::getCol() const
{
    return nCol_;
}
Matrixu Matrixu:: operator+=(const Matrixu& a)
{
    Matrixu m(nRow_, nCol_);
    if (m.size(a) == 1)
    {
        for (ptrdiff_t i = 0; i < nRow_*nCol_; i++)
        {
            pdata_[i] += a.pdata_[i];
        }
        return *this;
    }
    else 
    {
        throw std::invalid_argument("Error!");
    }
}
Matrixu& Matrixu:: operator-=(const Matrixu& a)
{
    Matrixu m(nRow_, nCol_);
    if (m.size(a) == 1)
    {
        for (ptrdiff_t i = 0; i < nRow_*nCol_; i++)
        {
            pdata_[i] -= a.pdata_[i];
        }
        return *this;
    }
    else
    {
        throw std::invalid_argument("Error!");
    }
}
Matrixu& Matrixu:: operator*=(const int k)
{
    for (ptrdiff_t i = 0; i < nRow_*nCol_; i++)
    {
        pdata_[i] *= k;
    }
    return *this;
}
Matrixu& Matrixu:: operator/=(const int k)
{
    for (ptrdiff_t i = 0; i < nRow_*nCol_; i++)
    {
        pdata_[i] /= k;
    }
    return *this;
}
Matrixu operator+(const Matrixu& a, const Matrixu& b)
{
    Matrixu sum(b);
    sum += a;
    return sum;
}
Matrixu operator-(const Matrixu& a, const Matrixu& b)
{
    Matrixu sum(b);
    sum -= a;
    return sum;
}
Matrixu operator*(const Matrixu& a, const Matrixu& b)
{
        if (a.RowCol(b) == 1)
        {
            Matrixu res(a.getRow(), b.getCol());
            for (ptrdiff_t i = 0; i < a.getRow(); i++)
            {
                for (ptrdiff_t j = 0; j < b.getCol(); j++)
                {
                    for (ptrdiff_t n = 0; n < a.getCol(); n++)
                    {
                        res.at(i, j) += a.at(i, n)*b.at(n, j);
                    }
                }
            }
            return res;
        }
        else
        {
            throw std::invalid_argument("Error!");
        }
}
