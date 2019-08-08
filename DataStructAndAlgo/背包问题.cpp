//19 1717427402
//474629280 340044001 458535524 80738170 904241932 645376690 53611478 690969776 684945902 18938732 475688968 970351041 492126153 997724258 992283814 749054681 812884853 12245802 242754871
//AC
#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
long long x[35];
long long num = 0;

void dfs(int nn,int mm)
{
	num++;
	if (nn == n-1)
	{
		return;
	}
	for (int i = nn + 1; i < n; i++)
	{
		if (x[i] + mm <= m)
		{
			dfs(i, x[i] + mm);
		}
	}
}

int main()
{
	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		sum += x[i];
	}
	if (sum <= m)
	{
		num = pow(2, n);
	}
	else
	{
		dfs(-1, 0);
	}
	cout << num << endl;
	system("pause");
	return 0;
}

