#include <iostream>
using namespace std;
string s = "";
void swa(int a)
{
    char temp = s[a];
    s[a] = s[a + 1];
    s[a + 1] = temp;
}
int main()
{
    int n1, n2, t;
    string s1, s2;
    cin >> n1 >> n2 >> s1 >> s2 >> t;
    for (int i = 0; i < s1.length(); i++)
    {
        s += s1[s1.length() - i - 1];
    }
    for (int i = 0; i < s2.length(); i++)
    {
        s += s2[i];
    }
    for (int x = 0; x < t; x++)
    {
        for (int i = 0; i < s1.length(); i++)
        {
            if (s2.find(s[s.find(s1[i]) + 1]) != -1 && x >= i)
                swa(s.find(s1[i]));
        }
    }
    cout << s << endl;
}