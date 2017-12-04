#include "priorityqueuel.h"

PriorityQueueL::PriorityQueueL(const PriorityQueueL& p)
{
}
PriorityQueueL PriorityQueueL::operator=(const PriorityQueueL& p)
{
    return *this;
}
bool PriorityQueueL::isEmpty() const
{
    return (pHead_ == nullptr);
}
void PriorityQueueL::push(const double& p)
{
    double e = 0.0001;
    Node *s;
    if (!isEmpty())
    {
        if (pHead_->data_ - p > e)
        {
            pHead_ = new Node(pHead_, p);
        }
        else
        {
            s = pHead_;
            while (s->pNext_ != nullptr && s->pNext_->data_ - p <= e)
            {
                s = s->pNext_;
            }
            Node *pnext = s->pNext_;
            s->pNext_ = new Node(pnext, p);
        }
    }
    else
    {
        pHead_ = new Node(nullptr, p);
        pTail_ = pHead_;
    }
}
void PriorityQueueL::pop()
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
double& PriorityQueueL::front()
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

double& PriorityQueueL::back()
{
    if (!isEmpty())
    {
        return pTail_->data_;
    }
    else
    {
        throw 3;
    }
}





