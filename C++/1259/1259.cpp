#include <iostream>
using namespace std;
int main()
{
    while (true)
    {
        string n;
        cin >> n;
        if (n == "0")
            break;
        int a = 0;
        int b = n.length() - 1;
        string ans = "yes";
        while (a < b)
        {
            if (n[a] != n[b])
                ans = "no";
            a++;
            b--;
        }
        cout<<ans<<"\n";
    }
}