//AC
#include <iostream>
#include <vector>
using namespace std;

void fun(int n, int m, int k)
{
	vector<char> v;
	while (n&&m)
	{
		int count = 1;
		for (int i = 0; i < n - 1; i++)
		{
			count *= n - 1 + m - i;
			count /= i + 1;
			if (count > k)
				break;
		}
		if (count >= k)
		{
			n--;
			v.push_back('a');
		}
		else
		{
			m--;
			k -= count;
			v.push_back('z');
		}
	}
	/*if (k != 0)
	{
		cout << -1;
		return;
	}*/

	while (n--)
	{
		v.push_back('a');
	}
	while (m--)
	{
		v.push_back('z');
	}
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	long long  count = 1;
	for (int i = 0; i < n; i++)
	{
		count *= (n + m - i);
		count /= (i + 1);
	}
	if (k > count)
	{
		cout << -1;
	}
	else
	{
		fun(n, m, k);
	}
	system("pause");
	return 0;
}

////
//////int File::copy_file(const char* srcPath, const char* desPath)
//////{
//////	FILE *srcFile, *desFile;
//////
//////	wchar_t wbuf[1024];
//////	MultiByteToWideChar(CP_UTF8, 0, desPath, -1, wbuf, sizeof(wbuf) / sizeof(wbuf[0]));
//////	wbuf[sizeof(wbuf) / sizeof(wbuf[0]) - 1] = '\0';
//////
//////	wchar_t rbuf[1024];
//////	MultiByteToWideChar(CP_UTF8, 0, srcPath, -1, rbuf, sizeof(rbuf) / sizeof(rbuf[0]));
//////	rbuf[sizeof(rbuf) / sizeof(rbuf[0]) - 1] = '\0';
//////
//////	if ((srcFile = _wfopen(rbuf, L"r")) == NULL || (desFile = _wfopen(wbuf, L"w")) == NULL)
//////	{
//////		Log::message("open file error %s", srcPath);
//////		return 0;
//////	}
//////	int ch = fgetc(srcFile);
//////	while (ch != EOF)
//////	{
//////		fputc(ch, desFile);
//////		ch = fgetc(srcFile);
//////	}
//////	fclose(srcFile);
//////	fclose(desFile);
//////	return 1;
//////}