#include <iostream>
using namespace std;
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int count = 0;
    while (true)
    {
        int temp = a.find(b);
        if (temp == -1)
            break;
        a.replace(temp, b.size(), "*");
        count++;
    }
    cout << count;
}