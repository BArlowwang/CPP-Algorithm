/**
* LeetCode The 27th problem :remove-element
* Date:2019-03-16
**/
#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int len = nums.size();
    vector<int>::iterator it1;
    if(len==0) return 0;
    for (int i = 0; i < len;)
    {
        if (nums[i] == val){
            nums[i]=nums[--len];
            continue;
        }
        ++i;
    }
    return len;
}
