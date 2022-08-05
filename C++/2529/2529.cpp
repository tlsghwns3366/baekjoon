#include <iostream>
#include <string>
using namespace std;
int k;
char s[10];
bool b[10];
int ans[10];
string ansm = "0123456789";
string ansn = "9876543210";
void f(int a)
{
    if (a > k)
    {
        for (int i = 0; i < k; i++)
        {
            if (s[i] == '>' && ans[i] < ans[i + 1])
                return;
            if (s[i] == '<' && ans[i] > ans[i + 1])
                return;
        }
        string temp = "";
        for (int i = 0; i < k + 1; i++)
        {
            temp += to_string(ans[i]);
        }
        if (ansn > temp)
            ansn = temp;
        if (ansm < temp)
            ansm = temp;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!b[i])
        {
            b[i] = true;
            ans[a] = i;
            f(a + 1);
            b[i] = false;
        }
    }
}
int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
    }
    f(0);
    cout << ansm << "\n";
    cout << ansn;
}