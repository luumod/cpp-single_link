#include "rec.h"

int main()
{
	
	sqList list1;
	sqList list2;
	sqList list3;
	Init(list1);
	Init(list2);
	Init(list3);
	for (int i = 0; i < 10; i++)
	{
		push_back(list1, i);
	}
	for (int i = 5; i < 15; i++)
	{
		push_back(list2, i);
	}
	Element elem2,elem5,elem8;
	Find_Pos_Little_Elem(list1, list2,2,elem2);
	Find_Pos_Little_Elem(list1, list2, 5, elem5);
	Find_Pos_Little_Elem(list1, list2, 8, elem8);
	travel(list1);
	travel(list2);
	
	cout << "Ѱ�ҵ�2С��Ԫ��" << elem2 << endl;
	cout << "Ѱ�ҵ�5С��Ԫ��" << elem5 << endl;
	cout << "Ѱ�ҵ�8С��Ԫ��" << elem8 << endl;


	return 0;
}