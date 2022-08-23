#include <iostream>
using namespace std;
int n;
int nn[101];
bool bn[101];
int anscount;
bool ans[101];
bool f(int a, int b)
{
    if (bn[b])
    {
        if (a == b)
        {
            ans[a] = true;
            return true;
        }
        return false;
    }
    bn[b] = true;
    if (f(a, nn[b]))
    {
        ans[b] = true;
        return true;
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nn[i];
    }
    for (int i = 1; i <= n; i++)
    {
        bn[i] = true;
        f(i, nn[i]);
        fill(bn, bn + 100, false);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
            anscount++;
    }
    cout << anscount << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
            cout << i << "\n";
    }
}