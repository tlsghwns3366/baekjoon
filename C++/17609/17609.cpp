#include <iostream>
using namespace std;
int f(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            int x = i + 1;
            int y = j;
            int count = 1;
            while (x < y)
            {
                if (s[x] == s[y])
                {
                    x++;
                    y--;
                }
                else
                {
                    count++;
                    break;
                }
            }
            if (count == 1)
                return 1;
            x = i;
            y = j - 1;
            count = 1;
            while (x < y)
            {
                if (s[x] == s[y])
                {
                    x++;
                    y--;
                }
                else
                {
                    count++;
                    break;
                }
            }
            if (count == 1)
                return 1;
            return 2;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << f(s) << "\n";
    }
}