#include "priorityqueuel.h"

int main()
{
    using namespace std;
    PriorityQueueL a;
    a.push(1.2);
    a.push(0.1);
    a.push(0.5);
    a.push(7.4);
    a.push(9.3);
    a.push(5.5);
    a.push(2.8);
    a.push(4.7);
    a.push(6.9);
    a.push(7.2);
    a.push(0.6);
    cout << " queue a = " << a << endl;
    cout << " front a = " << a.front() << endl;
    cout << " back a = " << a.back() << endl;
    a.pop();
    cout << " pop a = " << a << endl;
    PriorityQueueL b;
    try
    {
        b.pop();
    }
    catch (int error)
    {
        cout << "Error " << error << " queue is empty!" << endl;
    }
    try
    {
        b.front();
    }
    catch (int error)
    {
        cout << "Error " << error << " queue is empty!" << endl;
    }
    try
    {
        b.back();
    }
    catch (int error)
    {
        cout << "Error " << error << " queue is empty!" << endl;
    }
}

std::ostream& PriorityQueueL::writeTo(std::ostream& ostrm) const
{
    Node* q = pHead_;
    while (q != NULL)
    {
        ostrm << q->data_ << ' ';
        q = q->pNext_;
    }
    return ostrm;
}