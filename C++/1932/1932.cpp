#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	int** tr = new int* [n];
	int** sum = new int* [n];
	for (int i = 0; i < n; i++)
	{
		tr[i] = new int[i + 1];
		sum[i] = new int[i + 1]{ 0 };
		for (int j = 0; j <= i; j++)
		{
			cin >> tr[i][j];
		}
	}
	sum[0][0] = tr[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (j == 0)
				sum[i][j] = tr[i][j] + sum[i - 1][j];
			else if (i == j)
				sum[i][j] = tr[i][j] + sum[i - 1][j-1];
			else
			{
				if (sum[i - 1][j - 1] + tr[i][j] < sum[i - 1][j] + tr[i][j])
					sum[i][j] = sum[i - 1][j] + tr[i][j];
				else
					sum[i][j] = sum[i - 1][j - 1] + tr[i][j];
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum[n - 1][i] > max)
			max = sum[n - 1][i];
	}
	cout << max;
}