#include <iostream>
#include <list>
using namespace std;
/* list的底层源码实现是双向链表 */
int main()
{
	 list<int> l1; // 构造空的l1
	 list<int> l2(4, 100); // l2中放4个值为100的元素
	 list<int> l3(l2.begin(), l2.end()); // 用l2的[begin(), end()）左闭右开的区间构造l3，end位置不要
	 list<int> l4(l3); // 用l3拷贝构造l4
	// 以数组为迭代器区间构造l5
	int array[] = { 16,2,77,29 };
	 list<int> l5(array, array + sizeof(array) / sizeof(int));
	// 用迭代器方式打印l5中的元素
	 list<int>::iterator it;
	for ( it = l5.begin(); it != l5.end(); it++)
		 cout << *it << " ";
	 cout << endl;

	// C++11范围for的方式遍历
	for (auto& e : l4)
		 cout << e << " ";

	 cout << endl;
	system("pause"); 
	return 0;
}