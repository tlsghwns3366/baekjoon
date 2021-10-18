#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ny[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int l;
        cin >> l;

        queue<pair<int, int>> q;
        int **ll = new int *[l];
        for (int i = 0; i < l; i++)
        {
            ll[i] = new int[l];
            fill(ll[i], ll[i] + l, INT_MAX);
        }
        pair<int, int> p1;
        pair<int, int> p2;
        cin >> p1.first >> p1.second;
        cin >> p2.first >> p2.second;
        ll[p1.first][p1.second] = 0;
        q.push(p1);
        while (!q.empty())
        {
            pair<int, int> temp;
            temp.first = q.front().first;
            temp.second = q.front().second;
            if (temp.first == p2.first && temp.second == p2.second)
                break;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                if (temp.first + nx[i] < l && temp.first + nx[i] >= 0 && temp.second + ny[i] < l && temp.second + ny[i] >= 0)
                {
                    if (ll[temp.first + nx[i]][temp.second + ny[i]] > ll[temp.first][temp.second] + 1)
                    {
                        ll[temp.first + nx[i]][temp.second + ny[i]] = ll[temp.first][temp.second] + 1;
                        q.push(make_pair(temp.first + nx[i], temp.second + ny[i]));
                    }
                }
            }
        }
        cout << ll[p2.first][p2.second] << "\n";
    }
}