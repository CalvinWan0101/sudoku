[彩色解題思路(含公式驗證)](https://github.com/CalvinWan0101/Sudoku/blob/master/Sudoku.pdf)

先建立一個全域的int陣列當做map

```c++
int sudoku[9][9]
```

然後建立一個用來檢測輸入的數字是否符合條件的函數

條件如下:

範圍|條件A|條件B
-|-|-
x相同的9個格子|格子內的數字互不相等|數字為1~9
y相同的9個格子|格子內的數字互不相等|數字為1~9
劃分在同一個小格子的9個格子|格子內的數字互不相等|數字為1~9

這邊的`count`是跑到第count格的意思,從第1格開始跑，到第80格結束,先計算當前count值下的坐標

```c++
int y = count / 9;
int x = count % 9;
```
檢查y相同的狀況，
```c++
	//垂直檢查
	for (int i = 0; i < 9; ++i)
		if (sudoku[i][x] == sudoku[y][x] && i != y)
			return false;
```
檢查x相同的狀況
```c++
//水平檢查
	for (int i = 0; i < 9; ++i)
		if (sudoku[y][i] == sudoku[y][x] && i != x)
			return false;
```
檢查同一小格的狀況
```c++
	//小格檢查
	//小格左上角那一格的x,y坐標為sx,sy
	int sy = y / 3 * 3;
	int sx = x / 3 * 3;
	for (int i = sy; i < sy + 3; ++i)
		for (int k = sx; k < sx + 3; ++k)
			if (sudoku[i][k] == sudoku[y][x] && i != y && k != x)
				return false;
```
當到達這邊就代表前面都沒有return也就是這個值是沒問題的,這時候就`return true;`

# 
完整的`Test`函數長這樣
```c++
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
```

然後是DFS的部分了,我把這個函數取名叫`guess`,第一步先判斷是不是走到終點了,也就是count的值是否為81
```c++
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
```
確定了現在走的點不是最後一個點之後,這裡一樣要計算count當下x,y的值
```c++
int y = count / 9;
int x = count % 9;
```
這時候分成兩種情況

情況|動作
-|-
當前位置沒有數字(map[y][x]==0)|開始在這一格做嘗試
當前位置已有數字(map[y][x]!=0)|直接呼叫下一層

這邊好像就比較有dfs的味道了，一個值試過之後當前格再重置為0繼續試下一個值。


當前位置沒有數字時:
```c++
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
```
當前位置有數字時：
```c++
else
  //直接進入下一層
  guess(count + 1);
```
整個`guess`函數長這樣：
```c++
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
```
最後一步就是main函數啦~就只有輸入map的值然後`guess(0)`(第一格數字為0)

### 注意這邊輸入格式空格以0代替
```c++
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
```
我是在圖書館把這一串給寫完的，寫完之後我就坐在那邊開外掛完了半小時數獨(剛好IG廣告就是數獨我嚇到)，QQ資安問題啊！！！

完整的程式碼：
```c++
#include <iostream>
using namespace std;
int sudoku[9][9];
//當count傳入時計算x,y
//並分別從垂直,水平,以及小格子內搜尋並判斷當前數字是否符合要求
//一旦發現不符合就return false
//如果都沒有發現就return true
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
```