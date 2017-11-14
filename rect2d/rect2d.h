#ifndef RECT2D_H_1910
#define RECT2D_H_1910
#include <iosfwd>

class Rect2d
{
public:
    Rect2d() = default;
    Rect2d::Rect2d(const double x, const double y, const double x1, const double y1) : x_(x), y_(y), x1_(x1), y1_(y1) {}
    ~Rect2d() = default;
    Rect2d(const Rect2d& p) : x_(p.x_), y_(p.y_), x1_(p.x1_), y1_(p.y1_)
    {

    }
    Rect2d operator=(const Rect2d& p)
    {
        x_ = p.x_;
        y_ = p.y_;
        x1_ = p.x1_;
        y1_ = p.y1_;
        return *this;
    }

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    bool operator==(const Rect2d& rhs);
    bool operator!=(const Rect2d& rhs);
    double ploshad();
    double peresechenie(Rect2d& rhs);
    Rect2d perkoordinata(Rect2d& rhs);
    Rect2d obedinenie(Rect2d& rhs);

    double x_{ 0.0 };
    double y_{ 0.0 };
    double x1_{ 0.0 };
    double y1_{ 0.0 };

    static const char left{ '{' };
    static const char separator{ ',' };
    static const char right{ '}' };

};
inline std::ostream& operator<<(std::ostream& ostrm, const Rect2d& rhs)
{
    return rhs.writeTo(ostrm);
}
inline std::istream& operator >> (std::istream& istrm, Rect2d& rhs)
{
    return rhs.readFrom(istrm);
}
#endif