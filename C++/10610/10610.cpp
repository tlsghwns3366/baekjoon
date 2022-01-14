#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<>());
    long long int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
    }
    if (sum % 3 == 0 && s[s.length() - 1] == '0')
        cout << s;
    else
        cout << -1;
}