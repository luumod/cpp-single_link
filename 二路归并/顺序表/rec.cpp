#include "rec.h"

void Init(sqList& list)
{
    memset(list.data,0,sizeof(Element)*MAXSIZE);
    list.length=0;
}

//头插法
void push_head(sqList& list,Element elem)
{
    //所有元素往后退
    for (int i=list.length;i>0;i--)
    {
        list.data[i]=list.data[i-1];
    }
    list.data[0]=elem;
   
    list.length++;
}

//尾插法
void push_back(sqList& list,Element elem)
{
    list.data[list.length++]=elem;
}

//指定位置插入
void Insert(sqList& list,Element elem,int pos)
{
    if (pos<=1)
    {
        push_head(list,elem);
    }
    else if (pos>=list.length)
    {
        push_back(list,elem);
    }
    else
    {
        //此位置之后的所有元素往后移
        for (int i=list.length;i>pos-1;i--)
        {
            list.data[i]=list.data[i-1];
        }
        list.data[pos-1]=elem;
        list.length++;
    }
}

//头删
void pop_head(sqList& list)
{
    for (int i=0;i<list.length-1;i++)
    {
        list.data[i]=list.data[i+1];
    }
    list.length--;
}

//尾删
void pop_back(sqList& list)
{
    list.length--;
}

//指定位置删除
void Delete(sqList& list,int pos)
{
    if (pos<=1)
    {
        //默认头删
        pop_head(list);
    }
    else if (pos>=list.length)
    {
        //默认尾删
        pop_back(list);
    }
    else
    {
        //中间位置删除
        for (int i=pos-1;i<list.length;i++)
        {
            list.data[i]=list.data[i+1];
        }
        list.length--;
    }
}

//判断顺序表是否为空
bool Isempty(const sqList& list)
{
    if (!list.length)
    {
        return true;
    }
    return false;
}


//遍历顺序表
void travel(const sqList& list)
{
    if (Isempty(list))
    {
        cout<<"顺序表为空!\n";
        return;
    }
    for (int i=0;i<list.length;++i)
    {
        cout<<list.data[i]<<" ";
    }
    cout<<endl;
}


//判断顺序表的元素是否递增有序
bool IsIncrease(const sqList& list)
{
    for (int i=0;i<list.length-1;++i)
    {
        if (list.data[i]>=list.data[i+1])
        {
            return false;
        }
    }
    return true;
}

//逆置顺序表 空间O(1)
void swap(int& data1,int& data2)
{
    auto temp=data1;
    data1=data2;
    data2=temp;
}
void Reverse(sqList& list)
{
    int left=0,right=list.length-1;
    while (left<right)
    {
        swap(list.data[left],list.data[right]);
        left++;
        right--;
    }
}

//具有重复元素的顺序表，在最后一个最大值之后插入一个elem元素
void InsertMaxElem(sqList& list,Element elem)
{
    auto MaxElemIndex=0,MaxElem=list.data[0];
    for (int i=1;i<list.length;++i)
    {
        if (MaxElem<=list.data[i])
        {
            MaxElem=list.data[i];   //最大值元素
            MaxElemIndex=i;         //具有最大值的下标
        }
    }
    Insert(list,elem,MaxElemIndex+2);

}

//将非空顺序表中的最大的元素移动到最后面
//取得最大元素下标
int GetMax(const sqList& list)
{
    auto MaxElemIndex=0,MaxElem=list.data[0];
    for (int i=1;i<list.length;++i)
    {
        if (MaxElem<list.data[i])
        {
            MaxElem=list.data[i];   //最大值元素
            MaxElemIndex=i;         //具有最大值的下标
        }
    }
    return MaxElemIndex;    //返回下标
}
void MoveMax(sqList& list)
{
    auto MaxElemIndex=GetMax(list);  //得到了最大元素

    //相邻交换，移动到最后一个
    for (int i=MaxElemIndex;i<list.length-1;++i)
    {
        swap(list.data[i],list.data[i+1]);
    }
}


//奇数到偶数的后面
void odd_numberTOeven_number(sqList& list)
{
    int start_index=0,end_index=list.length-1;
    while (start_index<end_index)
    {
        //从前往后找奇数
        while (!(list.data[start_index]%2))
        {
            //如果是偶数，则往后移动
            start_index++;
        }
        //从后往前找偶数
        while (list.data[end_index]%2)
        {
            //如果是奇数，则往前移动
            end_index--;
        }
        if (start_index<end_index)
        {
            swap(list.data[start_index],list.data[end_index]);
        }   
    }

}


//高效删除元素：重建顺序表
void Delete_Elem(sqList& list,Element elem)
{
    int New_index=0;
    for (int i=0;i<list.length;++i)
    {
        if (list.data[i]!=elem)
        {
            list.data[New_index++]=list.data[i];
        }
    }
    list.length=New_index;
}

//删除所有负数元素
void Delete_negativeNum(sqList& list)
{
    int New_index=0;
    for (int i=0;i<list.length;++i)
    {
        if (list.data[i]>=0)
        {
            list.data[New_index++]=list.data[i];
        }
    }
    list.length=New_index;
}


//二路归并：两个有序表合并成新的递增有序表
void merge_list(sqList& list1,sqList& list2,sqList& DstList)
{
    int index_A=0;
    int index_B=0;
    int index_Dst=0;
    while (index_A<list1.length && index_B<list2.length)
    {
        if (list1.data[index_A]<list2.data[index_B])
        {
            DstList.data[index_Dst++]=list1.data[index_A];
            index_A++;
        }
        else
        {
            DstList.data[index_Dst++]=list2.data[index_B];
            index_B++;
        }
    }
    //多余的元素在填充
    while (index_A<list1.length)
    {
        DstList.data[index_Dst++]=list1.data[index_A++];
    }
    while (index_B<list2.length)
    {
        DstList.data[index_Dst++]=list2.data[index_B++];
    }
    DstList.length=index_Dst++;
}


//两个顺序表的公共元素组成新顺序表
void CommElem_list(sqList& list1,sqList& list2,sqList& DstList)
{
    int index_A=0,index_B=0,index_Dst=0;
    while (index_A<list1.length && index_B<list2.length)
    {
        if (list1.data[index_A] < list2.data[index_B])
        {
            index_A++;
        }
        else if (list2.data[index_B] < list1.data[index_A])
        {
            index_B++;
        }
        else
        {
            DstList.data[index_Dst++]=list1.data[index_A];
            index_A++;
            index_B++;
        }
    }
    DstList.length=index_Dst;
}



//找出第pos小的元素
void Find_Pos_Little_Elem(sqList& list1,sqList& list2,int pos,Element& elem)
{
#define INF 32767
    int index_A=0,index_B=0;
    //pos越界
    if (pos<1 || pos>list1.length+list2.length)
    {
        cout<<"没有找到!\n"<<endl;
        return;
    }
#if 1
    //当pos递减为0时，所在位置即是我们需要的元素
    while (index_A<list1.length && index_B<list2.length)
    {
        pos--;
        if (list1.data[index_A] < list2.data[index_B])
        {
            if (!pos)
            {
                elem=list1.data[index_A];
                return;
            }
            index_A++;
        }
        else
        {
            if (!pos)
            {
                elem=list2.data[index_B];
                return;
            }
            index_B++;
        }
    }

    //如果遍历完A或者B表后没有找到元素，则说明第pos个位置的元素不在A或B表中，则根据位置关系可以直接确定此位置元素
    // A: 1 2 6 8 10
    // B: 3 4 5 7 11  
    /*
    pos=6  B： 0+1-1
    */
   //已经找完了一个表，不在这个表里面，则必在另一个表里面
    if (index_A<list1.length)
    {
        elem=list1.data[index_A+pos-1];
    }
    else if (index_B<list2.length) 
    {
        elem=list2.data[index_B+pos-1];
    }
#else
/*
简化版本
*/
    while (true)
    {
        pos--;
        //遍历完A表后没有找到，则直接让A表的元素大于B表的所有元素，这样就可以直接进入else继续判断
        int _list1=((index_A<list1.length)?list1.data[index_A]:INF);
        //遍历完B表后没有找到，则直接让B表的元素大于A表的所有元素，这样就可以直接进入if继续判断
        int _list2=((index_B<list2.length)?list2.data[index_B]:INF);
        if (_list1<_list2)
        {
            if (!pos)
            {
                elem=_list1;
                return;
            }
            index_A++;
        }
        else
        {
            if (!pos)
            {
                elem=_list2;
                return;
            }
            index_B++;
        }
    }

#endif 
    return;
}