
#ifndef INSERT_H
#define INSERT_H

#include "Sort.hpp"
using namespace std;
template <class T>
class Insert final : public Sort<T>
{
  public:
    Insert() : Sort<T>(){};
    Insert(const vector<T> &data) : Sort<T>(data){};
    vector<T> method(const vector<T> data, const bool insc) override; ////non-recursive method
};
template <typename T>
vector<T> Insert<T>::method(const vector<T> data, const bool insc)
{
    vector<T> tmp = data;
    T temp = tmp[0];
    for (int i = 1; i < tmp.size(); i++)  //Iterator is not used here,because insert() and erase() will invalidates the iterator
    {
        for (int j = 0; j < i; j++)
        {
            if (insc)
                if (tmp[j] > tmp[i])
                {
                    temp = tmp[i];
                    for (int k = i; k >= j; k--)
                    {
                        tmp[k] = tmp[k - 1];
                    }
                    tmp[j] = temp;
                    break;
                }
                else
                {
                    temp = tmp[i];
                    for (int k = i; k >= j; k--)
                    {
                        tmp[k] = tmp[k - 1];
                    }
                    tmp[j] = temp;
                    break;
                }
        }
    }
    return tmp;
}
#endif //INSERT_H