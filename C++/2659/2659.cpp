#include <iostream>
using namespace std;
int fmin(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int time = a * 1000 + b * 100 + c * 10 + d;
    time = fmin(time, b * 1000 + c * 100 + d * 10 + a);
    time = fmin(time, c * 1000 + d * 100 + a * 10 + b);
    time = fmin(time, d * 1000 + a * 100 + b * 10 + c);
    int ans = 0;
    for (int i = 1111; i <= time; i++)
    {
        int temp = i;
        int tempa = temp / 1000;
        temp = temp % 1000;
        int tempb = temp / 100;
        temp = temp % 100;
        int tempc = temp / 10;
        temp = temp % 10;
        int tempd = temp;
        temp = fmin(i, tempa * 1000 + tempb * 100 + tempc * 10 + tempd);
        temp = fmin(temp, tempb * 1000 + tempc * 100 + tempd * 10 + tempa);
        temp = fmin(temp, tempc * 1000 + tempd * 100 + tempa * 10 + tempb);
        temp = fmin(temp, tempd * 1000 + tempa * 100 + tempb * 10 + tempc);
        if (i == temp)
            ans++;
    }
    cout << ans;
}