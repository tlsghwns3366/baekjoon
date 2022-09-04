#include <iostream>
using namespace std;
int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    bool ans = true;
    if (s1.length() < s2.length())
    {
        for (int i = 0; i < 2 * s2.length(); i++)
        {
            if (s1[i % s1.length()] != s2[i % s2.length()])
            {
                ans = false;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < 2 * s1.length(); i++)
        {
            if (s1[i % s1.length()] != s2[i % s2.length()])
            {
                ans = false;
                break;
            }
        }
    }
    cout << ans;
}