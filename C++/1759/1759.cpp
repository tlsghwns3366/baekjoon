#include <iostream>
#include <algorithm>
using namespace std;
int aeiou;
int temp;
void f(int l, int x, int a, int c, char *lc, char *ll)
{
    if (l == a && aeiou > 0 && temp > 1)
    {
        for (int i = 0; i < l; i++)
        {
            cout << ll[i];
        }
        cout << "\n";
        return;
    }
    for (int i = x; i < c; i++)
    {
        bool te = false;
        if (lc[i] == 'a' || lc[i] == 'e' || lc[i] == 'i' || lc[i] == 'o' || lc[i] == 'u')
        {
            aeiou++;
            te = true;
        }
        else
        {
            temp++;
            te = false;
        }
        ll[a] = lc[i];
        f(l, i + 1, a + 1, c, lc, ll);

        if (te)
            aeiou--;
        else
            temp--;
    }
}
int main()
{
    int l, c;
    cin >> l >> c;
    char *lc = new char[c];
    char *ll = new char[l];
    aeiou = 0;
    temp = 0;
    for (int i = 0; i < c; i++)
    {
        cin >> lc[i];
    }
    sort(lc, lc + c);
    f(l, 0, 0, c, lc, ll);
}