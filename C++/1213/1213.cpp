#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string vs[26];
    for (int i = 0; i < s.length(); i++)
    {
        vs[s[i] - 'A'] += s[i];
    }
    string ansf = "";
    string ansb = "";
    for (int i = 0; i < 26; i++)
    {
        if (vs[i].length() != 0)
        {
            if (vs[i].length() % 2 == 0)
            {
                int temp = vs[i].length() / 2;
                for (int j = 0; j < temp; j++)
                {
                    ansf += vs[i].back();
                    vs[i].pop_back();
                    ansb = vs[i].back() + ansb;
                    vs[i].pop_back();
                }
            }
            else
            {
                if (vs[i].length() / 2 > 0)
                {
                    int temp = vs[i].length() / 2;
                    for (int j = 0; j < temp; j++)
                    {
                        ansf += vs[i].back();
                        vs[i].pop_back();
                        ansb = vs[i].back() + ansb;
                        vs[i].pop_back();
                    }
                }
            }
        }
    }
    int temp = 0;
    for (int i = 0; i < 26; i++)
    {
        if (vs[i].length() > 0)
        {
            ansf += vs[i].back();
            temp++;
        }
    }
    if (temp > 1)
    {
        cout << "I'm Sorry Hansoo";
    }
    else
    {
        cout << ansf + ansb;
    }
}
