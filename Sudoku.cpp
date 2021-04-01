#include <iostream>
using namespace std;
int sudoku[9][9];
bool Test(int count)
{

	int y = count / 9;
	int x = count % 9;
	//水平檢查
	for (int i = 0; i < 9; ++i)
		if (sudoku[y][i] == sudoku[y][x] && i != x)
			return false;
	//垂直檢查
	for (int i = 0; i < 9; ++i)
		if (sudoku[i][x] == sudoku[y][x] && i != y)
			return false;
	//小格檢查
	//小格左上角那一格的x,y坐標為sx,sy
	int sy = y / 3 * 3;
	int sx = x / 3 * 3;
	for (int i = sy; i < sy + 3; ++i)
		for (int k = sx; k < sx + 3; ++k)
			if (sudoku[i][k] == sudoku[y][x] && i != y && k != x)
				return false;
	//default
	return true;
}
//count是格子的編號,從左上角開始左往右數,0號到80號
void guess(int count)
{
	//因為格子最後一號只有到80,當count==81時表示已經把一個答案跑出來了
	//此刻直接印出
	if (count == 81)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << sudoku[i][j] << " ";
			cout << endl;
		}
		return;
	}
	int y = count / 9;
	int x = count % 9;
	if (sudoku[y][x] == 0)
	{
		for (int i = 1; i <= 9; ++i)
		{
			//給這一格一個值,同時該格非0表示該格已經使用過了
			sudoku[y][x] = i;
			//測試這個值放在這一格是不是符合要求(丟進Test函數進行測試)
			if (Test(count))
			//通過的話就進入下一格
				guess(count + 1);
		}
		//9個數字都嘗試完了可是不符合
		//重置該點數值為0讓他回到上一層
		sudoku[y][x] = 0;
	}
	//這一格有數字
	else
		guess(count + 1);
}
int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> sudoku[i][j];
	cout << endl;
	//第一格是0號，count代0進入開始跑
	guess(0);
	system("PAUSE");
	return 0;
}
