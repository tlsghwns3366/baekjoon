#include <iostream>
using namespace std;
int n;
string **nn;
bool **bb;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans1 = 0;
int ans2 = 0;
void f(int a, int b)
{
    bb[a][b] = true;
    for (int q = 0; q < 4; q++)
    {
        if (a + dx[q] < n && a + dx[q] >= 0 && b + dy[q] < n && b + dy[q] >= 0)
        {
            if (nn[a][b] == nn[a + dx[q]][b + dy[q]] && !bb[a + dx[q]][b + dy[q]])
                f(a + dx[q], b + dy[q]);
        }
    }
}
int main()
{
    cin >> n;
    string s;
    nn = new string *[n];
    bb = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        nn[i] = new string[n];
        bb[i] = new bool[n];
        for (int j = 0; j < s.length(); j++)
        {
            nn[i][j] = s[j];
            bb[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!bb[i][j])
            {
                f(i, j);
                ans1++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bb[i][j] = false;
            if (nn[i][j] == "R")
                nn[i][j] = "RG";
            if (nn[i][j] == "G")
                nn[i][j] = "RG";
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!bb[i][j])
            {
                f(i, j);
                ans2++;
            }
        }
    }
    cout << ans1 << " " << ans2;
}