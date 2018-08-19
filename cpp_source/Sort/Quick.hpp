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
    vector<T> method(const vector<T> data, const bool insc) override;
    void onePass(vector<T> &data, typename vector<T>::iterator &left, typename vector<T>::iterator &right);

  private:
};

template <typename T>
void Quick<T>::onePass(vector<T> &data, typename vector<T>::iterator &left, typename vector<T>::iterator &right)
{
   typename vector<T>::iterator temp = left;
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
template <typename T>
vector<T> Quick<T>::method(const vector<T> data, const bool insc)
{
    vector<T> tmp = data;
    typename vector<T>::iterator right = prev(tmp.end());
    typename vector<T>::iterator left = tmp.begin();
    stack<typename vector<T>::iterator> s;
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
        onePass(tmp, left, right);
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
        for(auto i : tmp) cout<<i<< "  ";
        cout<<endl;
    }
    //onePass(tmp, left, right);

    return tmp;
}
#endif //QUICK_H