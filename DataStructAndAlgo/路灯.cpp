////2
////3
////.X.
////11
////...XX....XX
#include <iostream>
using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n;
//	char str[1010];
//	while (n--)
//	{
//		int num = 0;
//		cin >> m;
//		for (int i = 0; i < m; i++)
//		{
//			cin >> str[i];
//		}
//		for (int j = 0; j < m;)
//		{
//			if (str[j] == '.')
//			{
//				num++;
//				j += 3;
//			}
//			else
//			{
//				j++;
//			}
//		}
//	/*	int k;
//		for (k = 0; k + 2 < m;)
//		{
//			if (str[k] == '.' || str[k + 1] == '.' || str[k + 2] == '.')
//			{
//				num++;
//			}
//			k += 3;
//		}
//		if (k < m)
//		{
//			for (; k < m; k++)
//			{
//				if (str[k] == '.')
//				{
//					num++;
//					break;
//				}
//			}
//		}*/
//		cout << num << endl;
//	}
//	system("pause");
//	return 0;
//}

int FindSubString(char* pch)
{
	int   count = 0;
	char  * p1 = pch;
	while (*p1 != '\0')
	{
		if (*p1 == (p1[1] - 1))
		{
			p1++;
			count++;
		}
		else  {
			break;
		}
	}
	int count2 = count;
	while (*p1 != '\0')
	{
		if (*p1 == (p1[1] + 1))
		{
			p1++;
			count2--;
		}
		else  {
			break;
		}
	}
	if (count2 == 0)
		return(count);
	return(0);
}
void ModifyString(char* pText)
{
	char  * p1 = pText;
	char  * p2 = p1;
	while (*p1 != '\0')
	{
		int count = FindSubString(p1);
		if (count > 0)
		{
			*p2++ = *p1;
			printf_s(p2, "%c", count);
			while (*p2 != '\0')
			{
				p2++;
			}
			p1 += count + count + 1;
		}
		else  {
			*p2++ = *p1++;
		}
	}
}
void main()

{
	int a = 7, b = 5;

	printf("%d\n", b = b / a);
	system("pause");

}