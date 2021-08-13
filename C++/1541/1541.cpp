#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sic = "";
    cin >> sic;

    int p = 0;
    int m = 0;
    string temp = "";
    bool mp = true;
    for (int i = 0; i <= sic.length(); i++)
    {
        if (sic[i] == '+' || sic[i] == '-' || sic[i] == '\0')
        {
            if (mp)
            {
                p += stoi(temp);
            }
            else
            {
                m += stoi(temp);
            }
            if (sic[i] == '-')
                mp = false;
            temp = "";
            continue;
        }
        else
            temp += sic[i];
    }
    cout << p - m << endl;
}