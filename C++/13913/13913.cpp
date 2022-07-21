#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int nk[100001];
int count[100001];
int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    fill(count, count + 100001, 987654321);
    nk[n] = n;
    count[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        if (temp > 0 && count[temp - 1] > count[temp])
        {
            q.push(temp - 1);
            nk[temp - 1] = temp;
            count[temp - 1] = count[temp] + 1;
        }
        if (temp + 1 < 100001 && count[temp + 1] > count[temp])
        {
            q.push(temp + 1);
            nk[temp + 1] = temp;
            count[temp + 1] = count[temp] + 1;
        }
        if (temp * 2 < 100001 && count[temp * 2] > count[temp])
        {
            q.push(temp * 2);
            nk[temp * 2] = temp;
            count[temp * 2] = count[temp] + 1;
        }
    }
    stack<int> ans;
    ans.push(k);
    int tk = k;
    while (true)
    {
        if (nk[tk] == tk)
            break;
        else
        {
            ans.push(nk[tk]);
            tk = nk[tk];
        }
    }
    cout << ans.size() - 1 << "\n";
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}