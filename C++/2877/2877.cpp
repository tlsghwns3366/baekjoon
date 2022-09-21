#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    string s = "";
    k++;
    while (k != 0)
    {
        if (k % 2 == 0)
        {
            k = k / 2;
            s = "4" + s;
        }
        else if (k % 2 == 1)
        {
            k = k / 2;
            s = "7" + s;
        }
    }
    cout << s.substr(1);
}