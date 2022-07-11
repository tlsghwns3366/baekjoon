#include <iostream>
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
    int p = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (nn[i] < nn[i + 1])
            p = i;
    }
    if (p == -1)
        cout << -1;
    else
    {
        for (int i = n - 1; i > p; i--)
        {
            if (nn[p] < nn[i])
            {
                int temp = nn[p];
                nn[p] = nn[i];
                nn[i] = temp;
                break;
            }
        }
        for (int i = p + 1; i < (n + p + 1) / 2; i++)
        {
            int temp = nn[i];
            nn[i] = nn[n - (i - p)];
            nn[n - (i - p)] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            cout << nn[i] << " ";
        }
    }
}