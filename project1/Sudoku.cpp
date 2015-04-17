#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
    for(int i = 1;i < sudokuSize;i++)
	map[sudokuSize] = 0;
}

void Sudoku::GiveQuestion()
{
    int Origin[sudokuSize] = {9, 0, 0, 3, 0, 0, 5, 8, 0,
			      1, 4, 3, 5, 0, 0, 0, 6, 2,
			      0, 2, 0, 0, 4, 0, 1, 3, 7,
			      7, 8, 1, 4, 9, 3, 0, 2, 0,
			      5, 0, 0, 1, 6, 8, 0, 0, 3,
			      0, 3, 0, 2, 7, 5, 8, 1, 9, 
			      4, 5, 8, 0, 2, 0, 0, 9, 0,
			      3, 1, 0, 0, 0, 4, 2, 7, 8,
			      0, 7, 6, 0, 0, 9, 0, 0, 1};


//    int Origin[sudokuSize] = { 4, 2, 6, 8, 7, 3, 9, 5, 1,-1,-1,-1,
//		 	       0, 0, 3, 9, 5, 0, 6, 0, 4,-1,-1,-1,
//			       9, 0, 1, 6, 2, 4, 8, 0, 0,-1,-1,-1,
//			      -1,-1,-1, 1, 3, 2, 0, 8, 7, 9, 5, 6, 
//	  		      -1,-1,-1, 0, 8, 0, 1, 9, 0, 4, 2, 0,
//			      -1,-1,-1, 4, 9, 6, 2, 3, 0, 8, 7, 1,
//			       1, 0, 0, 0, 4, 0,-1,-1,-1, 6, 9, 5,
//			       0, 0, 4, 0, 6, 0,-1,-1,-1, 1, 3, 7,
//			       6, 9, 5, 0, 1, 7,-1,-1,-1, 2, 8, 4,
//			       3, 1, 2,-1,-1,-1, 7, 4, 0, 5, 0, 9,
//			       7, 4, 8,-1,-1,-1, 0, 6, 9, 3, 0, 2,
//			       0, 6, 0,-1,-1,-1, 3, 1, 0, 7, 0, 8};
    //srand(time(0));
    //R = rand()% 10;
    //if(R = 1)
    //{
    //    Question[sudokusize] = {};
    //}
    
    for(int i = 0;i < sudokuSize;i++)
    {
	cout << Origin[i] << ' ';
	if(i % 9 == 8)
	    cout << endl;
    }
}

void Sudoku::ReadIn()
{
    for(int i = 0;i < sudokuSize;i++)
	cin >> map[i];
    cout << endl;
    for(int i = 0;i < sudokuSize;i++)
    {
	cout << map[i] << ' ';
	if(i % 9 == 8)
	    cout << endl;
    }
}

bool Sudoku::checkUnity(int arr[] )
{
    int arr_unity[9];

    for(int i = 0;i < 9;++i)
	arr_unity[i] = 0;

    for(int i = 0;i < 9;++i)
	++arr_unity[arr[i] - 1];

    for(int i = 0;i < 9;++i)
    {
	if(arr_unity[i] != 1)
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
    return -2;
}

bool Sudoku::isCorrect()
{
    bool check_result;
    int check_arr[9];
    int location;

    for(int i = 0;i < 81;i += 9) //check rows
    {
	for(int j = 0;j < 9;++j)
	    check_arr[j] = map[i + j];
	
	check_result = checkUnity(check_arr);
	
	if(check_result == false)
	    return false;
    }

    for( int i = 0;i < 9;++i) //check columns
    {
	for(int j = 0;j < 9;++j)
	    check_arr[j] = map[i + 9 * j];
	  
	check_result = checkUnity(check_arr);

	if(check_result == false)
  	    return false;
    }

    for(int i = 0;i < 9;++i) //check cells
    {
	for(int j = 0;j < 9;j++)
	{	
	    location = 27*(i / 3) + 3 * (i % 3) + 9 * (j / 3) + (j % 3);
            check_arr[j] = map[location];
	}	

        check_result = checkUnity(check_arr);

        if(check_result == false)
	    return false;
    }
    return true;
}

int Sudoku::Solution()
{
    int firstZero;
    firstZero = getFirstZeroIndex();

    if(firstZero == -2)
    { 
	if(isCorrect())
	    return 1;
	else
	    return 0;
    }
    else
    {
	for(int n = 1;n <= 9;++n)
	{
	    map[firstZero] = n;
	    if(Solution() == 1)
		return 1;
	}
	return -1;
    }
}

void Sudoku::Solve()
{
    if(Solution() == 1)
    {
	cout << "1" << endl << "ans=" << endl;
	for(int i = 0;i < sudokuSize;i++)
	{
	    Ans[i] = map[i];
	    cout << Ans[i] << " ";
	    if(i % 9 == 8)
		cout << endl;
	}
    }
    else
        cout << "can't solve" << ' ' << Solution() <<endl;
}

