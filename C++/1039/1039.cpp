#include <iostream>
#include <queue>
using namespace std;
bool nn[1000001][10];
int main()
{
    string n;
    int k;
    cin >> n >> k;
    int m;
    m = n.length();
    queue<pair<string, int>> q;
    q.push({n, 0});
    int ans = -1;
    while (!q.empty())
    {
        string s = q.front().first;
        int count = q.front().second;
        int sn = stoi(s);
        q.pop();
        if (count == k)
            continue;
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                string s2 = s;
                if (i == 0 && s[j] == '0')
                    continue;
                    
                char temp = s2[i];
                s2[i] = s2[j];
                s2[j] = temp;

                int tempn = stoi(s2);
                if (count + 1 == k)
                {
                    ans = ans < tempn ? tempn : ans;
                }
                if (!nn[tempn][count + 1])
                {
                    nn[tempn][count + 1] = true;
                    q.push({s2, count + 1});
                }
            }
        }
    }
    cout << ans;
}