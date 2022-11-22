#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter" && m[s1] == 0)
            m[s1] = 1;
        else if (s2 == "leave" && m[s1] == 1)
            m[s1] = 0;
    }
    for (auto i = m.rbegin(); i != m.rend(); i++)
    {
        if (i->second == 1)
            cout << i->first << "\n";
    }
}