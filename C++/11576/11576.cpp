#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    int m;
    cin >> m;
    int mm[m];
    for (int i = 0; i < m; i++)
    {
        cin >> mm[i];
    }
    int t = 1;
    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        ans += mm[i] * t;
        t = t * A;
    }
    stack<int> s;
    while (ans != 0)
    {
        s.push(ans % B);
        ans = ans / B;
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}