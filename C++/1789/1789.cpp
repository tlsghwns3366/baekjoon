#include <iostream>
using namespace std;
int main()
{
    long long int s;
    cin >> s;
    long long int n = 0;
    long long int i = 1;
    long long int count = 0;
    while (s != n)
    {
        if (n + i > s)
        {
            n -= i;
            n += s - n;
            count--;
        }
        else
        {
            n += i;
        }
        i++;
        count++;
    }
    cout << count;
}