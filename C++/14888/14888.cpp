#include <iostream>
using namespace std;

int maxans = -100000000;
int minans = 1000000000;
void back(int *a, char *b, bool *b2, int n, int x, int ans)
{
    if (x == n)
    {
        if (ans <= minans)
            minans = ans;
        if (ans >= maxans)
            maxans = ans;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '+' && b2[i] == false)
        {
            b2[i] = true;
            back(a, b, b2, n, x + 1, ans + a[x]);
            b2[i] = false;
        }
        else if (b[i] == '-' && b2[i] == false)
        {
            b2[i] = true;
            back(a, b, b2, n, x + 1, ans - a[x]);
            b2[i] = false;
        }
        else if (b[i] == '*' && b2[i] == false)
        {

            b2[i] = true;
            back(a, b, b2, n, x + 1, ans * a[x]);
            b2[i] = false;
        }
        else if (b[i] == '/' && b2[i] == false)
        {
            b2[i] = true;
            back(a, b, b2, n, x + 1, ans / a[x]);
            b2[i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    char *b = new char[n - 1];
    bool *b2 = new bool[n - 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0; i < 4; i++)
    {
        int c;
        cin >> c;
        for (int k = 0; k < c; k++)
        {
            if (i == 0)
            {
                b[j] = '+';
                j++;
            }
            else if (i == 1)
            {
                b[j] = '-';
                j++;
            }
            else if (i == 2)
            {
                b[j] = '*';
                j++;
            }
            else if (i == 3)
            {
                b[j] = '/';
                j++;
            }
        }
    }
    back(a, b, b2, n, 1, *a);
    cout << maxans << endl;
    cout << minans << endl;
}