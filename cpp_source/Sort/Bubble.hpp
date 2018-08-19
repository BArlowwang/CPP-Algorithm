#ifndef BUBBLE_H
#define BUBBLE_H

#include "Sort.hpp"
using namespace std;
template <class T>
class Bubble final : public Sort<T>
{
    public:
        Bubble() : Sort<T>(){};
        Bubble(const vector<T> &data) : Sort<T>(data){};
        vector<T> method(const vector<T> data, const bool insc) override;
    private:
};

template <typename T>
vector<T> Bubble<T>::method(const vector<T> data, const bool insc)
{
    vector<T> tmp=data;
    typename vector<T>::iterator outterIt = prev(tmp.end());
    while (outterIt != tmp.begin())
    {
        for (typename vector<T>::iterator innerIt = tmp.begin(); innerIt != outterIt; innerIt++)
        {
            if (insc)
            {
                if (*innerIt > *(innerIt + 1))
                {
                    swap(*innerIt, *(innerIt + 1));
                }
            }
            else
            {
                if (*innerIt < *(innerIt + 1))
                {
                   swap(*innerIt, *(innerIt + 1));
                }
            }
        }
        outterIt--;
    }
    return tmp;
}
#endif // !BUBBLE_H