+++
author = "Calvin"
title = "SUDOKU WITH C++"
date = "2020-06-28"
description = "使用 C++ 解決數獨問題"
tags = ["Algorithm","Code"]
categories = ["演算法","程式"]
aliases = ["migrate-from-jekyl"]
images  = ["img/photo/p4.jpg"]
+++

ㅤㅤ

## 前情提要

有一天我去看了上清大資工同學的備審

獎項跟參賽記錄多到哭出來啊，是完全無法觸及的級別

但是他有提到他有用Excel寫一個2*2的數獨

剛好我最近在讀關於dfs的東西，想說不然來玩玩看

邏輯應該差不多，就是比較不那麼暴力的窮舉

### 正式開始
先建立一個全域的int陣列當做map

`int map[9][9]`

然後建立一個用來檢測輸入的數字是否符合條件的函數

條件如下:

範圍|條件A|條件B
-|-|-
x相同的9個格子|格子內的數字互不相等|數字為1~9
y相同的9個格子|格子內的數字互不相等|數字為1~9
劃分在同一個小格子的9個格子|格子內的數字互不相等|數字為1~9

這邊的`count`是跑到第count格的意思

從第1格開始跑，到第(9*9)格結束

先計算當前count值下的坐標

```c++
int y = count / 9;
int x = count % 9;
```
檢查y相同的狀況，
```c++
for (int i = 0; i < 9; ++i)
	//當發現y相同時有點的值和代入的值相同時就return false
    if (map[y][i] == map[y][x] && i != x)
		return false;
```
檢查x相同的狀況
```c++
for (int i = 0; i < 9; ++i)
//當發現x相同時有點的值和代入的值相同時就return false
	if (map[i][x] == map[y][x] && i != y)
		return false;
```
檢查同一小格的狀況
```c++
//sx,sy指小格子的坐標
//x,y的範圍是0~8,至於公式可以自己拿紙筆推推看
int sy = y / 3 * 3;
int sx = x / 3 * 3;
for (int i = sy; i < sy + 3; ++i)
	for (int k = sx; k < sx + 3; ++k)
		if (map[i][k] == map[y][x] && i != y && k != x)
			return false;
```
當到了這邊就代表前面都沒有return也就是這個值是沒問題的

這時候就`return true;`

# 
完整的`Test`函數長這樣
```c++
bool Test(int count)
{
	int y = count / 9;
	int x = count % 9;
	//y相同
	for (int i = 0; i < 9; ++i)
		if (map[y][i] == map[y][x] && i != x)
			return false;
	//x相同
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
```

然後是BackTracking的部分了(我這樣玩好像有dfs的味道，但我不確定是不是dfs)

我把這個函數取名叫`guess`

第一步先判斷是不是走到終點了

也就是count的值是否為81
```c++
if (count == 81)
	//如果是81就把map整個印出來再return
    {
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << map[i][j] << " ";
			cout << endl;
		}
		return;
	}
```
確定了現在走的點不是最後一個點之後

這裡一樣要計算count當下x,y的值
```c++
int y = count / 9;
int x = count % 9;
```
這時候分成兩種情況

情況|動作
-|-
當前位置沒有數字(map[y][x]==0)|開始在這一格做嘗試
當前位置已有數字(map[y][x]!=0)|直接呼叫下一層

這邊好像就比較有dfs的味道了

一個值試過之後當前格再重置為0繼續試下一個值

當前位置沒有數字時:
```c++
if (map[y][x] == 0)
	{
		for (int i = 1; i <= 9; ++i)
		{
			//給值標記已經使用過
			map[y][x] = i;
			//當檢測合格的時候就再進到下一層
            if (Test(count))
				guess(count + 1);
		}
		//重置該點數值
		map[y][x] = 0;
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
```
最後一步就是main函數啦~

就只有輸入map的值然後guess(0)

### 注意這邊輸入格式空格以0代替
```c++
int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> map[i][j];
	cout << endl;
	guess(0);
	return 0;
}
```
我是在圖書館把這一串給寫完的

寫完之後我就坐在那邊開外掛完了半小時數獨(剛好IG廣告就是數獨我嚇到)

完整的程式碼：
```c++
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
```