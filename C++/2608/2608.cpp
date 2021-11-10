#include <iostream>
using namespace std;
string c1[6] = {"IV", "IX", "XL", "XC", "CD", "CM"};
int n1[6] = {4, 9, 40, 90, 400, 900};
char c2[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int n2[7] = {1, 5, 10, 50, 100, 500, 1000};
int sq(int i)
{
    if (i == 0)
        return 1;
    else
        return 10 * sq(i - 1);
}
string f2(int a)
{
    string s = "";
    int i = 6;
    while (a != 0)
    {
        if (i < 6 && n1[i] <= a)
        {
            s = s + c1[i];
            a -= n1[i];
        }
        else if (n2[i] <= a)
        {
            s = s + c2[i];
            a -= n2[i];
        }
        else
            i--;
    }
    return s;
}
int f(string s)
{
    int temp = 0;
    for (int i = 0; i < 6; i++)
    {
        int a = 0;
        a = s.find(c1[i]);
        if (a != -1)
        {
            temp += n1[i];
            s.erase(a, 2);
        }
    }
    int i = 0;
    while (!s.empty())
    {
        int a = s.find(c2[i]);
        if (a != -1)
        {
            s.erase(a, 1);
            temp += n2[i];
        }
        else
            i++;
    }
    return temp;
}

int main()
{
    string s1, s2;
    int a = 0;
    cin >> s1 >> s2;
    a = f(s1) + f(s2);
    cout << a << endl;
    cout << f2(a);
}