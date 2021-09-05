#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    int m;
    cin >> m;
    int mm[m];
    int mb[m];
    for (int i = 0; i < m; i++)
    {
        cin >> mm[i];
        mb[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a = n;
        int b = 0;
        while (a >= b)
        {
            int c = (a + b) / 2;
            if (mm[i] == nn[c])
            {
                mb[i] = 1;
                break;
            }
            else if (mm[i] < nn[c])
                a = c - 1;
            else if (mm[i] > nn[c])
                b = c + 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << mb[i] << " ";
    }
}
