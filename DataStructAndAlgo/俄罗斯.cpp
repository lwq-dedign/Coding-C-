#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int x[1010] = { 0 };
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		x[k]++;
	}
	int num = x[1];
	for (int i=1;i<=n;i++)
	{
		if (x[i] < num)
		{
			num = x[i];
		}
	}
	cout << num << endl;
	system("pause");
	return 0;
}