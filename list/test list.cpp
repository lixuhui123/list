#include <iostream>
#include <list>
using namespace std;
/* list�ĵײ�Դ��ʵ����˫������ */
int main()
{
	 list<int> l1; // ����յ�l1
	 list<int> l2(4, 100); // l2�з�4��ֵΪ100��Ԫ��
	 list<int> l3(l2.begin(), l2.end()); // ��l2��[begin(), end()������ҿ������乹��l3��endλ�ò�Ҫ
	 list<int> l4(l3); // ��l3��������l4
	// ������Ϊ���������乹��l5
	int array[] = { 16,2,77,29 };
	 list<int> l5(array, array + sizeof(array) / sizeof(int));
	// �õ�������ʽ��ӡl5�е�Ԫ��
	 list<int>::iterator it;
	for ( it = l5.begin(); it != l5.end(); it++)
		 cout << *it << " ";
	 cout << endl;

	// C++11��Χfor�ķ�ʽ����
	for (auto& e : l4)
		 cout << e << " ";

	 cout << endl;
	system("pause"); 
	return 0;
}