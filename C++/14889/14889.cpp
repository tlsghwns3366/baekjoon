#include <iostream>
using namespace std;

int minans = 100;
int a = 0;
int b = 0;
void back(int **sij, int n, int *n2, int *n3, bool *mb, int x)
{
    if (a == n / 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (mb[i] == false)
            {
                if (b < n / 2)
                {
                    n3[b] = i + 1;
                    b++;
                    x++;
                }
            }
        }
        int start = 0;
        int link = 0;
        b = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i + 1; j < n / 2; j++)
            {
                start += sij[n2[i] - 1][n2[j] - 1] + sij[n2[j] - 1][n2[i] - 1];
                link += sij[n3[i] - 1][n3[j] - 1] + sij[n3[j] - 1][n3[i] - 1];
            }
        }
        if (abs(start - link) < minans)
            minans = abs(start - link);
        return;
    }

    for (int i = x; i < n; i++)
    {
        if (a < n / 2 && mb[i] == false)
        {
            n2[a] = i + 1;
            a++;
            mb[i] = true;
            back(sij, n, n2, n3, mb, i + 1);
            mb[i] = false;
            a--;
            n2[a] = 0;
            if (n2[0] == 0)
                return;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int **sij = new int *[n];
    int *n2 = new int[n / 2]{0};
    int *n3 = new int[n / 2]{0};
    bool *mb = new bool[n]{false};
    for (int i = 0; i < n; i++)
    {
        sij[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sij[i][j];
        }
    }
    back(sij, n, n2, n3, mb, 0);
    cout << minans;
}