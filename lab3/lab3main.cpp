#include <iostream>
#include <fstream>
#include "cow.h"
using namespace std;

int main(){

    fstream file;
    vector <int> cw;
    int w;
    Cow c;

    file.open("file.in", ios::in);
    if(!file){
        cerr << "Failed opening" << endl;
        exit(1);
    }   

    int n;
    file >> n;

    for(int i = 1;i <= n;i++)
    {
	while (file >> w)
            cw.push_back(w);
	//cout << cw[i-1] << endl;
    }

    cout << c.top_five_total(n, cw) << endl; 
}
