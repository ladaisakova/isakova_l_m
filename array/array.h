#ifndef ARRAY_H_2510
#define ARRAY_H_2510

#include <cstddef>
#include <iostream>

class Array
{
public:
    int& operator[](const ptrdiff_t i);
    const int& operator[](const ptrdiff_t i) const;
    Array() //конструктор без параметров
    {
        size = 1;
        pdata_ = new int[size];
        for (int i = 0; i < size; i++)
            pdata_[i] = 0;
    }
    ~Array() //деструктор
    {
        delete[] pdata_;
    }
    Array(const Array& a) //конструктор копирования
    {
        size = a.size;
        pdata_ = new int[size];
        for (int i = 0; i < size; i++)
            pdata_[i] = a.pdata_[i];
    }
    Array operator=(const Array& a) // оператор присваивания
    {
        for (int i = 0; i < size; i++)
        {
            a.pdata_[i] = pdata_[i];
        }
        return *this;
    }
    Array(int n) //создание массива с заданным размером
    {
        size = n;
        pdata_ = new int[size];
        for (int i = 0; i < size; i++)
        {
            pdata_[i] = 0;
        }
    }

    int getsize(); // получение размера
    void resize(const int& t);
    void insert(const int& obj, const int& j);
    void insertarray(const Array m, const int j);
    void remove(const int& j);
    void removearray(const int& j, const int& s);

    std::ostream& writeTo(std::ostream& ostrm) const;
    static char const leftBrace{ '[' };
    static char const separator{ ',' };
    static char const rightBrace{ ']' };

private:
    ptrdiff_t size{ 0 };
    int* pdata_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Array& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif