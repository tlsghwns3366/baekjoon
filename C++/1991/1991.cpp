#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<char, char>> v(26);
string f3(int a)
{
    string temp = "";
    temp += 'A' + a;
    if (v[a].second != '.')
    {
        temp = f3(v[a].second - 'A') + temp;
    }
    if (v[a].first != '.')
    {
        temp = f3(v[a].first - 'A') + temp;
    }
    return temp;
}
string f2(int a)
{
    string temp = "";
    temp += 'A' + a;
    if (v[a].first != '.')
    {
        temp = f2(v[a].first - 'A') + temp;
    }
    if (v[a].second != '.')
    {
        temp = temp + f2(v[a].second - 'A');
    }
    return temp;
}
string f1(int a)
{
    string temp = "";
    temp += 'A' + a;
    if (v[a].first != '.')
    {
        temp = temp + f1(v[a].first - 'A');
    }
    if (v[a].second != '.')
    {
        temp = temp + f1(v[a].second - 'A');
    }
    return temp;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v[t1 - 'A'].first = t2;
        v[t1 - 'A'].second = t3;
    }
    cout << f1(0) << "\n";
    cout << f2(0) << "\n";
    cout << f3(0);
}