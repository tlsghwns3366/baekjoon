#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *a = new int[n]{0};
	int *b = new int[n]{0};
	int *c = new int[n]{0};

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int maxsum = 0;
	for (int i = 0; i < n; i++)
	{
		b[i]++;
		int maxone = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				if (maxone <= b[j])
					maxone = b[i] + b[j];
			}
		}
		c[n - i - 1]++;
		int maxtwo = 0;
		for (int j = n - i - 1; j < n; j++)
		{
			if (a[n - i - 1] > a[j])
			{
				if (maxtwo <= c[j])
					maxtwo = c[n - i - 1] + c[j];
			}
		}
		b[i] = maxone;
		c[n - i - 1] = maxtwo;
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] + c[i] > maxsum)
			maxsum = b[i] + c[i];
	}
	cout << maxsum + 1;
}