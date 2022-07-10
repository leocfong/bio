#include <iostream>
using namespace std;

void render(int* r, int len)
{
    for (int i = 1; i <= len; i++)
    {
        cout << r[i] << ",";
    }
    cout << endl;
}

void sort(int* r, int len)
{
    int k = 0;
    for (int i = 1; i < len; i++)
    {
        k++;
        int j = 0;
        do
        {
            if (r[j] > r[j + 1])
            {
                int t = r[j + 1];
                r[j + 1] = r[j];
                r[j] = t;
            }
            j++;

        } while (j < len - i);
        render(r, len);
    }
}
int findMissing(int* r, int len)
{
    int i = 1;
    int c = r[0];
    int d = c;
    do
    {
        d++;
        c = r[i];
        if (c > d)
        {
            break;
        }
        i++;
    } while (i < len);
    return d;
}