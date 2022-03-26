#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int nk[100001];
    int count[100001];
    fill(nk, nk + 100001, INT_MAX);
    fill(count, count + 100001, 0);
    nk[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        n = q.front();
        count[n]++;
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
    cout << nk[k] << "\n"
         << count[k];
}