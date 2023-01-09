#include <iostream>
using namespace std;
int s;
string n;
char ans[25][150];
void f(int start, int c)
{
    for (int i = 0; i < s; i++)
    {
        switch (c)
        {
        case 1:
            ans[0][start + i + 1] = '-';
            break;
        case 2:
            ans[i + 1][start + s + 1] = '|';
            break;
        case 3:
            ans[(2 * s + 3) / 2][start + i + 1] = '-';
            break;
        case 4:
            ans[i + s + 2][start + s + 1] = '|';
            break;
        case 5:
            ans[2 * s + 3 - 1][start + i + 1] = '-';
            break;
        case 6:
            ans[i + s + 2][start] = '|';
            break;
        case 7:
            ans[i + 1][start] = '|';
            break;
        }
    }
}
int main()
{
    cin >> s >> n;
    fill(&ans[0][0], &ans[24][150], ' ');
    int start = 0;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] == '1')
        {
            f(start, 2);
            f(start, 4);
        }
        else if (n[i] == '2')
        {
            f(start, 1);
            f(start, 2);
            f(start, 3);
            f(start, 5);
            f(start, 6);
        }
        else if (n[i] == '3')
        {
            f(start, 1);
            f(start, 2);
            f(start, 3);
            f(start, 4);
            f(start, 5);
        }
        else if (n[i] == '4')
        {
            f(start, 2);
            f(start, 3);
            f(start, 4);
            f(start, 7);
        }
        else if (n[i] == '5')
        {
            f(start, 1);
            f(start, 3);
            f(start, 4);
            f(start, 5);
            f(start, 7);
        }
        else if (n[i] == '6')
        {
            f(start, 1);
            f(start, 3);
            f(start, 4);
            f(start, 5);
            f(start, 6);
            f(start, 7);
        }
        else if (n[i] == '7')
        {
            f(start, 1);
            f(start, 2);
            f(start, 4);
        }
        else if (n[i] == '8')
        {
            f(start, 1);
            f(start, 2);
            f(start, 3);
            f(start, 4);
            f(start, 5);
            f(start, 6);
            f(start, 7);
        }
        else if (n[i] == '9')
        {
            f(start, 1);
            f(start, 2);
            f(start, 3);
            f(start, 4);
            f(start, 5);
            f(start, 7);
        }
        else if (n[i] == '0')
        {
            f(start, 1);
            f(start, 2);
            f(start, 4);
            f(start, 5);
            f(start, 6);
            f(start, 7);
        }
        start += s + 3;
    }
    for (int i = 0; i < 2 * s + 3; i++)
    {
        for (int j = 0; j < (s + 2) * n.length() + n.length(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}