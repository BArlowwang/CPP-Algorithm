#include <random>
#include <time.h>
#include <iostream>
#include <vector>
#include "Bubble.hpp"
using namespace std;
#define random(x) (rand() % x)
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main(int argc, char const *argv[])
{
  srand((int)time(NULL));
    vector<int> data;
    for (int i = 0; i < 20; i++)
    {
        data.push_back(random(100));
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
    Bubble<int> b(data);
    b.showRowData();
    b.sort(true);
    b.showSortedData();
    b.sort(false);
    b.showSortedData();
    system("pause");
    return 0;
}
