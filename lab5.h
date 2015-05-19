#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
#include <vector>
using namespace std;

class HugeInt {
    friend ostream &operator << (ostream &, const HugeIntr&);
    friend istream &operator >> (istream &, HugeInt &);

    public:
	HugeInt operator + (const HugeInt &)
	HugeInt operator - (const HugeInt &)

    private:
	vector <int> num;
};

#endif
