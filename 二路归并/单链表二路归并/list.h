#pragma once
#include <iostream>
using namespace std;

enum Type{head,back};
enum Sort{less,greater};

typedef int Element;

typedef struct Node
{
    Element data;
    struct Node* Next;
}sqListNode;

//初始化链表
void InitList(sqListNode*& list);

//创建链表节点
inline 
sqListNode* CreateNode(Element elem);

//销毁链表
void DestroyList(sqListNode*& list);

//遍历链表
void travel(sqListNode* list);

//求链表的长度
int GetListLength(sqListNode* list);

//快速创建链表  1:头插法  -1:尾插法
void Array_MakeList(sqListNode*& list,int* arr,int n,Type type=back);

//到达尾部节点
sqListNode* ArriveListTail(sqListNode* list);

//判断链表是否为空
inline
bool IsEmpty(sqListNode* list);

//头插法
void push_head(sqListNode*& list,Element elem);

//尾插法
void push_back(sqListNode*& list,Element elem);

//任意位置插入
void Insert(sqListNode*& list,Element elem,int pos);

//头部删除
void pop_head(sqListNode*& list);

//尾部删除
void pop_back(sqListNode*& list);

//任意位置删除
void Delete(sqListNode*& list,int pos);


/*
单链表高效设计
*/

//用一趟扫描确定单链表中第一个元素最大的节点
sqListNode* GetMaxNode(sqListNode* list);

//用一趟扫描确定单链表中第一个元素最大的节点的前驱节点
sqListNode* GetMaxPreNode(sqListNode* list);

//删除第一个元素最大的节点
void Delete_Max(sqListNode*& list);

//单链表所有元素逆置
void Reverse(sqListNode*& list);

//将奇数移到偶数的前面
void pushOddToEvenNum(sqListNode*& list);

//有序单链表的二路归并: 两个递增链表合成一个递增链表，销毁原链表
void Merge_But_Destroy(sqListNode* list1,sqListNode* list2,sqListNode*& listDst);

//有序单链表的二路归并 两个链表合成一个有共同元素的有序递增链表，不会销毁原链表
void MergeComm_Not_Destroy(sqListNode* list1,sqListNode* list2,sqListNode*& Dst);

//单链表的排序  递减：less  递增：greater 
void SortList(sqListNode*& list,Sort type);



/*
作业
*/
//判断单链表是否是有序递增的
bool IsIncrease(sqListNode* list);

//拆分为两个链表,A链表偶数节点，B链表奇数节点
void SplitList(sqListNode*& listA,sqListNode*& listB);

//往递增有序链表中插入一个值为X的节点，链表仍然有序
void push_XNode(sqListNode*& list,Element elem);

//深度复制链表
void CopyList(sqListNode*& list_dst,sqListNode* list_src);