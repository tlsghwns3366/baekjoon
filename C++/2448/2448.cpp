#include <iostream>
using namespace std;
int n;
char **nn;
void f(int x, int y, int c)
{
    if (c == 3)
    {
        y--;
        nn[y][x] = nn[y][x + 1] = nn[y][x + 2] = nn[y][x + 3] = nn[y][x + 4] = '*';
        nn[y - 1][x + 1] = nn[y - 1][x + 3] = '*';
        nn[y - 2][x + 2] = '*';
        return;
    }
    f(x + c / 2, y - c / 2, c / 2);
    f(x + c, y, c / 2);
    f(x, y, c / 2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    nn = new char *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new char[n * 2 - 1];
        for (int j = 0; j < n * 2 - 1; j++)
        {
            nn[i][j] = ' ';
        }
    }
    f(0, n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {
            cout << nn[i][j];
        }
        cout << "\n";
    }
}