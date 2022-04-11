#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    stack<char> ansstack;
    for (int i = 0; i < s.length(); i++)
    {
        while (k && !ansstack.empty() && ansstack.top() < s[i])
        {
            ansstack.pop();
            k--;
        }
        ansstack.push(s[i]);
    }
    stack<char> outans;
    while (!ansstack.empty())
    {
        outans.push(ansstack.top());
        ansstack.pop();
    }
    int temp = outans.size();
    for (int i = 0; i < temp - k; i++)
    {
        cout << outans.top();
        outans.pop();
    }
}