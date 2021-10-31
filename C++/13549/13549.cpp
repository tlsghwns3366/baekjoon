#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> q;
    int *kk = new int[100005];
    fill(kk, kk + 100005, INT_MAX);
    kk[n] = 0;
    q.push(make_pair(0, n));
    while (!q.empty())
    {
        int time = -q.top().first;
        int nk = q.top().second;
        q.pop();
        if (nk == k)
        {
            cout << time;
            break;
        }
        if (nk - 1 >= 0)
        {
            if (kk[nk - 1] > kk[nk] + 1)
            {
                kk[nk - 1] = kk[nk] + 1;
                q.push(make_pair(-(time + 1), nk - 1));
            }
        }
        if (nk + 1 <= k)
        {
            if (kk[nk + 1] > kk[nk] + 1)
            {
                kk[nk + 1] = kk[nk] + 1;
                q.push(make_pair(-(time + 1), nk + 1));
            }
        }
        if (nk * 2 <= k + 5)
        {
            if (kk[nk * 2] > kk[nk])
            {
                kk[nk * 2] = kk[nk];
                q.push(make_pair(-time, nk * 2));
            }
        }
    }
}