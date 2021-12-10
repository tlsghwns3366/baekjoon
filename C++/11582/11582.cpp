#include <iostream>
#include <climits>
using namespace std;
int n;
int *nn;
int *ans;
int k;
void f(int a, int b, int c)
{
    int p1 = a;
    int p2 = (a + b) / 2;
    int p3 = a;
    if (b - a == 1)
    {
        if (c == k)
        {
            for (int i = a; i < b; i++)
            {
                cout << nn[i] << " ";
            }
        }
        return;
    }
    f(p1, p2, c * 2);
    f(p2, b, c * 2);
    while (p3 < b - 1)
    {
        if (nn[p1] < nn[p2])
        {
            ans[p3] = nn[p1];
            p1++;
        }
        else
        {
            ans[p3] = nn[p2];
            p2++;
        }
        p3++;
        if (p1 >= (a + b) / 2)
        {
            for (int i = p2; i < b; i++)
            {
                ans[p3] = nn[i];
                p3++;
            }
        }
        if (p2 >= b)
        {
            for (int i = p1; i < (a + b) / 2; i++)
            {
                ans[p3] = nn[i];
                p3++;
            }
        }
    }
    for (int i = a; i < b; i++)
    {
        nn[i] = ans[i];
    }
    if (c == k)
    {
        for (int i = a; i < b; i++)
        {
            cout << nn[i] << " ";
        }
    }
}
int main()
{
    cin >> n;
    nn = new int[n];
    ans = new int[n];
    fill(ans, ans + n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    cin >> k;
    f(0, n, 1);
}