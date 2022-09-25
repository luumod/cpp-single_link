#pragma once
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
coef������ʽϵ��
exp�� ����ʽָ��
*/
 
typedef double coefType;
typedef int expType;

typedef struct node
{
	coefType coef;
	expType exp;
	struct node* next;
}LinkNode;


//��ʼ��������
void InitLink(LinkNode*& list);

//��������ڵ�
inline LinkNode* CreateLinkNode(const coefType& coef, const expType& exp);

//���崴��������
void CreateLink(LinkNode*& list);

//�жϵ������Ƿ�ݼ�����
bool IsGreater(LinkNode* list);

//����������
void sort(LinkNode*& list);

//����ʽ���
void Merge(LinkNode* ha,LinkNode* hb,LinkNode*& list);

//���ٵ�����
void DestroyLink(LinkNode*& list);

//����������
void travel(LinkNode* list);