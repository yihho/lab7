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
        static const int sudokuSize = 81;

    private:
        int map[sudokuSize];
        int Origin[sudokuSize];
	int Question[sudokuSize];
	int R;
	bool checkUnity(int arr[]);
	int Ans[sudokuSize];
	void setElement(int index,int value);
	int getFirstZeroIndex();
	bool isCorrect();
	int Solution();
};
