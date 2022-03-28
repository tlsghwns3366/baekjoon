#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]]++;
        }
        string ans = "YES\n";
        for (int i = 0; i < v.size(); i++)
        {
            string temp = "";
            for (int j = 0; j < v[i].length(); j++)
            {
                temp += v[i][j];
                if (m[temp] == 1 && temp != v[i])
                {
                    ans = "NO\n";
                    i = v.size();
                    break;
                }
            }
        }
        cout << ans;
    }
}