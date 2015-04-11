#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cow{
    public:
	int top_five_total(int num, vector <int> cow_weight);
    private:
	int num;
	int weight;
	int total;
	vector <int> cow_weight;
};
