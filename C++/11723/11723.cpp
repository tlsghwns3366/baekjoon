#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;
    string s;
    int a, b = 0;
    for (int q = 0; q < m; q++)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> a;
            b |= (1 << a);
        }
        else if (s == "remove")
        {
            cin >> a;
            b &= ~(1 << a);
        }
        else if (s == "check")
        {
            cin >> a;
            if (b & (1 << a))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (s == "toggle")
        {
            cin >> a;
            b ^= (1 << a);
        }
        else if (s == "all")
        {
            b = (1 << 21) - 1;
        }
        else if (s == "empty")
        {
            b = 0;
        }
    }
}