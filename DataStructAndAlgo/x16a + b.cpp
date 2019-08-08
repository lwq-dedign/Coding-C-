#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long stt(string s)
{
	long sum = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'F')
		{
			sum *= 16;
			sum += s[i] - 55;
		}
		else if (s[i] >= 'a' && s[i] <= 'f')
		{
			sum *= 16;
			sum += s[i] - 87;
		}
		else
		{
			sum *= 16;
			sum += s[i] - '0';
		}

	}
	return sum;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		long a1 = stt(s1);
		long a2 = stt(s2);
		if (a1 == 0 && a2 == 0)
		{
			break;
		}
		cout << a1 + a2 << endl;
	}
	system("pause");
	return 0;
}