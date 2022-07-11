// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "digest.h"
#include "Util.h"
using namespace std;

int main()
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
    return 0;
}
