#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    string s;
    vector<string> ans;
    cin >> s;
    for (int a = 1; a < s.length() - 1; a++)
    {
        for (int b = a + 1; b < s.length(); b++)
        {
            string temp1 = "";
            string temp2 = "";
            string temp3 = "";
            temp1 = s.substr(0, a);
            temp2 = s.substr(a, b - a);
            temp3 = s.substr(b, s.length() - b);
            reverse(temp1.begin(), temp1.end());
            reverse(temp2.begin(), temp2.end());
            reverse(temp3.begin(), temp3.end());
            ans.push_back(temp1 + temp2 + temp3);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.front();
}