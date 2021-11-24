#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
        if (m.find(s)->second > ans)
            ans = m.find(s)->second;
    }
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second == ans)
        {
            cout << iter->first;
            break;
        }
    }
}