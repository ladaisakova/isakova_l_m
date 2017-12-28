#ifndef STACKAR_H_20171224
#define STACKAR_H_20171224

#include<iostream>

class Stackr
{
public:
	Stackr() = default;
	~Stackr();
	bool isEmpty() const;
	Stackr(const Stackr& s);
	Stackr operator=(Stackr& s);
	void push(const int& t);
	void pop();
	int& top();
	const int& top() const;
	std::ostream& writeTo(std::ostream& ostrm) const;
private:
	ptrdiff_t size{ 6 };
	int* pdata_{ nullptr };
	ptrdiff_t nhead_{ -1 };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Stackr& rhs)
{
	return rhs.writeTo(ostrm);
}

#endif // !STACKR_H_20172412
