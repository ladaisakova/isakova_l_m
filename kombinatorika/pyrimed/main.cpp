#include <iostream>
#include <vector>
using namespace std;
void rep(vector<int> &v, int vertex, int top) {

    int l = 2*vertex+1;
    int r = 2*vertex+2;
    if (l > top) return;
    if (l == top) r=l;
    int imax = v[l] > v[r] ? l : r;
    if (v[vertex] < v[imax]) {
        swap(v[vertex], v[imax]);
        rep(v, imax, top);
    }
}
int main() {
    vector<int> A(10);
    for (int i=0; i<A.size(); i+=1){
        A[i]=i;
    }
    for (int i=A.size()/2; i>=0; i-=1)
    {
        rep(A, i, A.size()-1);
    }
    for (int i=A.size()-1; i>0; i-=1)
    {
        swap(A[0], A[i]);
        rep(A, 0, i - 1);
    }
    for (int i=0; i<A.size(); i+=1){
        cout << A[i] << " ";
    }
    return 0;
}