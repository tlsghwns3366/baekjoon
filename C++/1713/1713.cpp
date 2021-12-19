#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> v;
    int b[101];
    fill(b, b + 101, 0);
    for (int i = 0; i < s; i++)
    {
        int temp;
        cin >> temp;
        if (b[temp] == 0)
        {
            int cl = INT_MAX;
            if (v.size() == n)
            {
                for (int j = 0; j < v.size(); j++)
                {
                    if (b[v[j]] < cl)
                        cl = b[v[j]];
                }
                for (int j = 0; j < v.size(); j++)
                {
                    if (b[v[j]] == cl)
                    {
                        b[v[j]] = 0;
                        v.erase(v.begin() + j);
                        break;
                    }
                }
            }
            v.push_back(temp);
        }
        b[temp]++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}