#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.length(); i++)
    {
        string temp = "";
        string t2 = "";
        string t3 = "";
        for (int j = 0; j <= i; j++)
        {
            temp += s[j];
        }
        t2 = temp;
        t3 = temp;
        for (int j = 0; j < temp.length(); j++)
        {
            t2 += temp[temp.length() - j - 1];
            if (j > 0)
                t3 += temp[temp.length() - j - 1];
        }
        if (t3.find(s) != -1)
        {
            cout << t3.length() << endl;
            break;
        }
        else if (t2.find(s) != -1)
        {
            cout << t2.length() << endl;
            break;
        }
    }
}