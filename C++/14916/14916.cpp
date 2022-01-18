#include <iostream>
using namespace std;
int f(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    cin >> n;
    int nn[n + 1];
    fill(nn, nn + n + 1, -1);
    nn[2] = 1;
    nn[4] = 2;
    nn[6] = 3;
    for (int i = 5; i <= n; i = i + 5)
    {
        nn[i] = i / 5;
    }
    for (int i = 5; i <= n; i++)
    {
        if (nn[i - 2] != -1)
        {
            if (nn[i - 5] == -1)
                nn[i] = nn[i - 2] + 1;
            else
                nn[i] = f(nn[i - 2] + 1, nn[i - 5] + 1);
        }
    }
    cout << nn[n];
}