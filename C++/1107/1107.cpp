#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int anscount = 0;

bool remob[10];
int ans[7];
int mf(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
void f(int sum, int c)
{
    if (c > 7)
        return;
    if (sum != 0)
    {
        int temp = 0;
        int mu = 1;
        for (int i = 0; i < c; i++)
        {
            temp += ans[i] * mu;
            mu *= 10;
        }
        if (n > temp)
            anscount = mf(anscount, sum + n - temp);
        else if (n < temp)
            anscount = mf(anscount, sum + temp - n);
        else
            anscount = mf(anscount, sum);
    }
    for (int i = 0; i < 10; i++)
    {
        if (!remob[i])
        {
            ans[c] = i;
            f(sum + 1, c + 1);
        }
    }
    return;
}
int main()
{
    cin >> n;
    cin >> m;
    fill(remob, remob + 10, false);
    fill(ans, ans + 7, 0);
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        remob[temp] = true;
    }

    if (n > 100)
        anscount = n - 100;
    else
        anscount = 100 - n;

    f(0, 0);

    cout << anscount;
}