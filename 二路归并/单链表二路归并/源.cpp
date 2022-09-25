#include "list.h"
 
int main()
{
	sqListNode* list1;
	sqListNode* list2;
	sqListNode* list3;
	InitList(list1);
	InitList(list2);
	InitList(list3);


	for (int i = 0; i < 10; ++i)
	{
		push_back(list1, i);
	}
	for (int i = 5; i < 15; ++i)
	{
		push_back(list2, i);
	}
	Merge_But_Destroy(list1, list2,list3);
	travel(list1);
	travel(list2);
	travel(list3);

	DestroyList(list1);
	DestroyList(list2);
	DestroyList(list3);
	return 0;
}
