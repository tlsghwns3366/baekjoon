#include <iostream>
using namespace std;
int nn[9][9];

bool che(int a, int b, int c)
{

    for (int i = 0; i < 9; i++)
    {
        if (nn[a][i] == c || nn[i][b] == c)
            return false;
    }
    a = (a / 3) * 3;
    b = (b / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (c == nn[a + i][b + j])
                return false;
        }
    }
    return true;
}
bool f()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (nn[i][j] == 0)
            {
                for (int k = 1; k < 10; k++)
                {
                    if (che(i, j, k))
                    {
                        nn[i][j] = k;
                        if (!f())
                            nn[i][j] = 0;
                    }
                }
                if (nn[i][j] == 0)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> nn[i][j];
        }
    }
    f();
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << nn[i][j] << " ";
        }
        cout << endl;
    }
}