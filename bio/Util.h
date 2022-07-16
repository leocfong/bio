#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
template<typename T>
//insert unique value into a vector
void InsertUnique(vector<T>& v, T newValue)
{
    if (std::find(v.begin(), v.end(), newValue) == v.end()) {
        v.push_back(newValue);
    }
}
//find max value in an array
template<typename T>
T FindMax(T* arr, size_t n)
{
    int max = arr[0];
    for (size_t j = 0; j < n; ++j) {
        if (arr[j] > max) {
            max = arr[j];
        }
    }
    return max;
}
//find max value i a vector
template<typename T>
T FindMax(vector<T>& v)
{
    return *std::max_element(v.begin(), v.end());
}
//render array
template<typename T>
void Render(T* arr, size_t n)
{
    if (n == 0)
    {
        cout << "null" ;
        return;
    }
    if (n < 2)
    {
        cout << arr[0] ;
    }
    for (size_t j = 0; j < n - 1; ++j) {
        cout << arr[j] << ",";
    }
    cout << arr[n - 1] ;
   
}
//render vector
template<typename T>
void Render(std::vector<T>& v)
{
    
    int vsize = v.size();
    if (vsize == 0)
    {
        cout << "null" ;
        return;
    }
    if (vsize < 2)
    {
        cout << v[0] ;
        return;
    }
    for (int i=0;i<vsize-1;i++)
    {
        cout << v[i] << ",";
    }
    cout << v[vsize - 1];

}
//calcaulte delta to vector
template<typename T>
vector<T> DeltaToVector(vector<T>& v, T val)
{
    vector<T> r;
    for (auto it = v.begin(); it != v.end(); ++it) {
        int g = abs(val - *it);
        r.push_back(g);
    }
    return r;
}
template<typename T>
vector<T> DeltaToVector(T* vec, size_t vec_size, T val)
{
    vector<T> ret;

    for (size_t i = 0; i < vec_size - 1; i++)
    {
        int g = abs(vec[i] - val);
        cout << g << ",";
        ret.push_back(g);
    }
    return ret;
}
//remove value from vector
template<typename T>
void RemoveFromVector(vector<T>& v, T val)
{
   v.erase(std::remove(v.begin(), v.end(), val), v.end());
}
template<typename T>
void RemoveFromVectorOnce(vector<T>& v, T val)
{
    for (auto it = v.begin(); it != v.end(); ++it) {

        if (*it == val) {
            v.erase(it);
            return;
        }
    }
}
//determine if a value is in vector
template<typename T>
bool IsInVector(vector<T>& set, T val)
{
    if (std::find(set.begin(), set.end(), val) == set.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}
//determine if a vector is a subset of another vector
template<typename T>
bool IsSubsetOf(vector<T>& subset, vector<T>& set)
{
    for (auto it = subset.begin(); it != subset.end(); ++it) {

        if (IsInVector(set, *it) == false){
            return false;
        }
    }
    return true;
}
//remove subset from a set
template<typename T>
void RemoveSubset(vector<T>& set, vector<T>& subset)
{
    for (auto it = subset.begin(); it != subset.end(); ++it) {
        RemoveFromVectorOnce(set, *it);
    }
    return;
}
//add set to vector
template<typename T>
bool Add(vector<T>& set, vector<T>& add)
{
    for (auto it = add.begin(); it != add.end(); ++it) {
        set.push_back(*it);
    }
    return true;
}

//add set to vector
template<typename T>
vector<T> Accumulate(vector<T>& set)
{
    T acc = 0; vector<T> accvec;
    size_t set_size = set.size();
    for (int i = 0; i < set_size; i++)
    {
       T newVal = set[i] + acc;
       accvec.push_back(newVal);
       acc = newVal;

    }
    return accvec;

}
template<typename T>
void RemoveDuplicate(vector<T>& v)
{
    std::unordered_set<int> s(v.begin(), v.end());
    v.assign(s.begin(), s.end());
}

template<typename T>
vector<T> Merge(vector<T>& setA, vector<T>& setB)
{
    vector<T> m;
    Add(m, setA);
    Add(m, setB);
    RemoveDuplicate(m);
    sort(m.begin(), m.end());
    return m;
}
//add set to vector
template<typename T>
vector<T> FindFragments(vector<T>& set)
{
    vector<T> f;
    size_t set_size = set.size();
    f.push_back(set[0]);
    for (size_t i = 1; i < set_size; i++) {
        int g = set[i] - set[i - 1];
        f.push_back(g);
    }
    return f;
}