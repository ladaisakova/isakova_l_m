#include "rect2d.h"
#include <iostream>

double e = 0.001;
bool Rect2d::operator==(const Rect2d& rhs)
{
    return((abs(rhs.x_ - x_) < e) && (abs(rhs.y_ - y_) < e) && (abs(rhs.x1_ - x1_) < e) && (abs(rhs.y1_ - y1_) < e));
}
bool Rect2d::operator!=(const Rect2d& rhs)
{
    return ((abs(rhs.x_ - x_) > e) || (abs(rhs.y_ - y_) > e) || (abs(rhs.x1_ - x1_) > e) || (abs(rhs.y1_ - y1_) > e));
}
double Rect2d::ploshad()
{
    double pl;
    pl = abs((x1_ - x_)*(y1_ - y_));
    return pl;
}

double Rect2d::peresechenie(Rect2d& rhs)
{
    double per, a, b, c, d;
    if (rhs.x_ > x_) { a = rhs.x_; }
    else { a = x_; }
    if (rhs.x1_ < x1_) { c = abs(a - rhs.x1_); }
    else { c = abs(a - x1_); }
    if (rhs.y_ > y_) { a = rhs.y_; }
    else { a = y_; }
    if (rhs.y1_ < y1_) { d = abs(a - rhs.y1_); }
    else { d = abs(a - y1_); }
    per = c * d;
    return per;
}
Rect2d Rect2d::perkoordinata(Rect2d& rhs)
{
    Rect2d k;
    if ((rhs.y1_ == y_) || (rhs.x_ == x1_)) { std::cout << "Ne peresekautsya" << std::endl; }
    if (rhs.x_ >= x_)
    {
        k.x_ = rhs.x_;
        if (rhs.y_ >= y_)
        {
            k.y_ = rhs.y_;
        }
        else { k.y_ = y_; }
    }
    else
    {
        k.x_ = x_;
        if (rhs.y_ >= y_)
        {
            k.y_ = rhs.y_;
        }
        else { k.y_ = y_; }
    }
    if (rhs.x1_ >= x1_)
    {
        k.x1_ = x1_;
        if (rhs.y1_ >= y1_)
        {
            k.y1_ = y1_;
        }
        else { k.y1_ = rhs.y1_; }
    }
    else
    {
        k.x1_ = rhs.x1_;
        if (rhs.y1_ >= y1_)
        {
            k.y1_ = y1_;
        }
        else { k.y1_ = rhs.y1_; }
    }
    return k;
}

Rect2d Rect2d::obedinenie(Rect2d& rhs)
{
    Rect2d k;
    if (rhs.x_ <= x_)
    {
        k.x_ = rhs.x_;
        if (rhs.y_ <= y_)
        {
            k.y_ = rhs.y_;
        }
        else { k.y_ = y_; }
    }
    else
    {
        k.x_ = x_;
        if (rhs.y_ <= y_)
        {
            k.y_ = rhs.y_;
        }
        else { k.y_ = y_; }
    }
    if (rhs.x1_ <= x1_)
    {
        k.x1_ = x1_;
        if (rhs.y1_ <= y1_)
        {
            k.y1_ = y1_;
        }
        else { k.y1_ = rhs.y1_; }
    }
    else
    {
        k.x1_ = rhs.x1_;
        if (rhs.y1_ <= y1_)
        {
            k.y1_ = y1_;
        }
        else { k.y1_ = rhs.y1_; }
    }
    return k;
}






