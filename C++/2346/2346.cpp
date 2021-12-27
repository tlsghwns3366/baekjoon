#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n;
    cin >> n;
    deque<pair<int, int>> d;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        d.push_back({i, temp});
    }
    while (!d.empty())
    {
        cout << d.front().first << " ";
        int temp = d.front().second;
        d.erase(d.begin());
        if (d.empty())
            break;
        if (temp > 0)
        {
            for (int i = 0; i < temp - 1; i++)
            {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else
        {
            for (int i = 0; i < abs(temp); i++)
            {
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }
}