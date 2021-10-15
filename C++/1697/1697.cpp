#include <iostream>
#include <climits>
#include <queue>
using namespace std;
queue<int> q;
int main()
{
    int n, k;
    cin >> n >> k;
    int nk[100001];
    fill(nk, nk + 100001, INT_MAX);
    nk[n] = 0;
    if (n > 0)
    {
        q.push(n - 1);
        if (nk[n - 1] > nk[n])
            nk[n - 1] = nk[n] + 1;
    }
    if (n + 1 < 100001)
    {
        q.push(n + 1);
        if (nk[n + 1] > nk[n])
            nk[n + 1] = nk[n] + 1;
    }
    if (n * 2 < 100001)
    {
        q.push(n * 2);
        if (nk[n * 2] > nk[n])
            nk[n * 2] = nk[n] + 1;
    }
    while (!q.empty())
    {
        n = q.front();
        q.pop();
        if (n > 0 && nk[n - 1] > nk[n])
        {
            q.push(n - 1);
            nk[n - 1] = nk[n] + 1;
        }
        if (n + 1 < 100001 && nk[n + 1] > nk[n])
        {
            q.push(n + 1);
            nk[n + 1] = nk[n] + 1;
        }
        if (n * 2 < 100001 && nk[n * 2] > nk[n])
        {
            q.push(n * 2);
            nk[n * 2] = nk[n] + 1;
        }
    }
    cout << nk[k];
}