#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int size, amount;
    cin >> size >> amount;
    vector<int> line;
    //vector<int> find;
    int max = 0;
    line.resize(size, 0);
    for (int i = 0; i < size; i+=1)
    {
        cin >> line[i];
        if (line[i] > max) { max = line[i]; }
    }
    //cout << max << endl;
    //find.resize(max - 1, 0);
    int result = 0;
/*for (int i = 0; i < max - 1; i += 1)
{
for (int j = 0; j < size; j += 1)
{
find[i] = find[i] + line[j] / (i + 1);
}

}*/
    int l, r, m;
    r = max;
    l = -1;
    m = (r + l) / 2;
    while (l < r - 1)
    {
        m = (r + l) / 2;
        result = 0;
        for (int j = 0; j < size; j += 1)
        {
            result = result + line[j] / m;
        }
        if (result < amount)
        {
            r = m;
        }
        else { l = m; }
    }
    cout << (r-1) << endl;
}