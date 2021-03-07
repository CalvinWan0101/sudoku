#include <iostream>
#include <algorithm>
using namespace std;
int map[9][9];
bool Test(int count)
{
	int y = count / 9;
	int x = count % 9;
	//同一行
	for (int i = 0; i < 9; ++i)
		if (map[y][i] == map[y][x] && i != x)
			return false;
	//同一列
	for (int i = 0; i < 9; ++i)
		if (map[i][x] == map[y][x] && i != y)
			return false;
	//同一小格
	int sy = y / 3 * 3;
	int sx = x / 3 * 3;
	for (int i = sy; i < sy + 3; ++i)
		for (int k = sx; k < sx + 3; ++k)
			if (map[i][k] == map[y][x] && i != y && k != x)
				return false;
	return true;
}
void guess(int count)
{
	if (count == 81)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << map[i][j] << " ";
			cout << endl;
		}
		return;
	}
	int y = count / 9;
	int x = count % 9;
	if (map[y][x] == 0)
	{
		for (int i = 1; i <= 9; ++i)
		{
			//給值標記已經使用過
			map[y][x] = i;
			if (Test(count))
				guess(count + 1);
		}
		//重置該點數值
		map[y][x] = 0;
	}
	else
		guess(count + 1);
}
int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> map[i][j];
	cout << endl;
	guess(0);
	return 0;
}
