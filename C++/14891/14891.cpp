#include <iostream>
using namespace std;

int t[4][8];
bool tb[4];
void L(int a);
void R(int a);

void L(int a)
{
    tb[a] = true;
    if (a + 1 < 4 && !tb[a + 1] && t[a][2] != t[a + 1][6])
        R(a + 1);
    if (a - 1 >= 0 && !tb[a - 1] && t[a][6] != t[a - 1][2])
        R(a - 1);
    int temp;
    temp = t[a][7];
    for (int i = 7; i > 0; i--)
    {
        t[a][i] = t[a][i - 1];
    }
    t[a][0] = temp;
}
void R(int a)
{
    tb[a] = true;
    if (a + 1 < 4 && !tb[a + 1] && t[a][2] != t[a + 1][6])
        L(a + 1);
    if (a - 1 >= 0 && !tb[a - 1] && t[a][6] != t[a - 1][2])
        L(a - 1);
    int temp;
    temp = t[a][0];
    for (int i = 0; i < 7; i++)
    {
        t[a][i] = t[a][i + 1];
    }
    t[a][7] = temp;
}
int main()
{
    for (int i = 0; i < 4; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < 8; j++)
        {
            t[i][j] = temp[j] - '0';
        }
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++)
    {
        int a, b;
        fill(tb, tb + 4, false);
        cin >> a >> b;
        a--;
        if (b == 1)
        {
            L(a);
        }
        else
        {
            R(a);
        }
    }
    int ans = 0;
    if (t[0][0] == 1)
        ans += 1;
    if (t[1][0] == 1)
        ans += 2;
    if (t[2][0] == 1)
        ans += 4;
    if (t[3][0] == 1)
        ans += 8;
    cout << ans;
}