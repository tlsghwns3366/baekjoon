#include <iostream>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'm')
            s[i] = s[i] + 13;
        else if (s[i] >= 'n' && s[i] <= 'z')
            s[i] = s[i] - 13;
        else if (s[i] >= 'A' && s[i] <= 'M')
            s[i] = s[i] + 13;
        else if (s[i] >= 'N' && s[i] <= 'Z')
            s[i] = s[i] - 13;
    }
    cout << s << endl;
}