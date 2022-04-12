#include <iostream>
#include <stack>
using namespace std;
int main()
{
    while (true)
    {
        int n;
        long long int ans = 0;
        cin >> n;
        if (n == 0)
            break;
        long long int lln[n + 1];
        stack<int> s;
        lln[n] = -1;
        for (int i = 0; i <= n; i++)
        {
            if (i != n)
                cin >> lln[i];
            while (!s.empty() && lln[i] < lln[s.top()])
            {
                long long int h = lln[s.top()];
                long long int w = i;
                s.pop();
                if (!s.empty())
                    w = i - s.top() - 1;
                ans = ans < h * w ? h * w : ans;
            }
            s.push(i);
        }
        cout << ans << "\n";
    }
}