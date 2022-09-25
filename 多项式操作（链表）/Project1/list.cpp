#include "list.h"

void InitLink(LinkNode*& list)
{
	list = new LinkNode;
	list->next = nullptr;
}

inline LinkNode* CreateLinkNode(const coefType& coef, const expType& exp)
{
	LinkNode* pNew = new LinkNode;
	pNew->coef = coef;
	pNew->exp = exp;
	pNew->next = nullptr;
	return pNew;
}

void CreateLink(LinkNode*& list)
{
	//整体创建单链
	int coef = 0, exp = 0, n = 0;
	cout << "请输入多项式的项数：";
	cin.clear(); 
	cin >> n;
	vector<coefType> a(n);
	vector<expType> b(n);
	cout << "请输入" << n << "项多项式各项的<系数>：";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "请输入" << n << "项多项式各项的<指数>：";
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	cin.clear();
	LinkNode* pNew = nullptr;
	LinkNode* pTail = list;
	for (int i = 0; i < n; ++i)
	{
		pNew = CreateLinkNode(a[i], b[i]);
		//链表尾插
		pTail->next = pNew;
		pTail = pNew;
	}
	sort(list);
}

bool IsGreater(LinkNode* list)
{
	LinkNode* pTemp = list->next, * pNext = nullptr;
	while (pTemp->next)
	{
		pNext = pTemp->next;
		if (pTemp->exp < pNext->exp)
		{
			return false;
		}
		pTemp = pTemp->next;
	}
	return true;
}

void sort(LinkNode*& list)
{
	if (!IsGreater(list))
	{
		//单链表递减排序
		if (list->next == nullptr)
		{
			cout << "链表为空!\n";
			return;
		}
		LinkNode* pCur = list->next->next, * pTemp = pCur, * pBegin = list;

		list->next->next = nullptr;
		while (pCur)
		{
			pTemp = pCur->next;
			pBegin = list;
			while (pBegin->next && pBegin->next->exp > pCur->exp)
			{
				pBegin = pBegin->next;
			}
			//头插
			pCur->next = pBegin->next;
			pBegin->next = pCur;
			pCur = pTemp;
		}
	}
}

void Merge(LinkNode* ha, LinkNode* hb, LinkNode*& list)
{
	LinkNode* pA = ha->next;
	LinkNode* pB = hb->next;
	
	InitLink(list);
	LinkNode* pList = list;
	LinkNode* pNew = nullptr;
	//二路归并
	while (pA && pB)
	{
		if (pA->exp < pB->exp)
		{
			pNew = CreateLinkNode(pB->coef, pB->exp);
			//尾插法连接
			pList->next = pNew;
			pList = pNew;
			pB = pB->next;
		}
		else if (pA->exp > pB->exp)
		{
			pNew = CreateLinkNode(pA->coef, pA->exp);
			//尾插法连接
			pList->next = pNew;
			pList = pNew;
			pA = pA->next;
		}
		else
		{
			//相等：多项式相加
			coefType coef = pA->coef + pB->coef;
			if (coef)
			{
				pNew = CreateLinkNode(coef, pA->exp);
				pList->next = pNew;
				pList = pNew;
			}
			pA = pA->next;
			pB = pB->next;
		}
	}
	if (pB)
	{
		pA = pB;
	}
	while (pA)
	{
		pNew = CreateLinkNode(pA->coef, pA->exp);
		pList->next = pNew;
		pList = pNew;
		pA = pA->next;
	}
}


void DestroyLink(LinkNode*& list)
{
	LinkNode* pTemp = nullptr,*pCur=list->next;
	while (pCur)
	{
		pTemp = pCur->next;
		delete pCur;
		pCur = pTemp;
	}
	delete pCur;
	pCur = nullptr;
}

void travel(LinkNode* list)
{
	LinkNode* pTravel = list->next;
	LinkNode* pTemp = nullptr;
	while (pTravel)
	{
		if (pTravel->next)
		{
			pTemp = pTravel->next;
		}
		//printf("(%.2lfx^%d)", pTravel->coef, pTravel->exp);
		cout << pTravel->coef << "x^" << pTravel->exp << ((pTravel->next == nullptr) ? "\n": ((pTemp->coef > 0) ? " + " : " "));
		pTravel = pTravel->next;
	}
	cout << endl;
}
