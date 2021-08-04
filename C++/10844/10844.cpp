#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long* step = new long long[n]{0};
	long long count[10];
	count[0] = 0;
	for (int i = 1; i < 10; i++)
	{
		count[i] = 1;
	}
	step[0] = 9;
	for (int i = 1; i < n; i++)
	{
		long long count2[10] = { 0 };
		for (int j = 0; j < 10; j++)
		{
			if (j == 0 && count[0] != 0)
			{
				count2[1] += count[0];
			}
			else if(j == 9 && count[9] != 0)
			{
				count2[8] += count[9];
			}
			else
			{
				count2[j-1] += count[j]%1000000000;
				count2[j+1] += count[j]%1000000000;
			}
		}
		for (int j = 0; j < 10; j++)
		{
			step[i] += count2[j];
			step[i] = step[i] % 1000000000;
			count[j] = count2[j];
		}
	}
	cout << step[n-1];
}