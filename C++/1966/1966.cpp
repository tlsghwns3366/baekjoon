#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        queue<int> q;
        queue<int> p;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            q.push(a);
            if (j == m)
                p.push(1);
            else
                p.push(0);
        }
        int count = 0;
        while (!q.empty())
        {
            int max = 0;
            for (int j = 0; j < q.size(); j++)
            {
                if (max < q.front())
                {
                    max = q.front();
                }
                q.push(q.front());
                q.pop();
            }

            for (int j = 0; j < q.size(); j++)
            {
                if (q.front() == max)
                {
                    count++;
                    if (p.front() == 1)
                        cout << count << endl;
                    q.pop();
                    p.pop();
                    break;
                }
                else
                {
                    q.push(q.front());
                    p.push(p.front());
                    q.pop();
                    p.pop();
                }
            }
        }
    }
}