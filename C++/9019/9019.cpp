#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
char str[4] = {'D', 'S', 'L', 'R'};
int f(int a, char str)
{
    if (str == 'D')
    {
        return (a * 2) % 10000;
    }
    else if (str == 'S')
    {
        if (a == 0)
            return 9999;
        else
            return a - 1;
    }
    else if (str == 'L')
    {
        return (a % 1000) * 10 + (a / 1000);
    }
    else if (str == 'R')
    {
        return (a % 10) * 1000 + (a / 10);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int a, b;
        cin >> a >> b;
        bool bfs[10000] = {
            false,
        };
        int ansint[10000] = {
            0,
        };
        char anschar[10000] = {
            '\0',
        };

        queue<int> q;
        q.push(a);
        bfs[a] = true;
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            if (n == b)
            {
                string sans = "";
                while (a != b)
                {
                    sans += anschar[b];
                    b = ansint[b];
                }
                reverse(sans.begin(), sans.end());
                cout << sans << "\n";
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int temp = f(n, str[i]);
                if (!bfs[temp])
                {
                    bfs[temp] = true;
                    ansint[temp] = n;
                    anschar[temp] = str[i];
                    q.push(temp);
                }
            }
        }
    }
}