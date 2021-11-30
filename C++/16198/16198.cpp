#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
int ans;
int sum;
void f(int a)
{
    if (n - a == 2)
    {
        if (sum > ans)
            ans = sum;
        return;
    }
    for (int i = 1; i < n - a - 1; i++)
    {
        int temp = v[i];
        sum += v[i - 1] * v[i + 1];
        v.erase(v.begin() + i);
        f(a + 1);
        v.insert(v.begin() + i, temp);
        sum -= v[i - 1] * v[i + 1];
    }
}
int main()
{
    ans = 0;
    sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    f(0);
    cout << ans;
}