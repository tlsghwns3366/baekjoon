#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool sb[12][6];
string s[12];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;
bool f(int a, int b)
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push({a, b});
    v.push_back({a, b});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 12 && x + dx[i] >= 0 && y + dy[i] < 6 && y + dy[i] >= 0)
            {
                if (sb[x + dx[i]][y + dy[i]] == true && s[x + dx[i]][y + dy[i]] == s[x][y])
                {
                    sb[x + dx[i]][y + dy[i]] = false;
                    q.push({x + dx[i], y + dy[i]});
                    v.push_back({x + dx[i], y + dy[i]});
                }
            }
        }
    }
    if (v.size() >= 4)
    {
        for (int i = 0; i < v.size(); i++)
        {
            s[v[i].first][v[i].second] = '.';
        }
        return true;
    }
    else
        return false;
}
bool chb()
{
    int temp = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (sb[i][j])
            {
                sb[i][j] = false;
                if (f(i, j))
                    temp++;
            }
        }
    }
    if (temp > 0)
    {
        ans++;
        return true;
    }
    else
        return false;
}
int main()
{
    for (int i = 0; i < 12; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (s[i][j] == '.')
                sb[i][j] = false;
            else
                sb[i][j] = true;
        }
    }

    while (true)
    {
        bool end = false;
        end = chb();
        if (!end)
            break;
        for (int i = 11; i >= 0; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (s[i][j] == '.')
                {
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (s[k][j] != '.')
                        {
                            s[i][j] = s[k][j];
                            s[k][j] = '.';
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (s[i][j] == '.')
                    sb[i][j] = false;
                else
                    sb[i][j] = true;
            }
        }
    }
    cout << ans;
}