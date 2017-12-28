#ifndef PRIORUTYQUEUE_H_20171224
#define PRIORUTYQUEUE_H_20171224

#include <iostream>

class Priorityqueuer
{
public:
	Priorityqueuer() = default;
	~Priorityqueuer();
	Priorityqueuer operator=(Priorityqueuer& q);
	Priorityqueuer(const Priorityqueuer& q);
	bool isEmpty() const;
	void push(const int& v);
	void pop();
	int& front();
	int& back();
	std::ostream& writeTo(std::ostream& ostrm) const;
private:
	ptrdiff_t size{ 6 };
	int* pdata_{ nullptr };
	ptrdiff_t nhead_{ 0 };
	ptrdiff_t ntail_{ -1 };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Priorityqueuer& rhs)
{
	return rhs.writeTo(ostrm);
}

#endif
