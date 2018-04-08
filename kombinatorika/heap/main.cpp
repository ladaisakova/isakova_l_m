#include<iostream>
#include<vector>

class Heap
{
private:
    const int maxSize = 100;
    int size;
public:
    std::vector<int> arr;
    Heap()
    {
        arr.resize(100);
        size = 0;
    }
    int sizeReturn()
    {
        return size;
    }
    void addEl(int item)
    {
        arr[size] = item;
        size += 1;
        internalRepair(size - 1);
    }
    void internalRepair(int index)
    {
        int k = (index - 1) / 2;
        int i = index;
        while (k >= 0 && i > 0)
        {
            if (arr[i] > arr[k])
            {
                int tmp = arr[i];
                arr[i] = arr[k];
                arr[k] = tmp;
            }
            i = k;
            k = (i - 1) / 2;
        }
    }
    void deleteEl(int index)
    {
        arr[index] = arr[size - 1];
        size -= 1;
        externalRepair(index, size);
    }
    void externalRepair(int index, int size)
    {
        int k = 2 * index + 1;
        int i = index;
        while (k < size && i < size)
        {
            if (arr[k] > arr[i] || arr[k + 1] > arr[i])
            {
                if (arr[k] > arr[k + 1])
                {
                    int tmp = arr[k];
                    arr[k] = arr[i];
                    arr[i] = tmp;
                }
                else
                {
                    int tmp = arr[k + 1];
                    arr[k + 1] = arr[i];
                    arr[i] = tmp;
                }
                i = k;
                k = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }
    void Heapify()
    {
        for (int i = (size - 1) / 2; i >= 0; i -= 1)
        {
            externalRepair(i, size);
        }
    }
    void sortTree()
    {
        Heapify();
        int heapSize = size;
        while (heapSize > 0)
        {
            int tmp = arr[heapSize - 1];
            arr[heapSize - 1] = arr[0];
            arr[0] = tmp;
            heapSize -= 1;
            externalRepair(0, heapSize);
        }
    }
};

int main()
{
    using namespace std;

    Heap h;
    h.addEl(50);
    h.addEl(35);
    h.addEl(40);
    h.addEl(10);
    h.addEl(8);
    h.addEl(15);
    h.addEl(6);
    h.addEl(7);
    h.addEl(6);
    h.addEl(5);
    h.addEl(28);
    h.addEl(42);

    for (int i = 0; i < h.sizeReturn(); i += 1)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    h.deleteEl(1);
    for (int i = 0; i < h.sizeReturn(); i += 1)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    Heap h1;
    h1.addEl(39);
    h1.addEl(27);
    h1.addEl(15);
    h1.addEl(10);
    h1.addEl(38);
    h1.addEl(46);
    h1.addEl(50);
    h1.addEl(15);
    h1.addEl(17);

    h1.sortTree();

    for (int i = 0; i < h1.sizeReturn(); i += 1)
    {
        cout << h1.arr[i] << " ";
    }

    int q;
    cin >> q;

    return 0;
}