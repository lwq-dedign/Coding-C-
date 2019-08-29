#include <iostream>
#include <vector>
using namespace std;

//��������
//�ʱ�临�Ӷ�O(n^2)
//���ʱ�临�Ӷ�O(nlogn)
//ƽ��ʱ�临�Ӷ�O(nlogn)
//���踨���ռ�O(>1)
//���ȶ�
int GetMidIndex(vector<int> &a, int m, int n)
{
	int temp = a[n];
	int t = m;
	while (m < n)
	{
		if (t == m)
		{
			if (a[t] < temp)
			{
				t++; m++;
			}
			else
			{
				a[n] = a[t];
				n--;
				t = n;
			}
		}
		else
		{
			if (a[t] > temp)
			{
				t--; n--;
			}
			else
			{
				a[m] = a[t];
				m++;
				t = m;
			}
		}
	}
	a[m] = temp;
	return m;
}
void FastSort(vector<int> &a,int m,int n)
{
	if (m >= n)
		return;
	int tai = GetMidIndex(a, m, n);
	FastSort(a, m, tai - 1);
	FastSort(a, tai + 1, n);
}

int main()
{
	vector<int> a;
	for (int i = 0; i<10; i++)
	{
		int b = rand() % 10;
		a.push_back(b);
	}
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	FastSort(a,0,9);
	cout << endl;
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}