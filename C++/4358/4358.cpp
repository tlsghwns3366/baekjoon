#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, double> m;
    int count = 0;
    string s;
    cout << fixed;
    cout.precision(4);
    while (getline(cin, s))
    {
        count++;
        m[s]++;
    }
    for (map<string, double>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << " " << (iter->second / count) * 100 << endl;
    }
}
