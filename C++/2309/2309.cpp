#include <iostream>
#include <algorithm>
using namespace std;
int n[9];
int s = 0;
bool b[9];
bool f(int end)
{
    if (end == 2)
    {
        int temp = 0;
        for (int i = 0; i < 9; i++)
        {
            if (b[i])
                temp += n[i];
        }
        if (s - temp == 100)
        {
            for (int i = 0; i < 9; i++)
            {
                if (!b[i])
                    cout << n[i] << "\n";
            }
            return false;
        }
        return true;
    }
    for (int i = 0; i < 9; i++)
    {
        if (!b[i])
        {
            b[i] = true;
            if (!f(end + 1))
                break;
            b[i] = false;
        }
    }
    return true;
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> n[i];
        s += n[i];
        b[i] = false;
    }
    sort(n, n + 9);
    f(0);
}