#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
class Sort
{
  public:
    Sort();
    Sort(const vector<T> &rawData);
    virtual ~Sort(){};
    void showRowData();
    void showSortedData();
    void setData(const vector<T> &rawdata);
    vector<T> getSortedData();
    void sort(const bool insc);
    virtual vector<T> method(const vector<T> data, const bool insc) = 0;

  private:
    vector<T> RawDate;
    vector<T> sortedDate;
    void swap(T &a, T &b);
    void printDate(const vector<T> &data);
};
template <class T>
Sort<T>::Sort(const vector<T> &rawData)
{
    setData(rawData);
}
template <class T>
void Sort<T>::sort(const bool insc)
{
    sortedDate = method(RawDate, insc);
}
template <class T>
void Sort<T>::setData(const vector<T> &rawData)
{
    // RawDate.assign(rawData.begin(),rawData.end);
    // function assign() will clear source vector and then assign
    vector<T> temp = rawData;
    RawDate.swap(temp);
    //swp will reset the space of vector
}
template <class T>
void Sort<T>::showRowData()
{
    printDate(RawDate);
}
template <class T>
void Sort<T>::showSortedData()
{
    printDate(sortedDate);
}
template <class T>
void Sort<T>::printDate(const vector<T> &data)
{
    int i = 0;
    for (auto tmp : data)
    {
        cout<< "  " << tmp;
    }
    cout<<endl;
}
template <class T>
inline void Sort<T>::swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
template <class T>
inline vector<T> Sort<T>::getSortedData()
{
    return sortedDate;
}
#endif // !SORT_H