#include <iostream>
using namespace std;
int leftmove(int *n, int lp);
int rightmove(int *n, int lp);
bool search(int *n, int lp, int *sp, int j);

int main()
{
    int n, m;
    cin >> n >> m;
    int *q = new int[n];
    int *sq = new int[m];
    int lp = n - 1;
    for (int i = 0; i < n; i++)
    {
        q[i] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> sq[i];
    }
    int i = 0;
    int count = 0;
    while (true)
    {
        if (i == m)
            break;
        if (sq[i] != q[0])
        {
            count++;
            if (search(q, lp, sq, i))
            {
                if (rightmove(q, lp) == sq[i])
                {
                    leftmove(q, lp);
                    lp--;
                    i++;
                }
            }
            else
            {
                if (leftmove(q, lp) == sq[i])
                {
                    leftmove(q, lp);
                    lp--;
                    i++;
                }
            }
        }
        else
        {
            leftmove(q, lp);
            lp--;
            i++;
        }
    }
    cout << count;
}
bool search(int *n, int lp, int *sp, int j)
{
    int c1 = 0, c2 = 0;
    //  Rsearch
    for (int i = 1; i < lp; i++)
    {
        c1++;
        if (sp[j] == n[i])
        {
            break;
        }
    }
    //  Lsearch
    for (int i = lp; i > 0; i--)
    {
        c2++;
        if (sp[j] == n[i])
        {
            break;
        }
    }
    return c1 >= c2;
}
int leftmove(int *n, int lp)
{
    int temp;
    if (n[0] != NULL)
        temp = n[0];
    for (int i = 0; i < lp; i++)
    {
        n[i] = n[i + 1];
    }
    n[lp] = temp;
    return *n;
}
int rightmove(int *n, int lp)
{
    int temp;
    if (n[0] != NULL)
        temp = n[lp];
    for (int i = lp; i > 0; i--)
    {
        n[i] = n[i - 1];
    }
    n[0] = temp;
    return *n;
}