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

//��ʼ������
void InitList(sqListNode*& list);

//��������ڵ�
inline 
sqListNode* CreateNode(Element elem);

//��������
void DestroyList(sqListNode*& list);

//��������
void travel(sqListNode* list);

//������ĳ���
int GetListLength(sqListNode* list);

//���ٴ�������  1:ͷ�巨  -1:β�巨
void Array_MakeList(sqListNode*& list,int* arr,int n,Type type=back);

//����β���ڵ�
sqListNode* ArriveListTail(sqListNode* list);

//�ж������Ƿ�Ϊ��
inline
bool IsEmpty(sqListNode* list);

//ͷ�巨
void push_head(sqListNode*& list,Element elem);

//β�巨
void push_back(sqListNode*& list,Element elem);

//����λ�ò���
void Insert(sqListNode*& list,Element elem,int pos);

//ͷ��ɾ��
void pop_head(sqListNode*& list);

//β��ɾ��
void pop_back(sqListNode*& list);

//����λ��ɾ��
void Delete(sqListNode*& list,int pos);


/*
�������Ч���
*/

//��һ��ɨ��ȷ���������е�һ��Ԫ�����Ľڵ�
sqListNode* GetMaxNode(sqListNode* list);

//��һ��ɨ��ȷ���������е�һ��Ԫ�����Ľڵ��ǰ���ڵ�
sqListNode* GetMaxPreNode(sqListNode* list);

//ɾ����һ��Ԫ�����Ľڵ�
void Delete_Max(sqListNode*& list);

//����������Ԫ������
void Reverse(sqListNode*& list);

//�������Ƶ�ż����ǰ��
void pushOddToEvenNum(sqListNode*& list);

//��������Ķ�·�鲢: ������������ϳ�һ��������������ԭ����
void Merge_But_Destroy(sqListNode* list1,sqListNode* list2,sqListNode*& listDst);

//��������Ķ�·�鲢 ��������ϳ�һ���й�ͬԪ�ص��������������������ԭ����
void MergeComm_Not_Destroy(sqListNode* list1,sqListNode* list2,sqListNode*& Dst);

//�����������  �ݼ���less  ������greater 
void SortList(sqListNode*& list,Sort type);



/*
��ҵ
*/
//�жϵ������Ƿ������������
bool IsIncrease(sqListNode* list);

//���Ϊ��������,A����ż���ڵ㣬B���������ڵ�
void SplitList(sqListNode*& listA,sqListNode*& listB);

//���������������в���һ��ֵΪX�Ľڵ㣬������Ȼ����
void push_XNode(sqListNode*& list,Element elem);

//��ȸ�������
void CopyList(sqListNode*& list_dst,sqListNode* list_src);