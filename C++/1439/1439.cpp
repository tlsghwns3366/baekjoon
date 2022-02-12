#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string s1 = s;
    string s2 = s;
    int counts1 = 0;
    int counts2 = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s1[i] == '1')
        {
            counts1++;
            int j = i;
            while (s1[j] == '1')
            {
                s1[j] = '0';
                j++;
            }
        }
        if (s2[i] == '0')
        {
            counts2++;
            int j = i;
            while (s2[j] == '0')
            {
                s2[j] = '1';
                j++;
            }
        }
    }
    if (counts1 < counts2)
        cout << counts1;
    else
        cout << counts2;
}