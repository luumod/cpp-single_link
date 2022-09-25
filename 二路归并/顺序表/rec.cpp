#include "rec.h"

void Init(sqList& list)
{
    memset(list.data,0,sizeof(Element)*MAXSIZE);
    list.length=0;
}

//ͷ�巨
void push_head(sqList& list,Element elem)
{
    //����Ԫ��������
    for (int i=list.length;i>0;i--)
    {
        list.data[i]=list.data[i-1];
    }
    list.data[0]=elem;
   
    list.length++;
}

//β�巨
void push_back(sqList& list,Element elem)
{
    list.data[list.length++]=elem;
}

//ָ��λ�ò���
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
        //��λ��֮�������Ԫ��������
        for (int i=list.length;i>pos-1;i--)
        {
            list.data[i]=list.data[i-1];
        }
        list.data[pos-1]=elem;
        list.length++;
    }
}

//ͷɾ
void pop_head(sqList& list)
{
    for (int i=0;i<list.length-1;i++)
    {
        list.data[i]=list.data[i+1];
    }
    list.length--;
}

//βɾ
void pop_back(sqList& list)
{
    list.length--;
}

//ָ��λ��ɾ��
void Delete(sqList& list,int pos)
{
    if (pos<=1)
    {
        //Ĭ��ͷɾ
        pop_head(list);
    }
    else if (pos>=list.length)
    {
        //Ĭ��βɾ
        pop_back(list);
    }
    else
    {
        //�м�λ��ɾ��
        for (int i=pos-1;i<list.length;i++)
        {
            list.data[i]=list.data[i+1];
        }
        list.length--;
    }
}

//�ж�˳����Ƿ�Ϊ��
bool Isempty(const sqList& list)
{
    if (!list.length)
    {
        return true;
    }
    return false;
}


//����˳���
void travel(const sqList& list)
{
    if (Isempty(list))
    {
        cout<<"˳���Ϊ��!\n";
        return;
    }
    for (int i=0;i<list.length;++i)
    {
        cout<<list.data[i]<<" ";
    }
    cout<<endl;
}


//�ж�˳����Ԫ���Ƿ��������
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

//����˳��� �ռ�O(1)
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

//�����ظ�Ԫ�ص�˳��������һ�����ֵ֮�����һ��elemԪ��
void InsertMaxElem(sqList& list,Element elem)
{
    auto MaxElemIndex=0,MaxElem=list.data[0];
    for (int i=1;i<list.length;++i)
    {
        if (MaxElem<=list.data[i])
        {
            MaxElem=list.data[i];   //���ֵԪ��
            MaxElemIndex=i;         //�������ֵ���±�
        }
    }
    Insert(list,elem,MaxElemIndex+2);

}

//���ǿ�˳����е�����Ԫ���ƶ��������
//ȡ�����Ԫ���±�
int GetMax(const sqList& list)
{
    auto MaxElemIndex=0,MaxElem=list.data[0];
    for (int i=1;i<list.length;++i)
    {
        if (MaxElem<list.data[i])
        {
            MaxElem=list.data[i];   //���ֵԪ��
            MaxElemIndex=i;         //�������ֵ���±�
        }
    }
    return MaxElemIndex;    //�����±�
}
void MoveMax(sqList& list)
{
    auto MaxElemIndex=GetMax(list);  //�õ������Ԫ��

    //���ڽ������ƶ������һ��
    for (int i=MaxElemIndex;i<list.length-1;++i)
    {
        swap(list.data[i],list.data[i+1]);
    }
}


//������ż���ĺ���
void odd_numberTOeven_number(sqList& list)
{
    int start_index=0,end_index=list.length-1;
    while (start_index<end_index)
    {
        //��ǰ����������
        while (!(list.data[start_index]%2))
        {
            //�����ż�����������ƶ�
            start_index++;
        }
        //�Ӻ���ǰ��ż��
        while (list.data[end_index]%2)
        {
            //���������������ǰ�ƶ�
            end_index--;
        }
        if (start_index<end_index)
        {
            swap(list.data[start_index],list.data[end_index]);
        }   
    }

}


//��Чɾ��Ԫ�أ��ؽ�˳���
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

//ɾ�����и���Ԫ��
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


//��·�鲢�����������ϲ����µĵ��������
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
    //�����Ԫ�������
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


//����˳���Ĺ���Ԫ�������˳���
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



//�ҳ���posС��Ԫ��
void Find_Pos_Little_Elem(sqList& list1,sqList& list2,int pos,Element& elem)
{
#define INF 32767
    int index_A=0,index_B=0;
    //posԽ��
    if (pos<1 || pos>list1.length+list2.length)
    {
        cout<<"û���ҵ�!\n"<<endl;
        return;
    }
#if 1
    //��pos�ݼ�Ϊ0ʱ������λ�ü���������Ҫ��Ԫ��
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

    //���������A����B���û���ҵ�Ԫ�أ���˵����pos��λ�õ�Ԫ�ز���A��B���У������λ�ù�ϵ����ֱ��ȷ����λ��Ԫ��
    // A: 1 2 6 8 10
    // B: 3 4 5 7 11  
    /*
    pos=6  B�� 0+1-1
    */
   //�Ѿ�������һ����������������棬�������һ��������
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
�򻯰汾
*/
    while (true)
    {
        pos--;
        //������A���û���ҵ�����ֱ����A���Ԫ�ش���B�������Ԫ�أ������Ϳ���ֱ�ӽ���else�����ж�
        int _list1=((index_A<list1.length)?list1.data[index_A]:INF);
        //������B���û���ҵ�����ֱ����B���Ԫ�ش���A�������Ԫ�أ������Ϳ���ֱ�ӽ���if�����ж�
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