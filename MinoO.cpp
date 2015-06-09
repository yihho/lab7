#include "MinoO.h"
char O_arr [4][4] = {{'0','0','0','0'},
                     {'0','0','0','0'},
                     {'0','1','1','0'},
                     {'0','1','1','0'}};
MinoO::MinoO():Mino(0){}
void MinoO::paint()
{
    for(int i=0;i<4;++i)
    {
	for(int j=0;j<4;++j)
	    cout << O_arr[i][j];
	cout << endl;
    }
}
