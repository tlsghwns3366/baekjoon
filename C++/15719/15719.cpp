#include <iostream>
using namespace std;
int bn[10000001];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        bn[temp]++;
        if (bn[temp] == 2)
        {
            cout << temp;
            break;
        }
    }
}