#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    string nn[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
        nn[i] += nn[i];
        if (nn[i].find(s) != -1)
            count++;
    }
    cout << count;
}