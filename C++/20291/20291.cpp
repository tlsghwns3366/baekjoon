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
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '.')
            {
                m[s.substr(j + 1)]++;
                break;
            }
        }
    }
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout<<iter->first<<" "<<iter->second<<"\n";
    }
}