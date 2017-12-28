#include"stackr.h"

Stackr::~Stackr()
{
	delete[] pdata_;
}

Stackr Stackr::operator=(Stackr& s)
{
	if (!s.isEmpty())
	{
		if (isEmpty())
		{
			pdata_ = new int[s.size];
			for (int i = 0; i <= s.nhead_; i++)
			{
				pdata_[i] = s.pdata_[i];
			}
			nhead_ = s.nhead_;
		}
		else
		{
			int* k(pdata_);
			pdata_ = s.pdata_;
			s.pdata_ = k;
			nhead_ = s.nhead_;
		}
	}
	else
	{
		delete[] pdata_;
		nhead_ = -1;
	}
	return *this;
} 

Stackr::Stackr(const Stackr& s)
{
	if (!s.isEmpty())
	{
		pdata_ = new int[s.size];
		for (int i = 0; i <= s.nhead_; i += 1)
		{
			pdata_[i] = s.pdata_[i];
		}
		nhead_ = s.nhead_;
	}
	else
	{
		delete[] pdata_;
		nhead_ = -1;
	}
}

bool Stackr::isEmpty() const
{
	return (nhead_ == -1);
}

int& Stackr::top()
{
	if (!isEmpty())
	{
		return pdata_[nhead_];
	}
	else
	{
		throw 1;
	}
}

const int& Stackr::top() const
{
	if (!isEmpty())
	{
		return pdata_[nhead_];
	}
	else
	{
		throw 2;
	}
}

void Stackr::push(const int& r)
{
	if (isEmpty())
	{
		pdata_ = new int[size];
	}
	if (nhead_ == (size - 1))
	{
		int* newdata = new int[size + 1];
		for (int i(0); i <= nhead_; i++)
		{
			newdata[i] = pdata_[i];
		}
		delete[] pdata_;
		pdata_ = newdata;
		size += 1;
	}
	nhead_ += 1;
	pdata_[nhead_] = r;
}

void Stackr::pop()
{
	if (!isEmpty())
	{
		nhead_ -= 1;
	}
	else
	{
		throw 3;
	}
}

