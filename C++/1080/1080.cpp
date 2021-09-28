#include <iostream>
using namespace std;
int a[50][50];
int b[50][50];
void f(int x, int y, int n, int m)
{
    if (x + 3 > n || y + 3 > m)
        return;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[x + i][y + j] = !a[x + i][y + j];
        }
    }
}
int main()
{
    int n, m;
    int c = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = temp[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            b[i][j] = temp[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                f(i, j, n, m);
                c++;
            }
        }
    }
    bool temp = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                temp = false;
                break;
            }
        }
    }
    if (temp)
        cout << c;
    else
        cout << -1;
}