#include "matrixr.h"
int& Matrixr::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pRows_[iRow][iCol];
    }
    else
    {
        throw std::invalid_argument("Error!");
    }
}
const int& Matrixr::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pRows_[iRow][iCol];
    }
    else
    {
        throw std::invalid_argument("Error!");
    }
}
bool Matrixr::size(const Matrixr& a)
{
    return(a.nRow_ == nRow_ && a.nCol_ == nCol_);
}const bool Matrixr::RowCol(const Matrixr& a) const
{
    return(nCol_ == a.nRow_);
}
const ptrdiff_t Matrixr::getRow() const
{
    return nRow_;
}
const ptrdiff_t Matrixr::getCol() const
{
    return nCol_;
}
Matrixr& Matrixr:: operator+=(const Matrixr& a)
{
    Matrixr m(nRow_, nCol_);
    if (m.size(a) == 1)
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pRows_[i][j] += a.pRows_[i][j];
            }
        }
        return *this;
    }
    else
    {
        throw std::invalid_argument("Error!");
    }
}
Matrixr& Matrixr:: operator-=(const Matrixr& a)
{
    Matrixr m(nRow_, nCol_);
    if (m.size(a) == 1)
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pRows_[i][j] -= a.pRows_[i][j];
            }
        }
        return *this;
    }
    else
    {
        throw std::invalid_argument("Error!");
    }
}
Matrixr& Matrixr:: operator*=(const int k)
{
        for (ptrdiff_t i = 0; i < nRow_; i++)
        {
            for (ptrdiff_t j = 0; j < nCol_; j++)
            {
                pRows_[i][j] *= k;
            }
        }
        return *this;
}
Matrixr& Matrixr:: operator/=(const int k)
{
    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        for (ptrdiff_t j = 0; j < nCol_; j++)
        {
            pRows_[i][j] /= k;
        }
    }
    return *this;
}
Matrixr operator+(const Matrixr& a, const Matrixr& b)
{
    Matrixr sum(b);
    sum += a;
    return sum;
}
Matrixr operator-(const Matrixr& a, const Matrixr& b)
{
    Matrixr sum(b);
    sum -= a;
    return sum;
}
Matrixr operator*(const Matrixr& a, const Matrixr& b)
{
    if (a.RowCol(b) == 1)
    {
        Matrixr res(a.getRow(), b.getCol());
        for (ptrdiff_t i = 0; i < res.getRow(); i++)
        {
            for (ptrdiff_t j = 0; j < res.getCol(); j++)
            {
                res.at(i, j) = 0;
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