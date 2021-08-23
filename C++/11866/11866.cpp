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
    int count = 1;
    cout << "<";
    while (q.size() != 1)
    {
        if (count == k)
        {
            count = 1;
            cout << q.front() << ", ";
            q.pop();
            continue;
        }
        q.push(q.front());
        q.pop();
        count++;
    }
    cout << q.front() << ">";
}