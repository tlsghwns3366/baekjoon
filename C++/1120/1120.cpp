#include <iostream>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < b.length() - a.length() + 1; i++)
    {
        int count = 0;
        for (int j = 0; j < a.length(); j++)
        {
            if (b[j + i] == a[j])
                count++;
        }
        if (count > ans)
            ans = count;
    }
    cout << a.length() - ans;
}