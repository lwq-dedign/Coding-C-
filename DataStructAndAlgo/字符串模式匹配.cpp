#include <iostream>
#include <string>
#include <vector>
using namespace std;

int nnext[1010];
string s1, s2;

void getnext(string s)
{
	//初始化阶段
	nnext[0] = -1;
	nnext[1] = 0;
	int k = 0, j = 1;
	while (j < s.length() -1)
	{
		if (s[j] == s[k])//前串和后串相等
		{
			k++;
			j++;
			nnext[j] = k;
		}
		else //前串和后串不相等
		{
			if (k == 0)
			{
				j++;
				nnext[j] = k;
			}
			else
			{
				k = nnext[k];
			}
		}
	}
}
bool KmpSearch(string s, string p)
{
	int i = 0;
	int j = 0;
	int sLen = s.length();
	int pLen = p.length();
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
			//next[j]即为j所对应的next值      
			j = nnext[j];
		}
	}
	if (j == pLen)
		return true;
	else
		return false;
}

int main()
{
	cin >> s1 >> s2;
	int len1;
	int len2 = 0;
	string s5;
	for (int i = 0; i < s2.length(); i++)
	{
		string s3;
		len1 = 0;
		string s4;
		for (int k = 0; k < s2.length();)
		{
			s3.assign(s2,i,k + 1);//从i位置开始，后面的k+1个字母赋值s3
			getnext(s3);
			if (KmpSearch(s1, s3))
			{
				len1++;
				k++;
			}
			else
			{
				if (len1 > len2)
				{
					len2 = len1;
					s4.assign(s3,0,s3.length() -1);
					s5 = s4;
				}
				break;
			}
		}
	}
	cout << s5 << endl;
	system("pause");
	return 0;
}