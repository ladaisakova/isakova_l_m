#include "array.h" 
int& Array::operator[](const ptrdiff_t i)
{
    return pdata_[i];
}
const int& Array::operator[](const ptrdiff_t i) const
{
    return pdata_[i];
}
int Array::getsize() // получение размера
{
    return size;
}
void Array::resize(const int& t)
{
    if (t > size)
    {
        int* m = new int[t];
        for (int i = 0; i < size; i++)
        {
            m[i] = pdata_[i];
        }
        delete[] pdata_;
        pdata_ = m;
        size = t;
    }
    else
    {
        int* m = new int[t];
        for (int i = 0; i < t; i++)
        {
            m[i] = pdata_[i];
        }
        delete[] pdata_;
        pdata_ = m;
        size = t;
    }
}
void Array::insert(const int& obj, const int& j)
{
    int* newm = new int[size+1];
    for (int i = 0; i < size; i++)
    {
        newm[i] = pdata_[i];
    }
    for (int i = size; i > j; i--)
    {
        newm[i] = newm[i - 1];
    }
    newm[j] = obj;
    size++;
    pdata_ = newm;
}
void Array::remove(const int& j)
{
    int* newm = new int[size];
    for (int i = 0; i < size; i++)
    {
        newm[i] = pdata_[i];
    }
    for (int i = j; i < size-1; i++)
    {
        newm[i] = newm[i + 1];
    }
    size--;
    pdata_ = newm;
}
void Array::removearray(const int& j, const int& s)
{
    int* newm = new int[size];
    for (int i = 0; i < size; i++)
    {
        newm[i] = pdata_[i];
    }
    for (int i = j; i < j+s; i++)
    {
        newm[i] = newm[i+s];
    }
    size-=s;
    pdata_ = newm;
}
void Array::insertarray(const Array m, const int j)
{
    int* newm = new int[size + m.size];
    for (int i = 0; i < size; i++)
    {
        newm[i] = pdata_[i];
    }
    for (int i = size+m.size-1; i > j+m.size-1; i--)
    {
        newm[i] = newm[i - m.size];
    }
    int t = 0;
    for (int i = j; i < j + m.size; i++)
    {
        newm[i] = m.pdata_[t];
        t++;
    }
    size+=m.size;
    pdata_ = newm;
}