#include "mlist.h"
#include <iostream>
using namespace std;
using namespace lxh;
int main()
{
	list<int> l1;

	list<int>::iterator fi;
	fi = l1.begin();
	//l1.erase(++fi);
	

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.erase(l1.begin(), l1.end());
	for (auto &i : l1)
	{
		cout << i << ' ';
	}
	cout << endl;
	//cout << *(l1.end());
	for (fi=l1.begin();fi != l1.end();++fi)
	{
		cout << *fi << ' ';
	}
	system("pause");

	return 0;
}