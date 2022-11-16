#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << "0";
    else
    {
        string s = "";
        while (n != 0)
        {
            if (n % -2 == 0)
            {
                s += "0";
                n /= -2;
            }
            else
            {
                s += "1";
                n = (n - 1) / -2;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--)
        {
            cout << s[i];
        }
    }
}