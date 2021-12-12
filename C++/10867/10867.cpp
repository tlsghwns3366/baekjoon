#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        m[temp]++;
    }
    for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << " ";
    }
}