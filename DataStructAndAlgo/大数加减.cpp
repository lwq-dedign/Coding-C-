#include <iostream>
#include <string>
#include <algorithm>
using  namespace std;

//s1和s2是否相等
bool isEqu(string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 == len2)
	{
		for (int i = 0; i < len1; i++)
		{
			if (s1[i] > s2[i] || s1[i] < s2[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}
//s1是否大于s2
bool isBig(string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 > len2)
	{
		return true;
	}
	else if (len1 < len2)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < len1; i++)
		{
			if (s1[i] > s2[i])
			{
				return true;
			}
			else if (s1[i] < s2[i])
			{
				return false;
			}
			else
			{
				continue;
			}
		}
	}
}
//大数相减
string sub(string s1, string s2)
{
	string s3;
	int len1 = s1.length();
	int len2 = s2.length();
	for (int i = len2 - 1,j = len1 -1; i >=0 && j>=0; --i , --j)
	{
		if (s1[j] >= s2[i])
		{
			s3.push_back(s1[j] - s2[i] + '0');
		}
		else
		{
			s1[j - 1] -= 1;
			s3.push_back(s1[j] + 10 - s2[i] + '0');
		}
	}
	for (int j = len1 - len2 - 1; j >= 0; --j)
	{
		s3.push_back(s1[j]);
	}
	reverse(s3.begin(),s3.end());//反转
	int num = 0;
	for (int i = 0; i < s3.size(); i++)
	{
		if (s3[i] == '0')
		{
			num++;
		}
		else
		{
			s3.erase(0,num);//删除
			break;
		}
	}
	return s3;
}

string add(string s1, string s2)
{
	string s3;
	int len1 = s1.length();
	int len2 = s2.length();
	bool flag = false;
	int t = 0;
	int num;
	for (int i = len2 - 1, j = len1 - 1; i >= 0 && j >= 0; --i, --j)
	{
		if (flag)
		{
			num = s1[j] - '0' + s2[i] - '0' + t;
		}
		else
		{
			num = s1[j] - '0' + s2[i] - '0';
		}
		if (num < 10)
		{
			s3.push_back(num + '0');
			flag = false;
		}
		else
		{
			t = num / 10;
			flag = true;
			s3.push_back(num % 10 + '0');
		}
	}
	for (int j = len1 - len2 - 1; j >= 0; --j)
	{
		if (flag)
		{
			num = s1[j] - '0' + t;
			if (num < 10)
			{
				s3.push_back(num + '0');
				flag = false;
			}
			else
			{
				t = num / 10;
				flag = true;
				s3.push_back(num % 10 + '0');
			}
		}
		else
		{
			s3.push_back(s1[j]);
		}
	}
	if (flag)
	{
		s3.push_back(t + '0');
	}
	reverse(s3.begin(), s3.end());//反转
	return s3;
}
int main()
{
	int n;
	cin >> n;
	int t = 0;
	while (n--)
	{
		t++;
		string s1;
		string s2;
		cin >> s1 >> s2;
		cout << "Case " << t << ":" << endl;
		if (n != 0)
		{
			if (isBig(s1,s2))
			{
				cout << s1 << " + " << s2 << " = " << add(s1, s2) << endl << endl;
			}
			else
			{
				cout << s1 << " + " << s2 << " = " << add(s2, s1) << endl << endl;
			}
		}
		else
		{
			if (isBig(s1,s2))
			{
				cout << s1 << " + " << s2 << " = " << add(s1, s2) << endl;
			}
			else
			{
				cout << s1 << " + " << s2 << " = " << add(s2, s1) << endl;
			}
		}

	}
	system("pause");
	return 0;
}