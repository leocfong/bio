// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
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

bool DoubleDigest(const vector<int>& a, const vector<int>& b, const vector<int>& ab)
{

    int a_size = a.size();
    int b_size = b.size();
    int ab_size = ab.size();
   // cout << "a size=" << a_size << ", a="; Render(a); cout << endl;
   // cout << "b size=" << b_size << ", b="; Render(b); cout << endl;
   // cout << "ab size=" << ab_size << ", ab="; Render(ab); cout << endl;
    vector<int> accum_a = Accumulate(a);
    vector<int> accum_b = Accumulate(b);
    int accum_a_size = accum_a.size();
    int accum_b_size = accum_b.size();
 //   cout << "accum_a size=" << accum_a_size << ", a="; Render(accum_a); cout << endl;
 //   cout << "accum_b size=" << accum_b_size << ", b="; Render(accum_b); cout << endl;

    vector<int> m = Merge(accum_a, accum_b);
    int m_size = m.size();
 //   cout << "m size=" << m_size << ", m="; Render(m); cout << endl;
    vector<int> f = FindFragments(m);
    int f_size = f.size();

 //   cout << "f size=" << f_size << ", f="; Render(f); cout << endl;
    bool eq = (f == ab);
    return eq;

}

void DoubleDigestFix()
{
    vector<int> a{ 1,4,5,6,2 };
    vector<int> b{ 3,8,3,3, 1 };
    vector<int> ab{ 1,2,2,5,1,3,2,1,1 };
    int a_size = a.size();
    int b_size = b.size();
    int ab_size = ab.size();
    cout << "a size=" << a_size << ", a="; Render(a); cout << endl;
    cout << "b size=" << b_size << ", b="; Render(b); cout << endl;
    cout << "ab size=" << ab_size << ", ab="; Render(ab); cout << endl;

    vector<int> accum_a = Accumulate(a);
    vector<int> accum_b = Accumulate(b);
    int accum_a_size = accum_a.size();
    int accum_b_size = accum_b.size();
    cout << "accum_a size=" << accum_a_size << ", a="; Render(accum_a); cout << endl;
    cout << "accum_b size=" << accum_b_size << ", b="; Render(accum_b); cout << endl;

    vector<int> m = Merge(accum_a, accum_b);
    int m_size = m.size();
    cout << "m size=" << m_size << ", m="; Render(m); cout << endl;
    vector<int> f = FindFragments(m);
    int f_size = f.size();

    cout << "f size=" << f_size << ", f="; Render(f); cout << endl;
    bool eq = (f==ab);
    cout << eq;

}
void DoubleDigest()
{
    //vector<int> a{ 1,4,5,6,2 };
    vector<int> a{ 2,6,5,4,1 };
    //vector<int> b{ 3,8,3,3,1 };
    vector<int> b{ 1,3,3,8,3 };
    vector<int> ab{ 1,2,2,5,1,3,2,1,1 };
    
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    do
    {
        do {
            bool eq = DoubleDigest(a, b, ab);
            cout << ".";
            if (eq) {
                cout << endl << "******************************" << endl;
                cout << "Answer found" << endl;
                cout << "a: "; RenderL(a);
                cout << "b: "; RenderL(b);
                cout << endl << "******************************" << endl;
                return;
            }

        } while (std::next_permutation(b.begin(), b.end()));
    } while (std::next_permutation(a.begin(), a.end()));
    bool eq = DoubleDigest(a, b, ab);
   
    if (eq) {
        cout << endl << "******************************" << endl;
        cout << "Answer found" << endl;
        cout << "a: "; RenderL(a);
        cout << "b: "; RenderL(b);
        cout << endl << "******************************" << endl;
        return;
    }

    cout << "Answer not found" << endl;
}
void GenerateSequenceFrame()
{
    vector<int> a{ 1,4,5,6,2 };
    vector<int> b{ 1,3,3,8,3,1 };
    int a_size = a.size();
    a_size = 3;
    vector<int> v(a_size, 0);
    vector<int> en(a_size, a_size-1);
    RenderL(v);
    while (GenerateSequence(a_size, a_size-1, v, en)){
        RenderL(v);
    }

}
int main()
{
    DoubleDigest();
    return 0;
}
