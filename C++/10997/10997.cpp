#include <iostream>
using namespace std;
char s[500][500];
int n;
void f(int a, int p)
{
    if (a == 1)
    {
        s[p][p] = '*';
        s[p + 1][p] = '*';
        s[p + 2][p] = '*';
        return;
    }
    int c = 4 * (a - 1) + 1;
    for (int i = p; i < c + p; i++)
    {
        s[p][i] = '*';
        s[p + c + 1][i] = '*';
    }
    for (int i = p; i < c + p + 2; i++)
    {
        s[i][p] = '*';
        s[i][p + c - 1] = '*';
    }
    s[p + 1][p + c - 1] = ' ';
    s[p + 2][p + c - 2] = '*';
    f(a - 1, p + 2);
}
int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << "*";
        return 0;
    }
    for (int i = 0; i < 4 * (n - 1) + 3; i++)
    {
        for (int j = 0; j < 4 * (n - 1) + 1; j++)
        {
            s[i][j] = ' ';
        }
    }
    f(n, 0);
    for (int i = 0; i < 4 * (n - 1) + 3; i++)
    {
        if (i == 1)
        {
            cout << "*\n";
            continue;
        }
        for (int j = 0; j < 4 * (n - 1) + 1; j++)
        {
            cout << s[i][j];
        }
        cout << "\n";
    }
}