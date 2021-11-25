#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, string> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        int dd, mm, yyyy;
        cin >> s >> dd >> mm >> yyyy;
        m[dd + mm * 30 + yyyy * 30 * 12] = s;
    }
    cout << m.rbegin()->second << "\n"
         << m.begin()->second;
}