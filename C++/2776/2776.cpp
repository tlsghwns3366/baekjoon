#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
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
        for (int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            int a = 0;
            int b = n - 1;
            while (a < b)
            {
                int c = (a + b) / 2;
                if (nn[c] < temp)
                {
                    a = c + 1;
                }
                else if (nn[c] > temp)
                {
                    b = c - 1;
                }
                else
                    b = c;
            }
            if (nn[b] == temp)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}