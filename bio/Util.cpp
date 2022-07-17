#include "Util.h"
#include <vector>
using namespace std;

bool GenerateSequence(int n, int m, vector<int>& v, const vector<int>& en) {
    if (v == en)
    {
        return false;
    }
   
    int i = m;
    bool cont = true;

    while (v[i] >= m)
    {
        v[i] = 0;
        i--;
    }
    v[i]++;

    return true;
}
