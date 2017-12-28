#include "priorityqueuer.h"

Priorityqueuer::~Priorityqueuer()
{
	delete[] pdata_;
}
Priorityqueuer Priorityqueuer::operator=(Priorityqueuer& q)
{
	if (!q.isEmpty())
	{
		if (isEmpty())
		{
			pdata_ = new int[q.size];
			nhead_ = q.nhead_;
			ntail_ = q.ntail_;
			for (int i = nhead_; i <= ntail_; i += 1)
			{
				pdata_[i] = q.pdata_[i];
			}
		}
		else
		{
			if (size > q.size)
			{
				pdata_ = new int[q.size];
				nhead_ = q.nhead_;
				ntail_ = q.ntail_;
				for (int i = nhead_; i <= ntail_; i += 1)
				{
					pdata_[i] = q.pdata_[i];
				}
			}
			else
			{
				delete[] pdata_;
				size = q.size;
				pdata_ = new int[size];
				nhead_ = q.nhead_;
				ntail_ = q.ntail_;
				for (int i = nhead_; i <= ntail_; i += 1)
				{
					pdata_[i] = q.pdata_[i];
				}
			}
		}
	}
	else
	{
		delete[] pdata_;
		ntail_ = -1;
	}
	return *this;
}

Priorityqueuer::Priorityqueuer(const Priorityqueuer& q)
{
	if (!q.isEmpty())
	{
		pdata_ = new int[q.size];
		nhead_ = q.nhead_;
		ntail_ = q.ntail_;
		for (int i = nhead_; i <= ntail_; i += 1)
		{
			pdata_[i] = q.pdata_[i];
		}
	}
	else
	{
		delete[] pdata_;
		ntail_ = -1;
	}
}
bool Priorityqueuer::isEmpty() const
{
	return (ntail_ == -1);
}

int& Priorityqueuer::front()
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

int& Priorityqueuer::back()
{
	if (!isEmpty())
	{
		return pdata_[ntail_];
	}
	else
	{
		throw 2;
	}
}

void Priorityqueuer::push(const int& t)
{
	if (ntail_ == (size - 1))
	{
		int* newdata = new int[size + 1];
		for (int i = 0; i <= ntail_; i++)
		{
			newdata[i] = pdata_[i];
		}
		delete[] pdata_;
		pdata_ = newdata;
		size += 1;
	}
	int n;
	if (!isEmpty())
	{
		if (pdata_[nhead_] > t)
		{
			for (int i = ntail_; i >= nhead_; i--)
			{
				pdata_[i + 1] = pdata_[i];
			}
			pdata_[nhead_] = t;
			ntail_ += 1;
		}
		else
		{
			if (pdata_[ntail_] < t)
			{
				ntail_ += 1;
				pdata_[ntail_] = t;
			}
			else
			{
				n = nhead_;
				while (pdata_[n + 1] <= t && n != (ntail_ + 1))
				{
					n += 1;
				}
				int k = n + 1;

				for (int i = ntail_; i >= k; i--)
				{
					pdata_[i + 1] = pdata_[i];
				}
				pdata_[k] = t;
				ntail_ += 1;
			}
		}
	}
	else
	{
		pdata_ = new int[size];
		ntail_ += 1;
		pdata_[ntail_] = t;
	}
}

void Priorityqueuer::pop()
{
	if (!isEmpty())
	{
		nhead_ += 1;
	}
	else
	{
		throw 3;
	}
}





