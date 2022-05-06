#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}
int main()
{
    int n;
    cin >> n;
    vector<string> v;
    for (int q = 0; q < n; q++)
    {
        string temp;
        cin >> temp;
        string ans = "";
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] >= '0' && temp[i] <= '9')
            {
                ans += temp[i];
            }
            else
            {
                if (ans != "")
                {
                    string anst = "";
                    for (int j = 0; j < ans.length(); j++)
                    {
                        if (anst == "" && ans[j] == '0')
                            continue;
                        anst += ans[j];
                    }
                    if (anst == "")
                        anst += '0';
                    v.push_back(anst);
                }
                ans = "";
            }
        }
        if (ans != "")
        {
            string anst = "";
            for (int j = 0; j < ans.length(); j++)
            {
                if (anst == "" && ans[j] == '0')
                    continue;
                anst += ans[j];
            }
            if (anst == "")
                anst += '0';
            v.push_back(anst);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}