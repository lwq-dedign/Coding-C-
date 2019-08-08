#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
int main()
{
	int n;
	int t = 0;
	cin >> n;
	while (n--)
	{
		t++;
		int  m;
		cin >> m;
		int maxx = -1001;
		int b, e;
		vector<int> v1(m + 1, 0);
		vector<int> v2(m + 1, 0);
		for (int i = 1; i <= m; i++)
		{
			cin >> v1[i];
			v2[i] = max(v2[i - 1] + v1[i], v1[i]);
			if (maxx < v2[i])
			{
				maxx = v2[i];
				e = i;
			}
		}
		int sum = 0;
		for (int j = e; j >= 1; --j)
		{
			sum += v1[j];
			if (sum == maxx)
			{
				b = j;
			}
		}
		cout << "Case " << t << ":" << endl;
		cout << maxx << " " << b << " " << e << endl;
		if (n)
		{
			cout << endl;
		}
	}
	system("pause");
	return 0;
}