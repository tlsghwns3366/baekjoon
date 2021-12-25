#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    cout << "<";
    int temp = 0;
    while (!q.empty())
    {
        temp++;
        if (temp == k)
        {
            if (q.size() == 1)
                cout << q.front();
            else
                cout << q.front() << ", ";
            q.pop();
            temp = 0;
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    cout << ">";
}