#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int nn[1000001];
int main()
{
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    fill(nn, nn + 1000001, INT_MAX);
    nn[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (a + u <= f && nn[a + u] > nn[a] + 1)
        {
            nn[a + u] = nn[a] + 1;
            q.push(a + u);
        }
        if (a - d >= 1 && nn[a - d] > nn[a] + 1)
        {
            nn[a - d] = nn[a] + 1;
            q.push(a - d);
        }
    }

    if (nn[g] != INT_MAX)
        cout << nn[g];
    else
        cout << "use the stairs";
}