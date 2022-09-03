#include <iostream>
using namespace std;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int main()
{
    int n;
    cin >> n;
    char st[10][10];
    char ans[10][10];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            st[i][j] = s[j];
        }
    }
    bool anst = false;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'x')
            {
                int a = 0;
                if (st[i][j] == '*')
                    anst = true;
                for (int k = 0; k < 8; k++)
                {
                    if (i + dx[k] < n && i + dx[k] >= 0 && j + dy[k] < n && j + dy[k] >= 0)
                    {
                        if (st[i + dx[k]][j + dy[k]] == '*')
                            a++;
                    }
                }
                ans[i][j] = a + '0';
            }
            else
            {
                ans[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (st[i][j] == '*' && anst)
                cout << '*';
            else
                cout << ans[i][j];
        }
        cout << endl;
    }
}