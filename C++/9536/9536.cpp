#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    for (int x = 0; x < t; x++)
    {
        string s;
        getline(cin, s);
        s += " ";
        while (true)
        {
            string temp;
            getline(cin, temp);
            if (temp == "what does the fox say?")
                break;
            temp = temp.substr(temp.rfind(" ") + 1, temp.length() - temp.rfind(" ") - 1);
            int j = 0;
            bool b = false;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == ' ')
                {
                    b = false;
                    if (j == temp.length())
                    {
                        s.erase(i - j, temp.length() + 1);
                        i -= temp.length() + 1;
                    }
                    j = 0;
                }
                else if (s[i] == temp[j] && !b)
                    j++;
                else
                    b = true;
            }
        }
        cout << s << endl;
    }
}