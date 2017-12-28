#include "stackr.h"

int main()
{
	using namespace std;
	Stackr s;
	s.push(1);
	s.push(8);
	s.push(3);
	s.push(7);
	s.push(4);
	s.push(9);
	s.push(0);
	cout << "Stack s= \n" << s << endl;
	s.pop();
	cout << "s.pop()= \n" << s << endl;
	Stackr s1(s);
	cout << "s1(s)= \n" << s1 << endl;;
	s1.top() = 8;
	cout << "s1.top() = 8= \n" << s1 << endl;
	Stackr s2;
	s2.push(2);
	s2.push(4);
	s2.push(9);
	s2.push(3);
	s2.push(2);
	cout << "Stack s2= \n" << s2 << endl;
	Stackr s3;
	s3 = s2;
	cout << "s3 = s2= \n" << s3 << endl;
	Stackr s4;
	s4.push(3);
	s4.push(9);
	s4.push(11);
	s4 = s1;
	cout << "s4 = s1= \n" << s4 << endl;
	Stackr s5;
	try
	{
		s5.top();
	}
	catch (int error)
	{
		cout << "Error " << error << " Stack is empty!" << endl;
	}
	try
	{
		s5.pop();
	}
	catch (int error)
	{
		cout << "Error " << error << " Stack is empty!" << endl;
	}
	return 0;
}
std::ostream& Stackr::writeTo(std::ostream& ostrm) const
{
	if (!isEmpty())
	{
		for (int i = nhead_; i >= 0; i--)
		{
			ostrm << pdata_[i] << std::endl;
		}
	}
	else
	{
		ostrm << "Stack is empty";
	}
	return ostrm;
}