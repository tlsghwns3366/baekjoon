#include <iostream>
using namespace std;
bool sosu[1004001];
int main()
{
    int n;
    cin >> n;
    sosu[1] = true;
    for (int i = 2; i * i <= 1004000; i++)
    {
        if (sosu[i])
            continue;
        for (int j = i + i; j <= 1004000; j += i)
        {
            sosu[j] = true;
        }
    }
    for (int i = n; i <= 1004000; i++)
    {
        if (sosu[i])
            continue;
        string s = to_string(i);
        bool temp = false;
        for (int j = 0; j < s.length() / 2; j++)
        {
            if (s[j] != s[s.length() - j - 1])
            {
                temp = true;
                break;
            }
        }
        if (!temp)
        {
            cout << i;
            break;
        }
    }
}