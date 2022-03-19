#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int nn[1001];
int mintime[1001];
vector<int> v[1001];
int count[1001];
int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n, k;
        int last;
        cin >> n >> k;
        fill(count, count + n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            cin >> nn[i];
            mintime[i] = nn[i];
            v[i].clear();
        }
        for (int i = 0; i < k; i++)
        {
            int x;
            int y;
            cin >> x >> y;
            v[y].push_back(x);
            v[x].push_back(y);
            count[y]++;
        }
        cin >> last;

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (count[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (int i = 0; i < v[temp].size(); i++)
            {
                if (count[v[temp][i]] <= 0)
                    mintime[temp] = max(mintime[temp], mintime[v[temp][i]] + nn[temp]);
            }

            for (int i = 0; i < v[temp].size(); i++)
            {
                count[v[temp][i]]--;
                if (count[v[temp][i]] == 0)
                    q.push(v[temp][i]);
            }
        }
        cout << mintime[last] << "\n";
    }
}