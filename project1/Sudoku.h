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
	int ANS[sudokuSize];
	int ans[sudokuSize];
	bool isCorrect(int arr[]);
	bool check(int arr[], int, int);
	void DFS(int);
	void dfs(int);
	bool SIGN;
	bool sign;
};
