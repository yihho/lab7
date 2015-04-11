#include <iostream>
#include <vector>
#include <algorithm>
#include "cow.h"

int Cow::top_five_total(int num, vector <int> cow_weight)
{
    while (num < 5 || num > 10000)
    {
	cout << "The number of cows is wrong!" << endl;
	break;
    }

    sort(cow_weight.begin(), cow_weight.end());
   
    total = 0; 
    for (int i = 1;i <= 5; i++)
	total += cow_weight[num - i];

    return total;
}
