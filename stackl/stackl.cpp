#include "stackl.h"
StackL::StackL(const StackL& a)
{
    StackL s;
    Node* temp = a.pHead_;
    while (temp != nullptr)
    {
        s.push(temp->data_);
        temp = temp->pNext_;
    }
    temp = s.pHead_;
    while (temp != nullptr)
    {
        push(temp->data_);
        temp = temp->pNext_;
    }
}
StackL& StackL::operator=(const StackL& a)
{
    StackL s;
    Node* temp = a.pHead_;
    while (temp != nullptr)
    {
        s.push(temp->data_);
        temp = temp->pNext_;
    }
    temp = s.pHead_;
    while (temp != nullptr)
    {
        push(temp->data_);
        temp = temp->pNext_;
    }
    return *this;
}
StackL::~StackL()
{
    while (!isEmpty())
    {
        pop();
    }
}
bool StackL::isEmpty() const
{
    return (pHead_ == nullptr);
}
void StackL::pop()
{
    if (!isEmpty())
    {
        Node* pdeleted(pHead_);
        pHead_ = pdeleted->pNext_;
        delete pdeleted;
    }
    else
    {
        throw 1;
    }
}
void StackL::push(const double& v)
{
    pHead_ = new Node(pHead_, v);
}
const double& StackL::top() const
{
    if (!isEmpty())
    {
        return pHead_->data_;
    }
    else
    {
        throw 2;
    }
}
double& StackL::top()
{
    if (!isEmpty())
    {
        return pHead_->data_;
    }
    else
    {
        throw 3;
    }
}