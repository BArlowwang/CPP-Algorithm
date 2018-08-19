#ifndef QUICK_H
#define QUICK_H

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
    return tmp;
}
#endif //QUICK_H