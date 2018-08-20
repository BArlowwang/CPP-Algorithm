#ifndef QUICK_H
#define QUICK_H

#include "Sort.hpp"
#include <stack>
using namespace std;
template <class T>
class Quick final : public Sort<T>
{
  public:
    Quick() : Sort<T>(){};
    Quick(const vector<T> &data) : Sort<T>(data){};
    vector<T> method(const vector<T> data, const bool insc) override; ////non-recursive method
    void onePass(vector<T> &data, typename vector<T>::iterator &left, typename vector<T>::iterator &right, bool insc);
    // one pass of sort
    void method_recursive(vector<T> &data, typename vector<T>::iterator left, typename vector<T>::iterator right, const bool insc); //recursive method
    void method_non_recursive(vector<T> &data, const bool insc);                                                                    //recursive method
    void useRecursiveMethod(bool rec);

  private:
    bool recursive = false;
};

template <typename T>
void Quick<T>::onePass(vector<T> &data, typename vector<T>::iterator &left, typename vector<T>::iterator &right, bool insc)
{
    typename vector<T>::iterator temp = left;
    if (insc)
    {
        while (right != left)
        {
            while (right > left && *right > *temp)
                right--;
            while (right > left && *left <= *temp)
                left++;
            if (right != left)
                swap(*left, *right);
        }
        swap(*left, *temp);
    }
    else
    {
        while (right != left)
        {
            while (right<left && * right> * temp)
                right--;
            while (right < left && *left <= *temp)
                left++;
            if (right != left)
                swap(*left, *right);
        }
        swap(*left, *temp);
    }
}
template <typename T>
vector<T> Quick<T>::method(const vector<T> data, const bool insc)
{
    vector<T> tmp = data;
    if (recursive)
    {
        typename vector<T>::iterator right = prev(tmp.end());
        typename vector<T>::iterator left = tmp.begin();
        method_recursive(tmp, left, right, insc);
    }
    else{
        method_non_recursive(tmp,insc);
    }
        return tmp;
}
template <typename T>
void Quick<T>::method_non_recursive(vector<T> &data, const bool insc)
{
    //non-recursive method
    typename vector<T>::iterator right = prev(data.end());
    typename vector<T>::iterator left = data.begin();
    stack<typename vector<T>::iterator> s; //Explicitly maintain a stack,which stores the section of sort
    s.push(left);
    s.push(right);
    while (!s.empty())
    {
        right = s.top();
        s.pop();
        left = s.top();
        s.pop();
        typename vector<T>::iterator templeft = left;
        typename vector<T>::iterator tempright = right;
        onePass(data, left, right, insc);
        if (left - 1 > templeft)
        {
            s.push(templeft);
            s.push(prev(left));
        }
        if (left + 1 < tempright)
        {
            s.push(left + 1);
            s.push(tempright);
        }
    }
}
template <typename T>
void Quick<T>::method_recursive(vector<T> &data, typename vector<T>::iterator left, typename vector<T>::iterator right, const bool insc)
{
    if (left >= right)
        return;
    typename vector<T>::iterator rightTemp = right;
    typename vector<T>::iterator leftTemp = left;
    if (insc)
    {
        onePass(data, leftTemp, rightTemp, insc);
        method_recursive(data, left, leftTemp - 1, insc);
        method_recursive(data, rightTemp + 1, right, insc);
    }
}
template <typename T> 
void Quick<T>::useRecursiveMethod(bool rec){
    recursive=rec;
}
#endif //INSERT_H