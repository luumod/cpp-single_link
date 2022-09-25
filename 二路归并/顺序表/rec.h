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
    int length;             //实际长度
}sqList;


//初始化顺序表
void Init(sqList& list);

//头插法
void push_head(sqList& list,Element elem);

//尾插法
void push_back(sqList& list,Element elem);

//指定位置插入
void Insert(sqList& list,Element elem,int pos=-1);

//头删
void pop_head(sqList& list);

//尾删
void pop_back(sqList& list);

//指定位置删除
void Delete(sqList& list,int pos);

//判断顺序表是否为空
bool Isempty(const sqList& list);

//遍历顺序表
void travel(const sqList& list);

/*
习题
*/
//判断顺序表的元素是否递增有序
bool IsIncrease(const sqList& list);

//逆置顺序表
void Reverse(sqList& list);

//具有重复元素的顺序表，在最后一个最大值之后插入一个X元素
void InsertMaxElem(sqList& list,Element elem);

//将非空顺序表中的最大的元素移动到最后面
//取得最大元素下标
int GetMax(const sqList& list);
void MoveMax(sqList& list);


//快速排序算法：将所有的奇数移动偶数的后面
void odd_numberTOeven_number(sqList& list);

//高效删除元素：重建顺序表
void Delete_Elem(sqList& list,Element elem);
//删除所有负数元素
void Delete_negativeNum(sqList& list);

//二路归并：两个递增有序表合并成新的递增有序表 : O(n+m)
void merge_list(sqList& list1,sqList& list2,sqList& DstList);

//两个顺序表的公共元素组成新顺序表：O(m+n)
void CommElem_list(sqList& list1,sqList& list2,sqList& DstList);

//找出第pos小的元素
void Find_Pos_Little_Elem(sqList& list1,sqList& list2,int pos,Element& elem);