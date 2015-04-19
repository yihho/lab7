#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"

Sudoku::Sudoku()
{
    for(int i = 1;i < sudokuSize;i++)
	map[sudokuSize] = 0;
}

void Sudoku::GiveQuestion()
{
    int Origin[sudokuSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1,
			      4, 5, 6, 7, 8, 9, 1, 2, 3, -1, -1, -1,
			      7, 8, 9, 1, 2, 3, 4, 5, 6, -1, -1, -1,
			      3, 1, 2, 6, 4, 5, -1, -1, -1, 9, 7, 8,
			      6, 4, 5, 9, 7, 8, -1, -1, -1, 3, 1, 2,
			      9, 7, 8, 3, 1, 2, -1, -1, -1, 6, 4, 5,
			      2, 3, 1, -1, -1, -1, 9, 7, 8, 4, 5, 6,
			      5, 6, 4, -1, -1, -1, 3, 1, 2, 7, 8, 9,
			      8, 9, 7, -1, -1, -1, 6, 4, 5, 1, 2, 3,
			      -1, -1, -1, 5, 6, 4, 8, 9, 7, 2, 3, 1,
			      -1, -1, -1, 8, 9, 7, 2, 3, 1, 5, 6, 4,
			      -1, -1, -1, 2, 3, 1, 5, 6, 4, 8, 9, 7};
    int Question[sudokuSize] = {0};
    int tmp[sudokuSize] = {0};

    for(int i = 0;i < sudokuSize;i++)
    {
        Question[i] = Origin[i];
        tmp[i] = Question[i];
    }
    
    srand(time(NULL));
    int R = rand()% 100 + 1;

    if(R % 2 == 0 || R % 3 == 0) //左右整排換
    {
	int a[36] = {0}, b[36] = {0}, c[36] = {0}, d[36] = {0};
	   
	for(int j = 0;j < 36;j++)
	{
	    a[j] = tmp[j];
	    b[j] = tmp[36 + j];
	    c[j] = tmp[72 + j];
	    d[j] = tmp[108 + j];
        }  
	
	if(R % 2 == 0)
	{
	    for(int j = 0;j < 36;j++)
	    {
	        Question[j] = b[j];
	        Question[36 + j] = c[j];
	        Question[72 + j] = d[j];
	        Question[108 + j] = a[j];
	    }
	}    
	
	if(R % 3 == 0)
	{
	    for(int j = 0;j < 36;j++)
	    {
	        Question[j] = b[j];
	        Question[36 + j] = d[j];
	        Question[72 + j] = c[j];
	        Question[108 + j] = a[j];
	    }
	}    
    }
    
    if(R % 5 == 0)
    {
	for(int i = 0;i < sudokuSize;i++)  //上下左右反轉
        { 
	    Question[i] = tmp[sudokuSize - 1 - i];
        }
    }  
    
    for(int i = 0;i < sudokuSize;i++)
        tmp[i] = Question[i];
    
    if(R % 7 == 0)
    {
        for(int i = 0;i < sudokuSize;i += 12)  //左右鏡射
        {
	    for(int j = 0;j < 12;j++)
	        Question[i + j] = tmp[i + 11 - j];
        }   
    }

    for(int i = 0;i < sudokuSize;i++)
        tmp[i] = Question[i];
    
    if(R % 11 == 0)
    {
        for(int i = 0;i < 12;i++)  //上下鏡射
        {
	    for(int j = 0;j < 12;j++)
	        Question[i * 12 + j] = tmp[12 * (11 - i) + j];
        }    
    }  

    for(int i = 0;i < sudokuSize;i++)
        tmp[i] = Question[i];
    
    int number[9] = {0}; //換數字
    for(int i = 1;i <= 9;i++)
    {
	int r = rand() % 9;
	if(number[r] == 0)
	{	
	    for(int j = 0;j < sudokuSize;j++)
	    {
	        if(tmp[j] == i)		  
		    Question[j] = r + 1;
		number[r]++;
	    }
	}
	else
	    i--;
    }

    for(int i = 0;i < 10;i++) //挖洞
    {
	int r = rand() % 144;
	if(Question[r] != 0)
	{
	    if(Question[r] != -1)
	        Question[r] = 0;
	}
	else
	    i--;
    }

    for(int i = 0;i < sudokuSize;i++)
    {
	cout << Question[i] << ' ';
	if(i % 12 == 11)
	    cout << endl;
    }
}

void Sudoku::ReadIn()
{
    for(int i = 0;i < sudokuSize;i++)
	cin >> map[i];
    cout << endl;
}

bool Sudoku::checkUnity(int arr[] )
{
    int arr_unity[9];

    for(int i = 0;i < 9;++i)
	arr_unity[i] = 0;

    for(int i = 0;i < 12;++i)
    {
        if(arr[i] != -1)
	    ++arr_unity[arr[i] - 1];
    }

    for(int i = 0;i < 9;++i)
    {    
	if(arr_unity[i] != 1)
	    return false;
    }
    return true;
}

bool Sudoku::checkCell(int arr[] )
{
    int arr_unity[9];

    for(int i = 0;i < 9;++i)
	arr_unity[i] = 0;

    for(int i = 0;i < 9;++i)
    {
        if(arr[i] == -1)
	    return true;
	else
	    ++arr_unity[arr[i] - 1];
    }

    for(int i = 0;i < 9;++i)
    {    
	if(arr_unity[i] != 1)
	    return false;
    }
    return true;
}

bool Sudoku::isCorrect()
{
    bool check_result;
    int check_arr[12];
    int location;

    for(int i = 0;i < 144;i = i + 12) //check rows
    {
	for(int j = 0;j < 12;++j)
	    check_arr[j] = map[i + j];	
	
	check_result = checkUnity(check_arr);
	if(check_result == false)
	   return false;
    }

    for( int i = 0;i < 12;++i) //check columns
    {
	for(int j = 0;j < 12;++j)
	    check_arr[j] = map[i + 12 * j];
	
	check_result = checkUnity(check_arr);
	if(check_result == false)
	    return false;
    }

    for(int i = 0;i < 12;++i) //check cells
    {
	for(int j = 0;j < 9;j++)
	{	
	    location = 36 * (i / 4) + 3 * (i % 4) + 12 * (j / 3) + (j % 3);
            check_arr[j] = map[location];
	}
        check_result = checkCell(check_arr);
	if(check_result == false)  
	    return false;
    }
    return true;
}

int Sudoku::getFirstZeroIndex()
{
    for(int i = 0;i < sudokuSize;++i)
    {
        if(map[i] == 0)
            return i;
    }
    return -1;
}

bool Sudoku::Solution()
{
    int firstZero;
    firstZero = getFirstZeroIndex();
    if(firstZero == -1)
    {
	if(isCorrect() == true)
	    return true;
	else
	    return false;
    }
    else
    {
	for(int n = 1;n <= 9;++n)
	{
	    map[firstZero] = n;
	    if(Solution())
		return true;
	}
	return false;
   }
}

void Sudoku::Solve()
{
    if(Solution())
    {
	cout << "1" << endl;
	for(int i = 0;i < sudokuSize;i++)
	{
	    Ans[i] = map[i];
	    cout << Ans[i] << " ";
	    if(i % 12 == 11)
		cout << endl;
	}
    }
    else
        cout << "0" << endl;
}













