/**
* LeetCode The 13th problem :roman-to-integer
* Auth:Barlowwang
* Date:2019-03-08
**/
#include <iostream>
#include <string>

using namespace std;
int romanToInt(string s)
{
    int length = s.length(), result = 0;
    ;
    char curr, next;
    for (int i = 0; i < length;)
    {
        curr = s[i];
        next = s[i + 1];
        switch (curr)
        {
        case 'I':
            if (next == 'V')
            {
                result += 4;
                i += 2;
            }
            else if (next == 'X')
            {
                result += 9;
                i += 2;
            }
            else
            {
                result += 1;
                ++i;
            }
            break;
        case 'V':
            result += 5;
            ++i;
            break;
        case 'X':
            if (next == 'L')
            {
                result += 40;
                i += 2;
            }
            else if (next == 'C')
            {
                result += 90;
                i += 2;
            }
            else
            {
                result += 10;
                ++i;
            }
            break;
        case 'L':
            result += 50;
            ++i;
            break;
        case 'C':
            if (next == 'D')
            {
                result += 400;
                i += 2;
            }
            else if (next == 'M')
            {
                result += 900;
                i += 2;
            }
            else
            {
                result += 100;
                ++i;
            }
            break;
        case 'D':
            result += 500;
            ++i;
        break;case 'M':
            result += 1000;
            ++i;
            break;
        }
    }
    return result;
}
int  main()
{
    string r;
    while(1){
    cin>>r;
    cout<<romanToInt(r)<<endl;
    system("pause");
    }
}
/**  力扣大神的题解
 * 
    int romanToInt(string s) {        
        int sum = 0;
        int n[s.size()+1];
        n[s.size()]=0;
        for(int i = 0; i < s.length(); i++){           
            switch(s[i]){
                case 'I':  n[i]=1; break;
                case 'V':  n[i]=5; break;
                case 'X':  n[i]=10; break;
                case 'L':  n[i]=50; break;
                case 'C':  n[i]=100; break;
                case 'D':  n[i]=500; break;
                case 'M':  n[i]=1000; break;
                default :break;             
            }
        }
        //可以用int n[100]; n['I']=1;....表示
        
        for(int i = 0; i < s.length(); i++){
            if(n[i] < n[i+1]) {
                sum = sum + n[i+1] - n[i];
                i++;
            }else
                sum += n[i];
        }
       
        return sum;
    } 
*/