<iostream>
using namespace std;
int main(int argc, char** argv)
{
	char x;
	cout << "心理測驗" << endl;
	cout << "我可以猜到你最喜歡什麼字母哦" << endl;
	cout << "找一個你最喜歡的字母按下去然後不要告訴我" << endl;
	cin >> x;
	cout << "你很喜歡" << x << "對不對，好啦我就是職業算命師,不如我再幫你算一卦BMI?";
	cout << endl;
	cout << "請分別輸入你的身高體重並以空格為間隔，如身高1.8公尺體重60公斤則1.8 60" << endl;
	float high;
	float weight;
	cin >> high >> weight;
	double H = pow(high, 2);
	double BMI = weight / H;
	if (BMI >= 27)
	{
		cout << "你的BMI是" << BMI << endl;
		cout << "你好胖" << endl;
		cout << "你好胖" << endl;
		cout << "你好胖" << endl;
		cout << "你好胖" << endl;
		cout << "你好胖" << endl;
		cout << "你好胖" << endl;
		cout << "你好胖" << endl;
		cout << "你好胖" << endl;
		cout << "你好胖" << endl;
	}
	else if (BMI >= 24)
	{
		cout << "你的BMI是" << BMI << "繼續保持哦" << endl;
	}
	else { cout << "你的BMI是" << BMI << "去多吃一點啦，這樣會被風吹走" << endl; }
	cout << "有時候我都佩服為什麼自己可以算得那麼准啊" << endl;
	cout << "好啦既然我算得那麼准，客官可否給點小費呀" << endl;
	system("PAUSE");
	return 0;
}