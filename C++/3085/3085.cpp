#include <iostream>
using namespace std;
int maxt(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void swap(char *a, char *b)
{
    char temp = *a;
    a = b;
    b = &temp;
}
int check(string *s, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char temp = s[i][j];
            int count1 = 0;
            int count2 = 0;
            for (int k = j; k < n; k++)
            {
                if (temp == s[i][k])
                    count1++;
                else
                    break;
            }
            for (int k = i; k < n; k++)
            {
                if (temp == s[k][j])
                    count2++;
                else
                    break;
            }
            max = maxt(max, maxt(count1, count2));
        }
    }
    return max;
}
int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            swap(s[i][j], s[i][j + 1]);
            max = maxt(max, check(s, n));
            swap(s[i][j], s[i][j + 1]);
        }
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < n)
            {
                swap(s[i][j], s[i + 1][j]);
                max = maxt(max, check(s, n));
                swap(s[i][j], s[i + 1][j]);
            }
        }
    }
    cout << max << endl;
}