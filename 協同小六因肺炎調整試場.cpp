//前情提要
/*
在疫情爆發前，協同中學就已經公佈小六新生測驗的准考證號碼
准考證號碼為4碼
如1233則代表 12號考場 座號33
如0132則代表   1號考場 座號32
原本一間考場安排36人，但由於疫情的緣故，一間考場只能安排24人
但是准考證號碼已經公佈
如何依靠輸入准考證號碼以得知新的考場以及座號？
*/
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	cout << "請輸入您的准考證號碼" << endl;
	int id;
	int oldroom;
	int oldnum;
	int act;
	int newroom;
	int newnumber;
	cin >> id;
	oldroom = id / 100;
	oldnum = id - oldroom * 100;
	act = oldroom * 36 + oldnum;
	newroom = act / 24;
	newnumber = act % 24;
	cout << "您的試場為" << newroom << "號試場，您的座號為" << newnumber << "號" << endl;
	system("PAUSE");
	return 0;
}