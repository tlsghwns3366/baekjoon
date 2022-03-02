#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> ans;
    for (int q = 0; q < n; q++)
    {
        int pi, li;
        cin >> pi >> li;
        priority_queue<int> temp;
        for (int i = 0; i < pi; i++)
        {
            int a;
            cin >> a;
            temp.push(-a);
        }
        while (temp.size() > li)
        {
            temp.pop();
        }

        if (pi < li)
            ans.push(-1);
        else
            ans.push(-(-temp.top()));
    }
    int anscount = 0;
    int anssize = ans.size();
    for (int i = 0; i < anssize; i++)
    {
        if (m - (-ans.top()) >= 0)
        {
            m = m - (-ans.top());
            anscount++;
            ans.pop();
        }
    }
    cout << anscount;
}