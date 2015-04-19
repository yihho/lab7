#include <iostream>
#include <vector>
using namespace std;

class Sudoku
{
    public:
        Sudoku();
        void GiveQuestion();
        void ReadIn();
        void Solve();
        static const int sudokuSize = 144;

    private:
        int map[sudokuSize];
	int R;
	bool checkUnity(int arr[]);
	bool checkCell(int arr[]);
	int Ans[sudokuSize];
	int getFirstZeroIndex();
	bool isCorrect();
	bool Solution();
	int A;
};
