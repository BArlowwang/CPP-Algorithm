#include <vector>
#include <iostream>
#include <string>
using namespace std;
void PMT(const string &src, int *next)
{
    next[0] = -1;                     //next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1,len = src.length(); //k初始化为-1
    for (int q = 1; q <= len - 1; q++)
    {
        while (k > -1 && src[k + 1] != src[q]) //如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
        {
            k = next[k]; //往前回溯
        }
        if (src[k + 1] == src[q]) //如果相同，k++
        {
            k = k + 1;
        }
        next[q] = k; //这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}
bool kmp(const string &src, const string &ptr, vector<int> &position)
{
    if (src.length() <= 0 || ptr.length() <= 0)
        return false;
    const int srcLength = src.length(), prtLength = ptr.length();
    int next[prtLength] = {0};
    PMT(ptr, next);
    int k = -1;
    for (int i = 0; i < srcLength; i++)
    {
        while (k > -1 && ptr[k + 1] != src[i]) //ptr和str不匹配，且k>-1（表示ptr和str有部分匹配）
            k = next[k];                       //往前回溯
        if (ptr[k + 1] == src[i])
            k = k + 1;
        if (k == prtLength - 1) //说明k移动到ptr的最末端
        {
            //cout << "在位置" << i-plen+1<< endl;
            k = -1;                                //重新初始化，寻找下一个
            i = i - prtLength + 1;                 //i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠），感谢评论中同学指出错误。
            position.push_back(i); //返回相应的位置
        }
    }
    return true;
}
int main()
{
    string src = "ababcdababedababccde";
    string prt = "ababc";
    vector<int> pos;
    if (kmp(src, prt, pos))
    {
        cout << endl
             << endl
             << endl;
        for (auto i : pos)
        {
            cout << i << endl;
        }
    }
    else
    {
        cout << "fail" << endl;
    }
    system("pause");
}