#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string ans;
    cin >> ans;

    string s[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> s[i];
    }
    bool b[ans.length()];
    int ak = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        fill(b, b + ans.length(), false);
        for (int j = 0; j < s[i].length(); j++)
        {
            int temp = 0;
            int a;
            while (true)
            {
                a = ans.find(s[i][j], temp);
                if (a == -1 || !b[a])
                    break;
                else if (b[a])
                {
                    temp = a + 1;
                }
            }
            if (a != -1)
            {
                b[a] = true;
            }
        }
        int count = 0;
        for (int j = 0; j < ans.length(); j++)
        {
            if (!b[j])
                count++;
        }
        if (count > 1)
            ak--;
        else if (count == 1 && s[i].length() > ans.length())
            ak--;
        else if (count == 0 && s[i].length() > ans.length() + 1)
            ak--;
    }
    cout << ak;
}