
#ifndef SELECT_H
#define SELECT_H

#include "Sort.hpp"
#include <algorithm>
using namespace std;
template <class T>
class Select final : public Sort<T>
{
  public:
    Select() : Sort<T>(){};
    Select(const vector<T> &data) : Sort<T>(data){};
    vector<T> method(const vector<T> data, const bool insc) override; ////non-recursive method
};
template <typename T>
vector<T> Select<T>::method(const vector<T> data, const bool insc)
{
    vector<T> tmp = data;
    typename vector<T>::iterator selected;
    for (typename vector<T>::iterator i = tmp.begin(); i != tmp.end(); i++)
    {
        if(insc)
        selected = min_element(i, tmp.end());
        else
        selected = max_element(i, tmp.end());
        if (selected != i)
            swap(*i, *selected);
    }
    return tmp;
}
#endif //SELECT_H