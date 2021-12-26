#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    int ans = 0;
    char temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            temp = '(';
        }
        else
        {
            if (temp == '(')
            {
                st.pop();
                ans += st.size();
            }
            else
            {
                st.pop();
                ans += 1;
            }
            temp = ')';
        }
    }
    cout << ans;
}