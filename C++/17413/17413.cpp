#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    stack<char> st;
    getline(cin, s);
    bool b = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<')
        {
            if (!st.empty())
            {
                int temp = st.size();
                for (int j = 0; j < temp; j++)
                {
                    cout << st.top();
                    st.pop();
                }
            }
            cout << "<";
            b = true;
            continue;
        }
        else if (s[i] == '>')
        {
            cout << ">";
            b = false;
            continue;
        }
        if (!b)
        {
            if (s[i] == ' ')
            {
                int temp = st.size();
                for (int j = 0; j < temp; j++)
                {
                    cout << st.top();
                    st.pop();
                }
                cout << " ";
                continue;
            }
            else
                st.push(s[i]);
        }
        else
        {
            cout << s[i];
        }
    }
    if (!st.empty())
    {
        int temp = st.size();
        for (int j = 0; j < temp; j++)
        {
            cout << st.top();
            st.pop();
        }
    }
}