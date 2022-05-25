#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    string t;
    cin >> s >> t;
    int ans = 0;
    while (t.size() >= s.size())
    {
        if (t.back() == 'A')
            t.pop_back();
        else if (t.back() == 'B')
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        if (s == t)
        {
            ans = 1;
            break;
        }
    }
    cout << ans;
}