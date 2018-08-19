#include <iostream>
#include <random>
#include <time.h>
#define random(x) (rand() % x)
using namespace std;
int main()
{
    int n = 19;
    int a[20];
    srand((int)time(NULL));
    for (int i = 0; i < 20; i++)
    {
        a[i] =random(100);
    }
    for(auto i:a) cout<<i<<" ";
    cout<<endl;
    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] < a[i + 1])
            {
                swap(a[i], a[i + 1]);
            }
        }
          n--;
    }
    for(auto i:a) cout<<i<<" ";
    cout<<endl;
    system("pause");
}