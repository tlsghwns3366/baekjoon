#include <iostream>
using namespace std;
int ks[6];
void f(int k, int *s, bool *sb, int a, int b)
{
    if (a == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << ks[i] << " ";
        }
        cout << "\n";

        return;
    }
    for (int i = b; i < k; i++)
    {
        if (!sb[i])
        {
            ks[a] = s[i];
            sb[i] = true;
            f(k, s, sb, a + 1, i + 1);
            sb[i] = false;
        }
    }
}
int main()
{
    while (true)
    {
        int k;
        cin >> k;
        if (k == 0)
            break;
        int *s = new int[k];
        bool *sb = new bool[k]{false};
        for (int i = 0; i < k; i++)
        {
            cin >> s[i];
        }
        f(k, s, sb, 0, 0);
        cout << "\n";
    }
}