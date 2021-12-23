#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int m;
    cin >> m;
    cin.ignore();
    stack<char> st1;
    stack<char> st2;
    for (int i = 0; i < s.length(); i++)
    {
        st1.push(s[i]);
    }
    for (int x = 0; x < m; x++)
    {
        string temp = "";
        getline(cin, temp);
        if (temp[0] == 'L')
        {
            if (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else if (temp[0] == 'D')
        {
            if (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        else if (temp[0] == 'B')
        {
            if (!st1.empty())
                st1.pop();
        }
        else
        {
            st1.push(temp[2]);
        }
    }
    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }
    while (!st2.empty())
    {
        cout << st2.top();
        st2.pop();
    }
}