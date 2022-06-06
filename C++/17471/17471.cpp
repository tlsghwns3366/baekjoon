#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int h[10];
bool hb[10] = {
    false,
};
vector<int> v[11];
int ans = 987654321;
void bfs(int a, bool tb[])
{
    queue<int> q;
    q.push(a);
    tb[a] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x + 1].size(); i++)
        {
            if (hb[v[x + 1][i] - 1] == hb[x])
            {
                if (!tb[v[x + 1][i] - 1])
                {
                    tb[v[x + 1][i] - 1] = true;
                    q.push(v[x + 1][i] - 1);
                }
            }
        }
    }
}
void f(int a)
{
    if (a >= n)
    {
        int one = 0;
        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (hb[i] == 0)
                zero++;
            else
                one++;
        }
        if (zero == n || one == n)
            return;

        bool tb[10] = {
            false,
        };
        for (int i = 0; i < n; i++)
        {
            if (!hb[i])
            {
                bfs(i, tb);
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (hb[i])
            {
                bfs(i, tb);
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!tb[i])
                return;
        }
        one = 0;
        zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (hb[i])
                zero += h[i];
            else
                one += h[i];
        }
        if (ans > abs(zero - one))
            ans = abs(zero - one);
        return;
    }

    hb[a] = false;
    f(a + 1);
    hb[a] = true;
    f(a + 1);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int temp2;
            cin >> temp2;
            v[i + 1].push_back(temp2);
        }
    }
    f(0);
    if (ans == 987654321)
        cout << "-1";
    else
        cout << ans;
}