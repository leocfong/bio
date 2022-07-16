// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "digest.h"
#include "Util.h"
using namespace std;
void PartialDigest()
{
    vector<int> L{ 2, 2, 3, 3, 4, 5, 6, 7, 8, 10 };
    vector<int> X; vector<int> Answer;
    cout << "Partial digest fragments:" << endl;
    Render(L); cout << endl; cout << endl;
    PartialDigest(L, X, Answer);
    sort(Answer.begin(), Answer.end());
    cout << "Original fragments:" << endl;
    Render(Answer); cout << endl; cout << endl;
    vector<int> D = FindDigest(Answer);
    sort(D.begin(), D.end());
    cout << "Reconstructing partial digest" << endl;
    Render(D); cout << endl;
}
void DoubleDigest()
{
    vector<int> a{ 1,4,5,6,2 };
    vector<int> b{ 3,8,3,3, 1 };
    vector<int> ab{ 1,2,2,5,1,3,2,1,1};
    int a_size = a.size();
    int b_size = b.size();
    int ab_size = ab.size();
    cout <<"a size=" << a_size << ", a="; Render(a); cout << endl;
    cout << "b size=" << b_size << ", b="; Render(b); cout << endl;
    cout << "ab size=" << ab_size << ", ab="; Render(ab); cout << endl;

    int a_index = 0;
    int b_index = 0;
    vector<int> f;
    bool cont = true; int ca = 0; int cb = 0;
    while (cont)
    {
        ca = ca + a[a_index];
        cb = cb + b[b_index];
        if (cb > ca)
        {
            int g = (cb - ca);
            f.push_back(g);
        }
        else
        {
            int g = (ca - cb);
            f.push_back(g);
        }
        if ((a_index< a_size) && (cb > ca)) {
            a_index++;
        }
        else if (b_index < b_size){
            b_index++;
        }
        else{
            cont = false;
        }
    }
    cout << "f:";
    Render(f); cout << endl;
}
int main()
{
    PartialDigest();
    return 0;
}
