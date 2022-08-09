#include <iostream>
#include <queue>
using namespace std;
bool sosu[10000];
int sosucount[10000];
char n[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main()
{
    int t;
    cin >> t;
    for (int i = 2; i < 10000; i++)
    {
        if (!sosu[i])
        {
            for (int j = i * 2; j < 10000; j += i)
            {
                sosu[j] = true;
            }
        }
    }
    for (int ts = 0; ts < t; ts++)
    {
        string a, b;
        cin >> a >> b;
        fill(sosucount, sosucount + 10000, 987654321);
        queue<string> q;
        q.push(a);
        sosucount[stoi(a)] = 0;
        while (!q.empty())
        {
            string x = q.front();
            q.pop();
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    string temp = x;
                    temp[j] = n[i];
                    int tx = stoi(temp);
                    if (!sosu[tx] && tx >= 1000)
                    {
                        if (sosucount[tx] > sosucount[stoi(x)] + 1)
                        {
                            sosucount[tx] = sosucount[stoi(x)] + 1;
                            q.push(temp);
                        }
                    }
                }
            }
        }
        cout << sosucount[stoi(b)] << "\n";
    }
}