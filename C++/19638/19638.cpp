#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, h, t;
    cin >> n >> h >> t;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    for (int i = 0; i < t; i++)
    {
        if (q.top() < h)
        {
            cout << "YES\n";
            cout << i;
            return 0;
        }

        int temp = q.top();
        q.pop();
        if (temp > 1)
            temp /= 2;
        else if (temp == 0)
            temp = 1;
        q.push(temp);
    }
    if (q.top() < h)
    {
        cout << "YES\n";
        cout << t;
    }
    else
    {
        cout << "NO\n";
        cout << q.top();
    }
}