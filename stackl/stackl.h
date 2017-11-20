#ifndef STACK_H_1611
#define STACK_H_1611
#include <iostream>

class StackL
{
public:
    StackL() = default;
    ~StackL();
    StackL(const StackL& a);
    StackL& operator=(const StackL& a);
    void push(const double& v);
    void pop();
    double& top();
    const double& top() const;
    bool isEmpty() const;
    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    struct Node
    {
        Node* pNext_{ nullptr };
        double data_{ 0 };
        Node(Node* pNext, const double& v) :pNext_(pNext), data_(v) {}
    };
    Node* pHead_{ nullptr };
};
inline std::ostream& operator<<(std::ostream& ostrm, const StackL& a)
{
    return a.writeTo(ostrm);
}

#endif // !STACK_H_1611
