#include <iostream>
#include <string>
using namespace std;
string f(string a, string b)
{
    string temp = "";
    int s = 0;
    while (!a.empty() || !b.empty() || s)
    {
        if (!a.empty())
        {
            s += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty())
        {
            s += b.back() - '0';
            b.pop_back();
        }
        string t2 = "";
        t2 = (s % 10) + '0';
        temp = t2 + temp;
        s = s / 10;
    }

    return temp;
}
int main()
{
    int n, m;
    cin >> n >> m;
    string nm[101][101];
    fill(&nm[0][0], &nm[n][n], "0");
    nm[0][0] = "1";
    for (int i = 1; i <= n; i++)
    {
        nm[i][0] = "1";
        for (int j = 1; j <= m; j++)
        {
            nm[i][j] = f(nm[i - 1][j - 1], nm[i - 1][j]);
        }
    }
    cout << nm[n][m];
}