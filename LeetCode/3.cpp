/**
* LeetCode The 3rd problem :longest-substring-without-repeating-characters
* Auth:Barlowwang
* Date:2018-12-*
**/
int lengthOfLongestSubstring(string s)
{
    int charMap[100];
    for (int i = 0; i < 100; i++)
        charMap[i] = -1;
    int currIndex = 0, currLength = 0, size = s.size(), maxLength = 0;
    while (currIndex != size)
    {
        char c = s[currIndex];
        if (charMap[c - 32] == -1)
        {
            charMap[c - 32] = currIndex;
            ++currLength;
        }
        else
        {
            maxLength = (maxLength > currLength) ? maxLength : currLength;
            currIndex = charMap[c - 32];
            for (int i = 0; i < 100; i++)
                charMap[i] = -1;
            currLength = 0;
        }
        ++currIndex;
    }
    maxLength = (maxLength > currLength) ? maxLength : currLength;
    return maxLength;
}