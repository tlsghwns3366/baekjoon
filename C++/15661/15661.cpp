#include <iostream>
using namespace std;
int nn[21][21];
int n;
int sum;
int ans = 987654321;
int b[21];
void f(int a)
{
    if (a == n + 1)
    {
        int tempA = 0;
        int tempB = 0;
        int acount = 0;
        int bcount = 0;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == 0)
                acount++;
            else if (b[i] == 1)
                bcount++;
        }
        if (acount == 0 || bcount == 0)
            return;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[i] == 0 && b[j] == 0)
                    tempA += nn[i][j];
                else if (b[i] == 1 && b[j] == 1)
                    tempB += nn[i][j];
            }
        }
        ans = ans > abs(tempA - tempB) ? abs(tempA - tempB) : ans;
        return;
    }
    for (int t = 0; t < 2; t++)
    {
        b[a] = t;
        f(a + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nn[i][j];
        }
    }
    f(1);
    cout << ans;
}