#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int i;
    for (i = x + 1; i < 1000000; i++)
    {
        string s = to_string(x);
        string temp = to_string(i);
        for (int j = 0; j < s.length(); j++)
        {
            int a = temp.find(s[j]);
            if (a != -1)
                temp.erase(a, 1);
            else
                break;
        }
        if (temp == "")
        {
            cout << i;
            break;
        }
    }
    if (i == 1000000)
        cout << 0;
}