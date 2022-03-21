#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

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

            int temp = (n * 2) % 10000;
            if (!bfs[temp])
            {
                bfs[temp] = true;
                ansint[temp] = n;
                anschar[temp] = 'D';
                q.push(temp);
            }

            if (n == 0)
                temp = 9999;
            else
                temp = n - 1;

            if (!bfs[temp])
            {
                bfs[temp] = true;
                ansint[temp] = n;
                anschar[temp] = 'S';
                q.push(temp);
            }

            temp = (n % 1000) * 10 + (n / 1000);
            if (!bfs[temp])
            {
                bfs[temp] = true;
                ansint[temp] = n;
                anschar[temp] = 'L';
                q.push(temp);
            }

            temp = (n % 10) * 1000 + (n / 10);
            if (!bfs[temp])
            {
                bfs[temp] = true;
                ansint[temp] = n;
                anschar[temp] = 'R';
                q.push(temp);
            }
        }
    }
}