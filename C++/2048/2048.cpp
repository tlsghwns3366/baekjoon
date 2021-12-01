#include <iostream>
using namespace std;
int n;
int **nn;
int ans;
void tempn(int **a, int **b)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void up(int **a)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int p = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j][i] != 0)
            {
                if (temp[p][i] == 0)
                {
                    temp[p][i] = a[j][i];
                }
                else if (temp[p][i] == a[j][i])
                {
                    temp[p][i] *= 2;
                    p++;
                }
                else
                {
                    p++;
                    temp[p][i] = a[j][i];
                }
            }
        }
    }
    tempn(a, temp);
}
void down(int **a)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int p = n - 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[j][i] != 0)
            {
                if (temp[p][i] == 0)
                {
                    temp[p][i] = a[j][i];
                }
                else if (temp[p][i] == a[j][i])
                {
                    temp[p][i] *= 2;
                    p--;
                }
                else
                {
                    p--;
                    temp[p][i] = a[j][i];
                }
            }
        }
    }
    tempn(a, temp);
}
void left(int **a)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int p = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                if (temp[i][p] == 0)
                {
                    temp[i][p] = a[i][j];
                }
                else if (temp[i][p] == a[i][j])
                {
                    temp[i][p] *= 2;
                    p++;
                }
                else
                {
                    p++;
                    temp[i][p] = a[i][j];
                }
            }
        }
    }
    tempn(a, temp);
}
void right(int **a)
{
    int **temp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int p = n - 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[i][j] != 0)
            {
                if (temp[i][p] == 0)
                {
                    temp[i][p] = a[i][j];
                }
                else if (temp[i][p] == a[i][j])
                {
                    temp[i][p] *= 2;
                    p--;
                }
                else
                {
                    p--;
                    temp[i][p] = a[i][j];
                }
            }
        }
    }
    tempn(a, temp);
}
void f(int **a, int c)
{
    if (c == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] > ans)
                    ans = a[i][j];
            }
        }
        return;
    }
    int **tempnn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tempnn[i] = new int[n];
    }
    tempn(tempnn, a);
    up(tempnn);
    f(tempnn, c + 1);
    tempn(tempnn, a);
    down(tempnn);
    f(tempnn, c + 1);
    tempn(tempnn, a);
    left(tempnn);
    f(tempnn, c + 1);
    tempn(tempnn, a);
    right(tempnn);
    f(tempnn, c + 1);
}
int main()
{
    cin >> n;
    nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
        }
    }
    f(nn, 0);
    cout << ans;
}