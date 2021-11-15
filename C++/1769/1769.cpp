#include <iostream>
#include <string>
using namespace std;
int main()
{
    string n;
    cin >> n;
    int count = 0;
    while (n.length() != 1)
    {
        int temp = 0;
        count++;
        for (int i = 0; i < n.length(); i++)
        {
            temp += n[i] - '0';
        }
        n = to_string(temp);
    }
    cout << count << "\n";
    if ((n[0] - '0') % 3 == 0)
        cout << "YES";
    else
        cout << "NO";
}