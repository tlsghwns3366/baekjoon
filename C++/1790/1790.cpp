#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int s = 0;
    int c = 1;
    int m = 10;
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (i % m == 0)
        {
            m = m * 10;
            c++;
        }
        s += c;
        if (s >= k)
        {
            s = s - k;
            string temp = to_string(i);
            reverse(temp.begin(), temp.end());
            ans = temp[s] - '0';
            break;
        }
    }
    cout << ans;
}