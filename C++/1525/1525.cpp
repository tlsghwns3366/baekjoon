#include <iostream>
#include <queue>
#include <map>
using namespace std;

int d[4] = {-3, 1, 3, -1};
int main()
{
    string n = "";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char temp;
            cin >> temp;
            n += temp;
        }
    }
    queue<string> q;
    map<string, int> m;
    q.push(n);
    m[n] = 1;
    string ans = "123456780";
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        if (s == ans)
            break;
        int ze = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                ze = i;
        }
        for (int i = 0; i < 4; i++)
        {
            if (ze + d[i] < 0 || ze + d[i] >= 9)
                continue;
            if (i == 3 && ze % 3 == 0)
                continue;
            if (i == 1 && ze % 3 == 2)
                continue;
            string temps = s;
            swap(temps[ze], temps[ze + d[i]]);
            if (m[temps] == 0)
            {
                m[temps] = m[s] + 1;
                q.push(temps);
            }
        }
    }
    cout << m[ans] - 1;
}