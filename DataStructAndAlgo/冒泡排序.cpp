#include <iostream>
#include <vector>
#include <random>
using namespace std;

void BubSort(vector<int> &a)
{
	for (int i=0;i<a.size() - 1;i++)
	{
		for (int j =0;j < a.size() - 1 - i ;j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
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
	BubSort(a);
	cout << endl;
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	system("pause");
	return 0;
}