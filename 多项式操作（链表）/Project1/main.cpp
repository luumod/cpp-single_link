#include "list.h"

int main()
{
	LinkNode* list1;
	LinkNode* list2;
	LinkNode* listDst;

	InitLink(list1);
	InitLink(list2);

	CreateLink(list1);


	CreateLink(list2);

	Merge(list1, list2, listDst);

	travel(list1);
	travel(list2);
	travel(listDst);

	DestroyLink(list1);
	DestroyLink(list2);
	DestroyLink(listDst);

	return 0;
}