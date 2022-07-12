#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int n, m;
    cin >> n >> m;
    char nm[n][m];
    int ans = 987654321;
    pair<int, int> p1, p2;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            nm[i][j] = s[j];
            if (s[j] == 'R')
            {
                p1.first = i;
                p1.second = j;
            }
            else if (s[j] == 'B')
            {
                p2.first = i;
                p2.second = j;
            }
        }
    }
    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;
    q.push({{p1, p2}, 0});
    while (!q.empty())
    {
        pair<int, int> tp1, tp2;
        tp1.first = q.front().first.first.first;
        tp1.second = q.front().first.first.second;
        tp2.first = q.front().first.second.first;
        tp2.second = q.front().first.second.second;
        int tempc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = tp1.first;
            int y1 = tp1.second;
            int x2 = tp2.first;
            int y2 = tp2.second;
            bool temp1 = false;
            bool temp2 = false;
            bool tans1 = false;
            bool tans2 = false;

            while (true)
            {
                if (nm[x1 + dx[i]][y1 + dy[i]] == '#')
                    break;
                else if (x1 + dx[i] == tp2.first && y1 + dy[i] == tp2.second)
                    temp1 = true;
                else if (nm[x1 + dx[i]][y1 + dy[i]] == 'O')
                    tans1 = true;
                x1 += dx[i];
                y1 += dy[i];
            }
            while (true)
            {
                if (nm[x2 + dx[i]][y2 + dy[i]] == '#')
                    break;
                else if (x2 + dx[i] == tp1.first && y2 + dy[i] == tp1.second)
                    temp2 = true;
                else if (nm[x2 + dx[i]][y2 + dy[i]] == 'O')
                    tans2 = true;
                x2 += dx[i];
                y2 += dy[i];
            }
            if (temp1)
            {
                x1 -= dx[i];
                y1 -= dy[i];
            }
            if (temp2)
            {
                x2 -= dx[i];
                y2 -= dy[i];
            }

            if (tans1 && !tans2)
                ans = ans > tempc + 1 ? tempc + 1 : ans;

            if (!tans2 && tempc + 1 <= 10 && !(tp1.first == x1 && tp1.second == y1 && tp2.first == x2 && tp2.second == y2))
            {
                q.push({{{x1, y1}, {x2, y2}}, tempc + 1});
            }
        }
    }
    if (ans == 987654321 || ans > 10)
        cout << -1;
    else
        cout << ans;
}