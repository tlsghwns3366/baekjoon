#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<string> ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == 'H' || s[i] == 'O' || s[i] == 'C')
        {
            string t = "";
            t = s[i];
            ans.push(t);
        }
        else if (s[i] == ')')
        {
            int temp = 0;
            while (!ans.empty() && ans.top() != "(")
            {
                if (ans.top() == "H")
                    temp += 1;
                else if (ans.top() == "C")
                    temp += 12;
                else if (ans.top() == "O")
                    temp += 16;
                else
                    temp += stoi(ans.top());
                ans.pop();
            }
            if (!ans.empty())
                ans.pop();
            ans.push(to_string(temp));
        }
        else if (s[i] >= '1' && s[i] <= '9')
        {
            int temp = 0;
            if (ans.top() == "H")
                temp += 1;
            else if (ans.top() == "C")
                temp += 12;
            else if (ans.top() == "O")
                temp += 16;
            else
                temp += stoi(ans.top());
            ans.pop();
            temp *= s[i] - '0';
            ans.push(to_string(temp));
        }
    }
    int sum = 0;
    while (!ans.empty())
    {
        if (ans.top() == "H")
            sum += 1;
        else if (ans.top() == "C")
            sum += 12;
        else if (ans.top() == "O")
            sum += 16;
        else
            sum += stoi(ans.top());
        ans.pop();
    }
    cout << sum;
}