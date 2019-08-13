#include <iostream>
#include <string>
#include <vector>
using namespace std;

int nnext[1010];
string s1, s2;

void getnext(string s)
{
	//��ʼ���׶�
	nnext[0] = -1;
	nnext[1] = 0;
	int k = 0, j = 1;
	while (j < s.length() -1)
	{
		if (s[j] == s[k])//ǰ���ͺ����
		{
			k++;
			j++;
			nnext[j] = k;
		}
		else //ǰ���ͺ󴮲����
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
		//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]    
			//next[j]��Ϊj����Ӧ��nextֵ      
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
			s3.assign(s2,i,k + 1);//��iλ�ÿ�ʼ�������k+1����ĸ��ֵs3
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