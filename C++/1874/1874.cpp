#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    string sa = "";
    int count = 0;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (count < a)
        {
            for (int j = count + 1; j <= a; j++)
            {
                s.push(j);
                sa += "+\n";
            }
            count = a;
        }
        if (!s.empty() && s.top() == a)
        {
            for (int j = s.top(); j >= a; j--)
            {
                s.pop();
                sa += "-\n";
            }
        }
        else
            ans = false;
    }
    if (ans)
    {
        cout << sa;
    }
    else
        cout << "NO";
}