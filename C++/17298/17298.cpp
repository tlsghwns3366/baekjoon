#include <iostream>
#include <stack>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n]{};
    int *b = new int[n]{};
    fill_n(b, n, -1);

    stack<int> s;
    stack<int> p;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (!s.empty() && s.top() < a[i])
        {
            b[p.top()] = a[i];
            s.pop();
            p.pop();
        }
        s.push(a[i]);
        p.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}