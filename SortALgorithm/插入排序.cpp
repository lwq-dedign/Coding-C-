#include <iostream>
#include <vector>
using namespace std;

//插入排序
//最坏时间复杂度O(n^2)
//最好时间复杂度O(n)
//平均时间复杂度O(n^2)
//所需辅助空间O(1)
//稳定
void InsertSort(vector<int> &a)
{
	for (int i = 1; i < a.size(); i++)
	{
		int temp = a[i];
		int j = i - 1;
		for ( ;j >= 0 && a[j] > temp;)
		{
				a[j + 1] = a[j];
				--j;
		}
		a[j + 1] = temp;
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
	InsertSort(a);
	cout << endl;
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	system("pause");
	return 0;
}