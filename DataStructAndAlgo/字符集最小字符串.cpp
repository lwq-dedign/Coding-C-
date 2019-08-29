#include <iostream>
#include <string>
using namespace std;

bool IsAllCharFromSetAppear(bool* pIsCharAppear, int iSetSize)
{
	int i;
	for (i = 0; i < iSetSize; i++)
	{
		if (!pIsCharAppear[i])
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char* argv[])
{
	string strSource, strCharSet;
	cin >> strSource >> strCharSet;
	const int iStrSize = strSource.length();
	const int iSetSize = strCharSet.length();
	int iMinPos = -1; 
	int iCurMinLength = iStrSize;

	bool* pIsCharAppear = new bool[iSetSize];
	int i;
	for (i = 0; i < iSetSize; i++)
	{
		pIsCharAppear[i] = false;
	}
	int j, temp, iTempPos;
	for (i = 0; i < strSource.length(); i++)
	{
		if (strCharSet.find(strSource[i]) == string::npos)
		{
			continue;
		}
		temp = iCurMinLength < iStrSize - i ? iCurMinLength : iStrSize - i;
		for (j = 0; j < temp; j++)
		{
			iTempPos = strCharSet.find(strSource[i + j]);
			if (iTempPos == string::npos)
			{
				continue;
			}
			pIsCharAppear[iTempPos] = true;
			if (IsAllCharFromSetAppear(pIsCharAppear, iSetSize))
			{
				break;
			}
		}
		if (j < temp) 
		{
			if (j + 1 < iCurMinLength)
			{
				iCurMinLength = j + 1;
				iMinPos = i;
			}
		}

		for (j = 0; j < iSetSize; j++)
		{
			pIsCharAppear[j] = false;
		}
	}
	if (iMinPos == -1)
	{
		cout << "#" << endl;
	}
	else
	{
		cout  << strSource.substr(iMinPos, iCurMinLength) << endl;
	}
	system("pause");
	return 0;
}
