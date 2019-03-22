
/**
* LeetCode The 9th problem :palindrome-number
* Auth:Barlowwang
* Date:2019-03-16
**/
#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x < 10)
        return true;
    if (x % 10 == 0)
        return false;
    int cur = 0, tmp = 0;
    while (x != 0)
    {
        cur = x % 10;
        tmp = tmp * 10 + cur;
        x /= 10;
        if (x == tmp)
            return true;
        cur = x % 10;
        x /= 10;
        if (x == tmp)
            return true;
        x = x * 10 + cur;
        if (tmp > x)
            return false;
    }
}
int main()
{
    int s;
    while (1)
    {
        cin >> s;
        cout << isPalindrome(s) << endl;
    }
}