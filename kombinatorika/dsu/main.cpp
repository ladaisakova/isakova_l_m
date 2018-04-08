#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DSU {
    vector <int> parent;
    DSU(int size) {
        parent.resize(size, -1);
    }
    void hang(int v, int p) {
        parent[v] = p;
    }
    void print() {
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] != -1)
                cout << i << " -> " << parent[i] << endl;
            else
                cout << i << endl;
        }
    }
    int find(int v) {
        int r = v;
        while (parent[r] != -1)
            r = parent[r];
        while (parent[v] != -1)
        {
            int tmp = v;
            v = parent[v];
            parent[tmp] = r;
        }
        return v;
    }
    void reset(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i += 1) {
            if (parent[i] != -1) {
                hang(i, -1);
            }
        }
        cout << "RESET DONE" << endl;
    }
    void join(int j, int k) {
        if (find(j) == find(k)) {
            cout << "ALREADY " << j << " " << k << endl;
        }
        else {
            hang(find(j), find(k));
        }
    }
    void check(int j, int k) {
        if (find(j) == find(k)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
};

int main() {
    DSU d(1);
    //string s;
    //while (cin >> s) {
    //    if (s == "RESET")
    //    {
    //        int n;
    //        cin >> n;
    //        dsu.reset(n);
    //    }
    //    if (s == "JOIN")
    //    {
    //        int j, k;
    //        cin >> j >> k;
    //        dsu.join(j, k);
    //    }
    //    if (s == "CHECK")
    //    {
    //        int j, k;
    //        cin >> j >> k;
    //        dsu.check(j, k);
    //    }
    //}
    d.reset(15);
    d.join(14, 10);
    d.join(13, 8);
    d.join(0, 9);
    d.join(8, 3);
    d.join(4, 1);
    d.join(10, 5);
    d.join(8, 4);
    d.check(2, 11);
    d.join(4, 1);
    d.join(2, 6);
    d.check(9, 1);
    d.join(6, 5);
    d.check(10, 5);

    string q;
    cin >> q;
    return 0;
}