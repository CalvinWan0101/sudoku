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
	//p=准考證號碼
	int p;
	//oldroom=舊考場編號,oldnum=舊座號
	int oldroom, oldnum;
	//newroom=新考場編號,newroom=新座號
	int newroom, newnum;
	//該學生為第【act】名學生
	int act;
	int i = 0;
	while (i > -1)
	{
		i++;
		cout << endl;
		cout << "您為第" << i << "位使用者" << endl;
		cout << "請輸入您的四位准考證號碼" << endl;
		cin >> p;
		oldroom = p / 100;
		oldnum = p % 100;
		act = (oldroom - 1) * 36 + oldnum;
		newnum = act % 24;
		//末二碼超過36
		if (oldnum > 36)
		{
			cout << "座號最高為36，請重新輸入您的准考證號碼" << endl;
		}
		else if (newnum==0)
		{
			oldroom = p / 100;
			oldnum = p % 100;
			act = (oldroom - 1) * 36 + oldnum;
			newroom = act / 24;
			cout << "您的准考證號碼為" << p << endl;
			cout << "您的新考場號碼為" << newroom << "號" << endl;
			cout << "您的新座號為24號" << endl;
		}
		//輸入超過4位數
		else if (p > 9999)
		{
			cout << "准考證號碼為4位，請重新輸入您的准考證號碼" << endl;
		}
		//100<p<9999正常範圍
		else if (p >= 999)
		{
			oldroom = p / 100;
			oldnum = p % 100;
			act = (oldroom-1) * 36 + oldnum;
			newroom = act / 24+1;
			newnum = act % 24;
			cout << "您的准考證號碼為" << p << endl;
			cout << "您的新考場號碼為" << newroom << "號" << endl;
			cout << "您的新座號為" << newnum << "號" << endl;
		}
		//3碼的計算方式和4碼相同
		else if (p >= 101)
		{
			oldroom = p / 100;
			oldnum = p % 100;
			act = (oldroom - 1) * 36 + oldnum;
			newroom = act / 24 + 1;
			newnum = act % 24;
			cout << "您的准考證號碼為" << p << endl;
			cout << "您的新考場號碼為" << newroom << "號" << endl;
			cout << "您的新座號為" << newnum << "號" << endl;
		}
		//輸入之號碼不足3位數（至少三位，如0101為最小者）
		else if (p > 0)
		{
			cout << "准考證號碼為4位，請重新輸入您的准考證號碼" << endl;
		}
		//輸入非數字的狀況
		else if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "請不要輸入准考證號碼以外的字元" << endl;
			continue;
		}
		//輸入的為負數
		else
		{
			cout << "准考證號碼為4位正整數，請輸入正確號碼" << endl;
		}
	}
	system("PAUSE");
	return 0;
}
