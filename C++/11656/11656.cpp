#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<string> v;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s.substr(i, s.length() - i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}