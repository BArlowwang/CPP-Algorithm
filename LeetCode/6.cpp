
/**
* LeetCode The 6th problem :zigzag-conversion
* Auth:Barlowwang
* Date:2019-03-21
**/
#include <iostream>
#include <string>
using namespace std;
string convert(string s, int numRows)
{
    int i = 0, row = 0, cols = 0, tmp = 0, len = s.length();
    char *words = new char[len + 1];
    while (i < len)
    {
        tmp = (2 * numRows - 2) * cols + row;
        if (tmp < len - 1)
        {
            if (row == 0 || row == numRows - 1)
            {
                words[i] = s[tmp];
            }
            else
            {
                words[i] = s[tmp];
                tmp = tmp + 2 * (numRows - row - 1);
                if (tmp < len)
                {
                    words[i + 1] = s[tmp];
                    i++;
                }
            }
            cols++;
            i++;
        }
        else
        {
            row++;
            cols = 0;
        }
    }
    words[len] = '\0';
    string rs(words);
    return rs;
}
int main()
{
    string s;
    int i;
    while (1)
    {
        cin >> s >> i;
        cout << endl
             << convert(s, i) << endl;
    }
}