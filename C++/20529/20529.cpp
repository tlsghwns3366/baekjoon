#include <iostream>
#include <vector>
using namespace std;

int checkstr(string s1, string s2)
{
    int value = 0;
    for (int i = 0; i < 4; i++)
    {
        if (s1[i] != s2[i])
            value++;
    }
    return value;
}

int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n > 32)
        {
            cout <<0<<endl;
        }
        else
        {
            int answer = 987654321;
            for (int i = 0; i < n - 2; i++)
            {
                for (int j = i+1; j < n - 1; j++)
                {
                    for (int k = j+1; k < n; k++)
                    {
                        answer = min(checkstr(v[i], v[j]) + checkstr(v[j], v[k]) + checkstr(v[i], v[k]), answer);
                    }
                }
            }
            cout << answer<<endl;
        }
    }
}
