#include <iostream>
using namespace std;
char nn[100][100];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            nn[i][j] = s[j];
        }
    }

    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (nn[i][j] == '.')
            {
                temp++;
            }
            else
            {
                if (temp >= 2)
                    ans1++;
                temp = 0;
            }
        }
        if (temp >= 2)
            ans1++;
    }
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (nn[j][i] == '.')
            {
                temp++;
            }
            else
            {
                if (temp >= 2)
                    ans2++;
                temp = 0;
            }
        }
        if (temp >= 2)
            ans2++;
    }
    cout << ans1 << " " << ans2;
}