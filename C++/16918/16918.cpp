#include <iostream>
#include <stack>
using namespace std;
int r, c, n;
char rc[200][200];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
stack<pair<int, int>> s;

void f1(int t);
void f2(int t);

void f1(int t)
{
    if (t == n)
        return;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (rc[i][j] == 'O')
                s.push({i, j});
            else
                rc[i][j] = 'O';
        }
    }
    f2(t + 1);
}
void f2(int t)
{
    if (t == n)
        return;
    while (!s.empty())
    {
        int x = s.top().first;
        int y = s.top().second;
        rc[x][y] = '.';
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < r && x + dx[i] >= 0 && y + dy[i] < c && y + dy[i] >= 0)
                rc[x + dx[i]][y + dy[i]] = '.';
        }
    }
    f1(t + 1);
}
int main()
{
    cin >> r >> c >> n;
    for (int i = 0; i < r; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < c; j++)
        {
            rc[i][j] = temp[j];
        }
    }
    f1(1);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << rc[i][j];
        }
        cout << "\n";
    }
}