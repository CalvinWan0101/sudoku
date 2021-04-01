#include <iostream>
using namespace std;
int main()
{
	int x, y;
	//nextl 是拿來換行的
	int nextl = 1;
	for (int i = 0; i <= 80; i++)
	{
		x = i % 9;
		y = i / 9;
		cout << "(" << y << "," << x << ")  ";
		nextl++;
		if (nextl == 10)
		{
			nextl = 1;
			cout << endl;
		}
	}
	int sx, sy;
	cout << endl;
	for (int i = 0; i <= 80; i++)
	{
		x = i % 9;
		y = i / 9;
		sx = (x / 3) * 3;
		sy = (y / 3) * 3;
		cout << "(" << sy << "," << sx << ")  ";
		nextl++;
		if (nextl == 10)
		{
			nextl = 1;
			cout << endl;
		}
	}
	system("PAUSE");
	return 0;
}
