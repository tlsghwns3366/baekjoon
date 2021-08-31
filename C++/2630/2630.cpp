#include <iostream>
using namespace std;
int white = 0;
int blue = 0;
int f(int n, int **nn)
{
    if (n != 1)
    {
        int a = n / 2;
        int **a1 = new int *[a];
        int **a2 = new int *[a];
        int **a3 = new int *[a];
        int **a4 = new int *[a];
        for (int i = 0; i < n; i++)
        {
            if (i < a)
            {
                a1[i] = new int[a]{0};
                a2[i] = new int[a]{0};
            }
            else
            {
                a3[i - a] = new int[a]{0};
                a4[i - a] = new int[a]{0};
            }

            for (int j = 0; j < n; j++)
            {
                if (i < a && j < a)
                {
                    a1[i][j] = nn[i][j];
                }
                else if (i < a && j >= a)
                {
                    a2[i][j - a] = nn[i][j];
                }
                else if (i >= a && j < a)
                {
                    a3[i - a][j] = nn[i][j];
                }
                else
                {
                    a4[i - a][j - a] = nn[i][j];
                }
            }
        }
        int b1 = f(a, a1);
        int b2 = f(a, a2);
        int b3 = f(a, a3);
        int b4 = f(a, a4);
        if (b1 == 1 && b2 == 1 && b3 == 1 && b4 == 1)
            return 1;
        else if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0)
            return 0;
        if (b1 == 1)
            blue++;
        else if (b1 == 0)
            white++;
        if (b2 == 1)
            blue++;
        else if (b2 == 0)
            white++;
        if (b3 == 1)
            blue++;
        else if (b3 == 0)
            white++;
        if (b4 == 1)
            blue++;
        else if (b4 == 0)
            white++;
    }
    else
    {
        if (nn[0][0] == 1)
            return 1;
        else
            return 0;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int **nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
        }
    }
    int b = f(n, nn);
    if (b == 1)
    {
        cout << 0 << endl;
        cout << 1 << endl;
    }
    else if (b == 0)
    {
        cout << 1 << endl;
        cout << 0 << endl;
    }
    else
    {
        cout << white << endl;
        cout << blue << endl;
    }
}