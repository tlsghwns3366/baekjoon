#include <iostream>
using namespace std;

string s;
void swap(int a, int b)
{
    char temp;
    temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}
void reverse(int a, int b)
{
    while (a != b && a != --b)
    {
        swap(a++, b);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    for (int q = 0; q < n; q++)
    {
        getline(cin, s);
        int p = 0;
        s+=' ';
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(p, i);
                p = i + 1;
            }
        }
        cout << s << "\n";
    }
}