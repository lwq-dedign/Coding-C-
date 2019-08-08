#include <iostream>
#include <vector>
using namespace std;


void SelectSort(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		int temp = a[i];
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
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
	SelectSort(a);
	cout << endl;
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	system("pause");
	return 0;
}