#include<iostream>
using namespace std;

int getMax(int a, int b)
{
	return a>b ? a : b;
}
int s, e;
int Num(int *x ,int n)
{
	if (n <= 0 || x == NULL)
	{
		return 0;
	}
	int sum = x[0];
	int Max = x[0];
	for (int i = 1; i<n; i++)
	{
		sum = getMax(sum + x[i], x[i]);
		if (sum >Max)
		{
			Max = sum;
		}
	}
	return Max;
}
int main()
{
	int n;
	cin >> n;
	int *x = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i<n; ++i)
	{
		cin >> x[i];
	}
	cout << Num(x, n) << endl;
	return 0;
}



