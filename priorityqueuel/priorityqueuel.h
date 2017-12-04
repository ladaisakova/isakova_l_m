#ifndef PRIORITYQUEUEL_H_0412
#define PRIORITYQUEUEL_H_0412

#include<iostream>

class PriorityQueueL
{
public:
    PriorityQueueL() = default;
    ~PriorityQueueL()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    PriorityQueueL operator=(const PriorityQueueL& q);
    PriorityQueueL(const PriorityQueueL& q);
    bool isEmpty() const;
    void push(const double& p);
    void pop();
    double& front();
    double& back();

    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    struct Node
    {
        Node(Node* pNext, const double& p)
            : pNext_(pNext)
            , data_(p)
        {
        }
        Node() = default;
        Node* pNext_{ nullptr };
        double data_{ int(0) };
    };
    Node* pHead_{ nullptr };
    Node* pTail_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif