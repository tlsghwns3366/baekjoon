#include <iostream>

using namespace std;
void back(int *nm, int n, int m, int z)
{
    if (z == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", nm[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        bool k = false;
        for (int j = 0; j < z; j++)
        {
            if (nm[j] == i + 1)
                k = true;
        }
        if (!k)
        {
            nm[z] = i + 1;
            back(nm, n, m, z + 1);
        }
    }
}
int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    int *nm = new int[m];

    for (int i = 0; i < m; i++)
    {
        nm[i] = 0;
    }

    back(nm, n, m, 0);
}