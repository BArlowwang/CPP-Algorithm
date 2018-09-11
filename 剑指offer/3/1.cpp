#include <iostream>
using namespace std;
bool duplicate(int arr[], int length, int *duplication)
{
    if (arr == nullptr || length <= 0)
        return false;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0 || arr[i] > length - 1)
            return false;
        while (arr[i] != i)
        {
            if (arr[i] == arr[arr[i]])
            {
                
            }
            int temp = arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp;
        }
    }
    return false;
}