#include <iostream>
#include <queue>
using namespace std;
struct XY
{
    int x;
    int y;
};

int main()
{
    int t;
    cin >> t;
    for (int w = 0; w < t; w++)
    {
        int n;
        cin >> n;
        XY p[n + 2];
        bool pb[n + 2];
        fill(pb, pb + n + 2, false);
        cin >> p[0].x >> p[0].y;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        cin >> p[n + 1].x >> p[n + 1].y;
        queue<XY> q;
        q.push(p[0]);
        pb[0] = true;
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();
            for (int i = 1; i <= n + 1; i++)
            {
                if (!pb[i])
                {
                    int temp = abs(x - p[i].x) + abs(y - p[i].y);
                    if (temp <= 1000)
                    {
                        q.push(p[i]);
                        pb[i] = true;
                    }
                }
            }
        }
        if (pb[n + 1])
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}