#pragma once
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
coef：多项式系数
exp： 多项式指数
*/
 
typedef double coefType;
typedef int expType;

typedef struct node
{
	coefType coef;
	expType exp;
	struct node* next;
}LinkNode;


//初始化单链表
void InitLink(LinkNode*& list);

//创建链表节点
inline LinkNode* CreateLinkNode(const coefType& coef, const expType& exp);

//整体创建单链表
void CreateLink(LinkNode*& list);

//判断单链表是否递减有序
bool IsGreater(LinkNode* list);

//单链表排序
void sort(LinkNode*& list);

//多项式相加
void Merge(LinkNode* ha,LinkNode* hb,LinkNode*& list);

//销毁单链表
void DestroyLink(LinkNode*& list);

//遍历单链表
void travel(LinkNode* list);