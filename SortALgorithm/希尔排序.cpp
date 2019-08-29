#include <iostream>
#include <vector>
using namespace std;

//ϣ������
//�ʱ�临�Ӷ�O(n(logn)^2)
//���ʱ�临�Ӷ�O(n)
//ƽ��ʱ�临�Ӷ�O(����)
//���踨���ռ�O(1)
//���ȶ�
void ShellSort(vector<int> &a)
{
	//����
	int k = 0;
	while (k * 2 + 1 < a.size())
	{
		k = k * 2 + 1;
	}
	while (k >= 1)
	{
		for (int i = k; i < a.size();i++)
		{
			int j = i - k;
			int temp = a[i];
			//��������
			while (j >= 0 &&temp < a[j])
			{
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = temp;
		}
		k = (k - 1) / 2;
	}
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
	ShellSort(a);
	cout << endl;
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}