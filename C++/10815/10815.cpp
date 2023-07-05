#include <iostream>
#include <algorithm>
using namespace std;

int nn[500001];
int mm[500001];
int mb[500001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> mm[i];
        mb[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a = n - 1;
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
