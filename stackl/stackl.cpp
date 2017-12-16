#include "stackl.h"
StackL::StackL(const StackL& a)
{
    Node* pCopyFrom(a.pHead_->pNext_);
    Node* pCopyTo = new Node(nullptr, a.pHead_->data_);
    pHead_ = pCopyTo;
    while (pCopyFrom != nullptr)
    {
        pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->data_);
        pCopyTo = pCopyTo->pNext_;
        pCopyFrom = pCopyFrom->pNext_;
    }
}
StackL& StackL::operator=(const StackL& a)
{
    Node* pCopyTo = pHead_;
    Node* pCopyFrom = a.pHead_;
    while ((pCopyTo->pNext_ != nullptr) && (pCopyFrom->pNext_ != nullptr))
    {
        pCopyTo->data_ = pCopyFrom->data_;
        pCopyTo = pCopyTo->pNext_;
        pCopyFrom = pCopyFrom->pNext_;
    }
    if ((pCopyTo->pNext_ == nullptr) && (pCopyFrom->pNext_ != nullptr))
    {
        pCopyTo->data_ = pCopyFrom->data_;
        pCopyFrom = pCopyFrom->pNext_;
        while (pCopyFrom != nullptr)
        {
            pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->data_);
            pCopyTo = pCopyTo->pNext_;
            pCopyFrom = pCopyFrom->pNext_;
        }
    }
    else
    {
        if ((pCopyFrom->pNext_ == nullptr) && (pCopyTo->pNext_ != nullptr))
        {
            pCopyTo->data_ = pCopyFrom->data_;
            Node* pContinue(pCopyTo->pNext_);
            pCopyTo->pNext_ = nullptr;
            Node* pDelete;
            while (pContinue != nullptr)
            {
                pDelete = pContinue;
                pContinue = pDelete->pNext_;
                delete pDelete;
            }
        }
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