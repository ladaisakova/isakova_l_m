#include "stackl.h"
int main()
{
    using namespace std;
    StackL s;
    s.push(0.0);
    s.push(8.1);
    s.push(3.0);
    s.push(0.4);
    s.push(1.3);
    s.push(7.7);
    s.push(6.5);
    cout << " stack s = " << s << endl;
    double k = s.top();
    cout << " s.top() = " << k << endl;
    s.push(2.1);
    cout << " s.push(2.1) = " << s << endl;
    s.pop();
    cout << " s.pop() = " << s << endl;
    StackL s1(s);
    cout << " stack s1 = " << s1 << endl;
    StackL s2 = s;
    cout << " stack s2 = " << s2 << endl;
    StackL l;
    try
    {
        cout << l.top() << endl;
    }
    catch (int p)
    {
        cout << " Error " << p << " stack is empty " << endl;
    }
    try
    {
        l.pop();
    }
    catch (int p)
    {
        cout << " Error " << p << " stack is empty " << endl;
    }
}
std::ostream& StackL::writeTo(std::ostream& ostrm) const
{
    Node* t = pHead_;
    while (t != nullptr)
    {
        ostrm << t->data_ << " ";
        t = t->pNext_;
    }
    return ostrm;
}