#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	//cout的第一次練習
	cout << "窗前明月光，疑是地上霜。" << endl << "舉頭望明月，低頭思故鄉。" << endl;// 再加上<<endl 就可以再往下一行

		//cout+endl+（;）
	cout << "紅葉晚蕭蕭，長亭酒一瓢。" << endl;
	cout << "殘雲歸太華，疏雨過中條。" << endl;
	cout << "樹色隨關回，河聲入海遙。" << endl;
	cout << "帝鄉明日到，猶自夢錯字。" << endl;
	cout << endl;

	//cout+\n+（;）
	cout << "紅葉晚蕭蕭，長亭酒一瓢。\n";
	cout << "殘雲歸太華，疏雨過中條。\n";
	cout << "樹色隨關回，河聲入海遙。\n";
	cout << "帝鄉明日到，猶自夢錯字。\n";
	cout << endl;

	//cout + \n
	cout << "紅葉晚蕭蕭，長亭酒一瓢。\n"
		<< "殘雲歸太華，疏雨過中條。\n"
		<< "樹色隨關回，河聲入海遙。\n"
		<< "帝鄉明日到，猶自夢錯字。\n";
	cout << endl;

	//宣告一個變數然後我覺得很無聊所以我要把他改掉
	int boring = 10; //我這邊啊先表面宣告一下boring這個變數是10
	cout << "我一開始設的是=>" << boring;
	cout << endl;
	//IMPROANT!!!如果要寫變更值的話不能再設一個int，就直接【變數=你要的數字】就好了
	boring = 1000;//然後再偷偷把他的變數值改成1000（變更值）
	cout << "然後我偷偷把他修改完的是=>" << boring;
	cout << endl;


	system("pause");
	return 0;
}