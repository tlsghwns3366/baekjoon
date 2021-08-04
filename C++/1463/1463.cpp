#include <iostream>
using namespace std;

int count(int* one, int n)
{
	int* temp = new int[3]{ 0 };
	int temp2 = 0;
	if (one[n] != 0)
		return one[n];
	else if (n == 1)
		return 0;
	else
	{
		if (n % 3 == 0)
		{
			temp[0]++;
			temp[0] += count(one, n / 3);
			temp2 = temp[0];
		}

		if (n % 2 == 0)
		{
			temp[1]++;
			temp[1] += count(one, n / 2);
			temp2 = temp[1];
		}
		temp[2]++;
		temp[2] += count(one, n - 1);
		temp2 = temp[2];
	}
	for (int i = 0; i < 3; i++)
	{
		if (temp[i] != 0)
		{
			if (temp[i] < temp2)
			{
				temp2 = temp[i];
			}
		}
	}
	return one[n] = temp2;
}

int main()
{
	int n;
	cin >> n;
	int* one = new int[n+1]{ 0 };
	one[0] = 0;
	one[1] = 0;
	one[2] = 1;
	one[3] = 1;
	cout << count(one, n);
}