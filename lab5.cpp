#include "lab5.h"
#include <vector>
#include <algorithm>
using namespace std;

ostream & operator <<(ostream &out, const HugeInt &a)
{
    out << a.num;
    return out;
}

istream &operator >> (istream & in, HugeInt & a)
{
    int N;
    vector <int> tmp;
    while(in >> N)
	tmp.push_back(N);
    a.num = reverse(N.begin(), N.end());
    return in;
}

HugeInt HugeInt::operator +(const HigeInt &a)
{
    result = num + a.num;
    int i = 0;
    while(i < result.size)
    {
	if(result.at(i) > 10)
	{
	    result.at(i) = result(i) - 10;
	    result.at(i + 1)++;
	}
	i++;
    }
}

};

