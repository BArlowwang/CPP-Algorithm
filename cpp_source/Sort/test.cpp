#include <random>
#include <time.h>
#include <iostream>
#include <vector>
#include "Insert.hpp"
using namespace std;
#define random(x) (rand() % x)
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void insertSort(int *a, int length)
{
    if (a == NULL)
        return;
    int temp = a[0];
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[i])
            {
                temp = a[i];
                for (int k = i; k >= j; k--)
                {
                    a[k] = a[k - 1];
                }
                a[j] = temp;
                break;
            }
        }
        cout << i << ": ";
        for (int hh = 0; hh < length; hh++)
            cout << a[hh] << " ";
        cout << endl;
    }
}
int main(int argc, char const *argv[])
{
    srand((int)time(NULL));
    vector<int> data;
    int a[10] = {50, 13, 81, 8, 25, 59, 52, 20, 7, 19};
    for (int i = 0; i < 10; i++)
    {
        // data.push_back(random(100));
        data.push_back(a[i]);
    }
    /* for (auto i : data)
        cout << i << " ";
    cout << endl;

    vector<int>::iterator it1=data.begin();
     vector<int>::iterator it2=data.end();
    swap(*it1,*(it2-1));
 for (auto i : data)
        cout << i << " ";
    cout << endl;
     system("pause");*/
    Insert<int> b(data);
    b.showRowData();
    b.sort(true);
    b.showSortedData();
    b.sort(false);
    b.showSortedData();
    /*   for (auto i : data)
        cout << i << " ";
    cout << endl;
    vector<int>::iterator k = data.begin();
    vector<int>::iterator j = data.begin() + 2;
    data.insert(k, 20);
    for (auto i : data)
        cout << i << " ";
    cout << endl;
    data.erase(j+1);
    for (auto i : data)
        cout << i << " ";
    cout << endl;
    //  insertSort(a, 10);
    ///   for (auto i : a)
    ////       cout << i << " ";
    cout << endl;
    //   b.sort(false);
    //  b.showSortedData();*/
    system("pause");
    return 0;
}
