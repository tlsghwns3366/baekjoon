#include <iostream>
using namespace std;
int dx[4] = {-1, 0, 1, 1};
int dy[4] = {1, 1, 1, 0};
int nn[20][20];
int main()
{
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j < 20; j++)
        {
            cin >> nn[i][j];
        }
    }
    int ans = 0;
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i < 20; i++)
        {
            if (nn[i][j] != 0)
            {
                int temp = nn[i][j];
                for (int q = 0; q < 4; q++)
                {
                    int count = 1;
                    if (i - dx[q] < 20 && j - dy[q] < 20 && i - dx[q] > 0)
                    {
                        if (nn[i - dx[q]][j - dy[q]] == temp)
                            continue;
                    }
                    for (int w = 1; w < 6; w++)
                    {
                        int a = i + (w * dx[q]);
                        int b = j + (w * dy[q]);
                        if (a < 20 && b < 20 && a > 0)
                        {
                            if (nn[a][b] == temp)
                                count++;
                            else
                                break;
                        }
                    }
                    if (count == 5)
                    {
                        cout << temp << "\n";
                        cout << i << " " << j;
                        return 0;
                    }
                }
            }
        }
    }
    cout << ans;
}