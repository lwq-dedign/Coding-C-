#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

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
		map<string, int> bal;
		map<string, int>::iterator it;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			it = bal.find(s);
			if (it != bal.end())
			{
				bal[s] ++;
			}
			else
			{
				bal[s] = 1;
			}
		}
		int num = -1;
		string s1;
		for (map<string, int>::iterator l = bal.begin();l != bal.end();l++)
		{
			if (l->second > num)
			{
				num = l->second;
				s1 = l->first;
			}
		}
		cout << s1 << endl;
	}
	system("pause");
	return 0;
}
