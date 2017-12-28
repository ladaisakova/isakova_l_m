#include "priorityqueuer.h"

int main()
{
	using namespace std;
	Priorityqueuer q;
	q.push(11);
	q.push(6);
	q.push(1);
	q.push(3);
	q.push(7);
	q.push(4);
	q.push(8);
	q.push(1);
	q.push(5);
	q.push(4);
	cout << "q= \n" << q << endl;
	q.pop();
	cout << "q.pop()= \n" << q << endl;
	cout << "q.front()= \n" << q.front() << endl;
	cout << "q.back()= \n" << q.back() << endl;
	Priorityqueuer q1;
	q1.push(3);
	q1.push(4);
	q1.push(13);
	q1.push(9);
	q1.push(8);
	cout << "q1= \n" << q1 << endl;
	q = q1;
	cout << "q = q1 \n" << q << endl;
	Priorityqueuer q2;
	q2.push(6);
	q2.push(5);
	q2.push(4);
	q2.push(7);
	cout << "q2= \n" << q2 << endl;
	q2 = q;
	cout << "q2 = q \n" << q2 << endl;
	Priorityqueuer q5;
	try
	{
		q5.front();
	}
	catch (int error)
	{
		cout << "Error " << error << " Queue is empty!" << endl;
	}
	try
	{
		q5.back();
	}
	catch (int error)
	{
		cout << "Error " << error << " Queue is empty!" << endl;
	}
	try
	{
		q5.pop();
	}
	catch (int error)
	{
		cout << "Error " << error << " Queue is empty!" << endl;
	}
	return 0;
}
std::ostream& Priorityqueuer::writeTo(std::ostream& ostrm) const
{
	if (!isEmpty())
	{
		for (int i = nhead_; i <= ntail_; i += 1)
		{
			ostrm << pdata_[i] << std::endl;
		}
	}
	else
	{
		ostrm << "Queue is empty";
	}
	return ostrm;
}