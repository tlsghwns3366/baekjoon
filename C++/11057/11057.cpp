#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n + 1][10];
    nn[1][0] = 0;
    for (int i = 0; i < 10; i++)
    {
        nn[0][i] = 1;
        nn[1][9]++;
    }

    for (int i = 1; i <= n; i++)
    {
        nn[i][0] = 1;
        for (int j = 1; j < 10; j++)
        {
            nn[i][j] = (nn[i][j - 1] + nn[i - 1][j]) % 10007;
        }
    }
    cout <<nn[n][9];
}