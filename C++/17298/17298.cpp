#include <iostream>
#include <stack>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n]{0};
    int *b = new int[n]{0};
    stack<int> s;
    stack<int> p;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[i + 1])
        {
            b[i] = a[i + 1];
            while (!s.empty() && s.top() < a[i + 1])
            {
                b[p.top()] = a[i + 1];
                s.pop();
                p.pop();
            }
        }
        else
        {
            s.push(a[i]);
            p.push(i);
        }
    }
    s.pop();
    p.pop();
    while (!s.empty())
    {
        b[p.top()] = -1;

        s.pop();
        p.pop();
    }
    b[n - 1] = -1;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}