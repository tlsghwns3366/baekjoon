#include <iostream>
using namespace std;
int main()
{
	int n;
	int a[49];
	int b[49];
	int s = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		for (int j = 0; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	int k = 0;
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == b[j])
			{
				s += a[k] * b[j];
				k++;
			}
		}
	}
	cout << s;
}