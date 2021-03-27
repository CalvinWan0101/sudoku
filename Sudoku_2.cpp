#include <iostream>
using namespace std;
int map[10][10], y, x, sy, sx;
bool Test(int count)
{
    y = count / 9 + 1;
    x = count % 9;
    for (int i = 1; i <= 9; i++)
        if (map[i][x] == map[y][x] && i != y)
            return false;
    for (int i = 1; i <= 9; i++)
        if (map[y][i] == map[y][x] && i != x)
            return false;
    sy = (y - 1) / 3 * 3 + 1;
    sx = (x - 1) / 3 * 3 + 1;
    for (int i = sy; i < sy + 3; i++)
        for (int j = sx; j < sx + 3; j++)
            if (map[i][j] == map[y][x] && i != y && j != x)
                return false;
    return true;
}
void function(int count)
{
    if (count == 82)
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
                cout << map[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }
    y = count / 9 + 1;
    x = count % 9;
    if (x == 0)
        x = 9, y--;
    if (map[y][x] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            map[y][x] = i;
            if (Test(count))
                function(count + 1);
        }
        map[y][x] = 0;
    }
    else
        function(count + 1);
}
int main()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            cin >> map[i][j];
    cout << endl;
    function(1);
    return 0;
}