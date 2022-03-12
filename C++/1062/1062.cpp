#include <iostream>
using namespace std;
int n, k;
int ans = 0;
bool bk[26];
string *instr;
void f(int c, int a)
{
    if (c == k)
    {
        int temp = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < instr[i].length(); j++)
            {
                if (!bk[instr[i][j] - 'a'])
                {
                    temp--;
                    break;
                }
            }
        }
        if (ans < temp)
            ans = temp;
        return;
    }
    for (int i = a; i < 26; i++)
    {
        if (!bk[i])
        {
            bk[i] = true;
            f(c + 1, i);
            bk[i] = false;
        }
    }
}
int main()
{
    cin >> n >> k;
    instr = new string[n];
    bk['a' - 'a'] = true;
    bk['c' - 'a'] = true;
    bk['i' - 'a'] = true;
    bk['n' - 'a'] = true;
    bk['t' - 'a'] = true;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        instr[i] = "";
        for (int j = 4; j < temp.length() - 4; j++)
        {
            instr[i] += temp[j];
        }
    }
    if (k - 5 >= 0)
    {
        f(5, 0);
        cout << ans;
    }
    else
        cout << 0;
}