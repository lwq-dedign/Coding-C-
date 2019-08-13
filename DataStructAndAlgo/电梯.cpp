#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		int sum = 0;
		int *x = (int *)malloc(sizeof(int)*n);
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
			if (i >0)
			{
				if (x[i] - x[i - 1] > 0)
				{
					sum += 6 * (x[i] - x[i - 1]);
				}
				else
				{
					sum += 4 * (x[i - 1] - x[i]);
				}
			}
			else
			{
				sum += 6 * x[i];
			}
		}
		sum += 5 * n;
		cout << sum << endl;
	}
	system("pause");
	return 0;
}