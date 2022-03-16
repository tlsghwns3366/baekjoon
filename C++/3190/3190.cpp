#include <iostream>
#include <queue>

using namespace std;

int n, k, l, c;
int ans = 0;
int nn[101][101];
char ab[10001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        nn[a][b] = 2;
    }
    queue<pair<int, int>> q;
    nn[1][1] = 3;
    q.push({1, 1});
    c = 0;
    cin >> l;
    for (int w = 0; w < l; w++)
    {
        int temp;
        cin >> temp >> ab[temp];
    }

    while (true)
    {
        ans++;
        int x = q.back().first;
        int y = q.back().second;
        if (!(x + dx[c] <= n && x + dx[c] >= 1 && y + dy[c] <= n && y + dy[c] >= 1) || nn[x + dx[c]][y + dy[c]] == 3)
        {
            cout << ans;
            return 0;
        }
        q.push({x + dx[c], y + dy[c]});
        if (nn[x + dx[c]][y + dy[c]] == 2)
        {
            nn[x + dx[c]][y + dy[c]] = 3;
        }
        else
        {
            nn[x + dx[c]][y + dy[c]] = 3;
            nn[q.front().first][q.front().second] = 0;
            q.pop();
        }

        if (ab[ans] != 0)
        {
            if (ab[ans] == 'D')
                c = (c + 1) % 4;
            else
                c = (4 + c - 1) % 4;
        }
    }
}
