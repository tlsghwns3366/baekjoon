#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string w[30] = {""};
        int count[30] = {
            1,
        };
        for (int j = 0; j < n; j++)
        {
            string a, b;
            cin >> a >> b;
            count[j] = 1;
            for (int k = 0; k < n; k++)
            {
                if (w[k] == b)
                {
                    count[k]++;
                    break;
                }
                else if (w[k] == "")
                {
                    w[k] = b;
                    count[k]++;
                    break;
                }
            }
        }

        int c = count[0];
        for (int k = 1; k < n; k++)
        {
            if (count[k] > 1)
                c = c * count[k];
        }
        cout << c - 1 << endl;
    }
}