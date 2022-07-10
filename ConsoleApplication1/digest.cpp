#include "digest.h"
#include <iostream>
#include <vector>
#include "Util.h"
using namespace std;
vector<int> FindDigest(vector<int>& X)
{
    vector<int> v;
    size_t n = X.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int g = abs(X[i] - X[j]);

            v.push_back(g);
        }
    }
    return v;
}
void Place(vector<int>& L, vector<int>& X, const int width, std::vector<int>& Answer)
{
    if (L.size() == 0)
    {
        Answer = X;
        cout << endl << "*****************" << endl;
        cout << "Answer:" << endl;
        Render(Answer);
        cout << endl<<  "*****************" << endl;
        return;
    }
    int y = FindMax(L);
    vector<int> r1 = DeltaToVector(X, y);
    if (IsSubsetOf(r1, L))
    { 
        X.push_back(y);
        RemoveSubset(L, r1);
        cout << "A-X:"; Render(X); cout << "  L:"; Render(L); cout << "  r1:"; Render(r1); cout << endl;
        Place(L, X, width, Answer);
        cout << "B-X:"; Render(X); cout << "  L:"; Render(L); cout << "  r1:"; Render(r1); cout << endl;
        RemoveFromVector(X, y);
        Add(L, r1);
    }
    int wy = width - y;
    vector<int> r2 = DeltaToVector(X, wy);
    if (IsSubsetOf(r2, L))
    {
        X.push_back(wy);
        RemoveSubset(L, r2);
        cout << "A-X:"; Render(X); cout << "  L:"; Render(L); cout << "  r2:"; Render(r2); cout << endl;
        Place(L, X, width, Answer);
        cout << "B-X:"; Render(X); cout << "  L:"; Render(L); cout << "  r2:"; Render(r2); cout << endl;
        RemoveFromVector(X, wy);
        Add(L, r2);
    }
    return;
}
void PartialDigest(vector<int>& L, vector<int>& X, std::vector<int>& Answer)
{
   int width = FindMax(L);
   RemoveFromVector(L, width);
   X.push_back(0); X.push_back(width);
   cout << "X:";Render(X);cout << "  L:";Render(L); cout << endl;
   Place(L, X, width, Answer);
}