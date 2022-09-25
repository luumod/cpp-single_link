#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef int Element;
#define MAXSIZE 50
typedef struct 
{
    Element data[MAXSIZE];
    int length;             //ʵ�ʳ���
}sqList;


//��ʼ��˳���
void Init(sqList& list);

//ͷ�巨
void push_head(sqList& list,Element elem);

//β�巨
void push_back(sqList& list,Element elem);

//ָ��λ�ò���
void Insert(sqList& list,Element elem,int pos=-1);

//ͷɾ
void pop_head(sqList& list);

//βɾ
void pop_back(sqList& list);

//ָ��λ��ɾ��
void Delete(sqList& list,int pos);

//�ж�˳����Ƿ�Ϊ��
bool Isempty(const sqList& list);

//����˳���
void travel(const sqList& list);

/*
ϰ��
*/
//�ж�˳����Ԫ���Ƿ��������
bool IsIncrease(const sqList& list);

//����˳���
void Reverse(sqList& list);

//�����ظ�Ԫ�ص�˳��������һ�����ֵ֮�����һ��XԪ��
void InsertMaxElem(sqList& list,Element elem);

//���ǿ�˳����е�����Ԫ���ƶ��������
//ȡ�����Ԫ���±�
int GetMax(const sqList& list);
void MoveMax(sqList& list);


//���������㷨�������е������ƶ�ż���ĺ���
void odd_numberTOeven_number(sqList& list);

//��Чɾ��Ԫ�أ��ؽ�˳���
void Delete_Elem(sqList& list,Element elem);
//ɾ�����и���Ԫ��
void Delete_negativeNum(sqList& list);

//��·�鲢���������������ϲ����µĵ�������� : O(n+m)
void merge_list(sqList& list1,sqList& list2,sqList& DstList);

//����˳���Ĺ���Ԫ�������˳���O(m+n)
void CommElem_list(sqList& list1,sqList& list2,sqList& DstList);

//�ҳ���posС��Ԫ��
void Find_Pos_Little_Elem(sqList& list1,sqList& list2,int pos,Element& elem);