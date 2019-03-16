/**
* LeetCode The 7th problem :reverse-integer
* Auth:Barlowwang
* Date:2019-03-15
**/
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
int reverse(int x)
{
    int sign = x < 0 ? -1 : 1;
    x*=sign;
    int tmp=0;
    while (x != 0)
    {
        tmp = tmp * 10 + (x % 10);
        x /= 10;
    }
    return tmp > 2147483647 ? 0 : (sign * tmp);
}
int main()
{
    int x;
    cin >> x;
    int sign = x < 0 ? -1 : 1;
    cout << sign << endl;
    cout << reverse(x) << endl;
    system("pause");
}