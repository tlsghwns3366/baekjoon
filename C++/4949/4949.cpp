#include <iostream>
#include <stack>
using namespace std;
int main()
{
    while (true)
    {
        char a[102] = {};
        char b[102] = {};
        string c = {};
        cin.getline(a, 102);
        if (a[0] == '.')
            break;

        int p = 0;

        for (int i = 0; i < 102; i++)
        {
            if (a[i] == '(' || a[i] == ')' || a[i] == '[' || a[i] == ']')
            {
                b[p] = a[i];
                p++;
            }
        }
        c = b;
        for (int i = 1; i <= p; i++)
        {
            if (c[i - 1] == '(' && c[i] == ')')
            {
                c.erase(i - 1, 2);
                i = 0;
            }
            else if (c[i - 1] == '[' && c[i] == ']')
            {
                c.erase(i - 1, 2);
                i = 0;
            }
        }
        if (c.length() == 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}