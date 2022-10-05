#include <iostream>
using namespace std;
char nm[101][101];
bool nmb[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int f(int a, int b, char c)
{
    int t = 1;
    for (int i = 0; i < 4; i++)
    {
        if (a + dx[i] < m && a + dx[i] >= 0 && b + dy[i] < n && b + dy[i] >= 0)
        {
            if (nm[a + dx[i]][b + dy[i]] == c && !nmb[a + dx[i]][b + dy[i]])
            {
                nmb[a + dx[i]][b + dy[i]] = true;
                t += f(a + dx[i], b + dy[i], c);
            }
        }
    }
    return t;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            nm[i][j] = s[j];
        }
    }
    long long int ansb = 0;
    long long int answ = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!nmb[i][j])
            {
                nmb[i][j] = true;
                long long int temp = f(i, j, nm[i][j]);
                temp *= temp;
                if (nm[i][j] == 'B')
                    ansb += temp;
                else
                    answ += temp;
            }
        }
    }
    cout << answ << " " << ansb;
}