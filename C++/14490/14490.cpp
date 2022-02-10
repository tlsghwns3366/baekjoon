#include <iostream>
#include <string>
using namespace std;
int f(int a, int b)
{
    if (a % b == 0)
        return b;
    return f(b, a % b);
}
int main()
{
    string s;
    cin >> s;
    string a = "";
    string b = "";
    bool temp = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ':')
        {
            temp = false;
            continue;
        }
        if (temp)
            a += s[i];
        else
            b += s[i];
    }
    int n = stoi(a);
    int m = stoi(b);
    int ans = f(n, m);
    cout << n / ans << ":" << m / ans;
}