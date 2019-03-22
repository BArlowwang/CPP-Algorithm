/**
* LeetCode The 1st problem :two-sum
* Auth:Barlowwang
* Date:2018-12-*
**/

vector<int> twoSum(vector<int> &nums, int target)
{
    int size = nums.size();
    int temp = 0;
    vector<int> result;
    for (int i = 0; i < size; i++)
    {
        temp = target - nums[i];
        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] == temp)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}