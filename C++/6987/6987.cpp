#include <iostream>
using namespace std;
int t[4][6][3];
int ans[4];
int n[6][3];
pair<int, int> temp[15];
void f(int c)
{
    if (c == 15)
    {
        for (int k = 0; k < 4; k++)
        {
            if (ans[k] == 1)
                continue;
            bool temp = true;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (t[k][i][j] != n[i][j])
                    {
                        temp = false;
                        break;
                    }
                }
                if (!temp)
                    break;
            }
            if (temp)
                ans[k] = 1;
        }

        return;
    }
    int a = temp[c].first;
    int b = temp[c].second;

    n[a][0]++;
    n[b][2]++;
    f(c + 1);
    n[a][0]--;
    n[b][2]--;

    n[a][1]++;
    n[b][1]++;
    f(c + 1);
    n[a][1]--;
    n[b][1]--;

    n[a][2]++;
    n[b][0]++;
    f(c + 1);
    n[a][2]--;
    n[b][0]--;
}
int main()
{
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> t[k][i][j];
            }
        }
    }
    int c = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            temp[c].first = i;
            temp[c].second = j;
            c++;
        }
    }
    f(0);
    for (int i = 0; i < 4; i++)
    {
        cout << ans[i] << " ";
    }
}