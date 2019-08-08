#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string add(string s1, string s2,bool &flag)
{
	string s3;
	int len1 = s1.length();
	int len2 = s2.length();
	int num;
	for (int i = len2 - 1, j = len1 - 1; i >= 0 && j >= 0; --i, --j)
	{
		if (flag)
		{
			num = s1[j] - '0' + s2[i] - '0' + 1;
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
			flag = true;
			s3.push_back(num % 10 + '0');
		}
	}
	for (int j = len1 - len2 - 1; j >= 0; --j)
	{
		if (flag)
		{
			num = s1[j] - '0' + 1;
			if (num < 10)
			{
				s3.push_back(num + '0');
				flag = false;
			}
			else
			{
				flag = true;
				s3.push_back(num % 10 + '0');
			}
		}
		else
		{
			s3.push_back(s1[j]);
		}
	}
	reverse(s3.begin(), s3.end());//·´×ª
	return s3;
}
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

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		string s3, s4, s5, s6;
		int a1 = s1.find('.');
		int a2 = s2.find('.');
		if (a1 == -1)
		{
			 s5.assign(s1);
			 s4.assign(s2, a2 + 1,s2.length() - a2);
			 s6.assign(s2, 0, a2);
		}
		else if (a2 == -1)
		{
			 s6.assign(s2);
			 s3.assign(s1, a1 + 1,s1.length() - a1);
			 s5.assign(s1, 0, a1);
		}
		else
		{
			 s3.assign(s1, a1 + 1,s1.length() - a1);
			 s5.assign(s1, 0, a1);
			 s4.assign(s2, a2 + 1,s2.length() - a2);
			 s6.assign(s2, 0, a2);
		}
		bool flag = false;
		string s7, s8;
		if (isBig(s3, s4))
		{
			 s7 = add(s3, s4, flag);
		}
		else
		{
			 s7 = add(s4, s3, flag);
		}
		if (isBig(s5, s6))
		{
			s8 = add(s5, s6, flag);
		}
		else
		{
			s8 = add(s6, s5, flag);
		}
		int num = 0;
		string s9(s8 + '.' +  s7);
		for (int i = s9.length() - 1; i >= 0; --i)
		{
			if (s9[i] == '0')
			{
				num++;
			}
			else if (s9[i] == '.')
			{
				num++;
				break;
			}
			else
			{
				break;
			}
		}
		s9.erase(s9.length() - num);
		cout << s9 << endl;
	}
	system("pause");
	return 0;
}