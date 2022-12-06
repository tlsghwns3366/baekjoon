#include <iostream>
using namespace std;
int main()
{
    string l, r;
    cin >> l >> r;
    if (l.length() != r.length())
    {
        cout << 0;
    }
    else
    {
        int c = 0;
        for (int i = 0; i < l.length(); i++)
        {
            if (l[i] == r[i] && l[i] == '8')
                c++;
            else if (l[i] != r[i])
                break;
        }
        cout << c;
    }
}