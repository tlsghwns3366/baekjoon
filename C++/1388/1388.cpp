#include <iostream>
using namespace std;
int n, m;
string s[50];
bool sb[50][50];
void f(int a, int b)
{
    if (s[a][b] == '-')
    {
        for (int i = b; i < m; i++)
        {
            if(s[a][i] == '-')
            {
                sb[a][i] = true;
            }
            else
                return;
        }
    }
    else if(s[a][b] == '|')
    {
        for (int i = a; i < n; i++)
        {
            if(s[i][b] == '|')
            {
                sb[i][b] = true;
            }
            else
                return;
        }

    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!sb[i][j])
            {
                ans++;
                f(i, j);
            }
        }
    }
    cout<<ans;
}