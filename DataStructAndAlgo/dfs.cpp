#include <iostream>
#include <vector>

using namespace std;

//邻接矩阵
int Map[5][5] = { 0 };
//是否遍历
int isvisible[5] = { 0 };
//结点数据
char MapData[5] = { 'A', 'B', 'C', 'D' ,'E'};
void dfs(int index)
{
	cout << MapData[index] << " ";
	isvisible[index] = 1;
	for (int i = 0; i < 5; i++)
	{
		if (Map[index][i])
		{
			if (isvisible[i])
			{
				continue;
			}
			else
			{
				dfs(i);
			}
		}
		else
		{
			continue;
		}
	}
}
int main()
{
	Map[0][1] = 1;
	Map[1][2] = 1;
	Map[2][4] = 1;
	Map[0][3] = 1;
	Map[1][0] = 1;
	Map[2][1] = 1;
	Map[4][2] = 1;
	Map[3][0] = 1;
	dfs(0);
	system("pause");
	return 0;
}