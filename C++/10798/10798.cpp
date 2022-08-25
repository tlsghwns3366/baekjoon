#include <iostream>
using namespace std;
char ans[5][15];
int main()
{
    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            ans[i][j] = s[j];
        }
    }
    for(int i =0;i<15;i++)
    {
        for(int j = 0;j<5;j++)
        {
            if(ans[j][i] != NULL)
                cout<<ans[j][i];
        }
    }
}