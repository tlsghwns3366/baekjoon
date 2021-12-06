#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(64);
    int x;
    cin >> x;
    int count = 0;
    while (true)
    {
        int ans = 0;
        count = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            count++;
            ans += v[i];
        }
        if (ans == x)
            break;
        if (ans > x)
        {
            v[0] = v[0] / 2;
            int sum = 0;
            for (int i = 0; i < v.size(); i++)
            {
                sum += v[i];
            }
            if (sum < x)
                v.push_back(v[0]);
        }
    }
    cout << count;
}