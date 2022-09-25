#include "list.h"

//��ʼ������
void InitList(sqListNode*& list)
{
    list=new sqListNode;
    list->Next=nullptr;
}

//��������ڵ�
inline
sqListNode* CreateNode(Element elem)
{
    sqListNode* NewNode=new sqListNode;
    if (!NewNode)
    {
        return nullptr;
    }
    NewNode->data=elem;
    NewNode->Next=nullptr;
    return NewNode;
}

//��������
void DestroyList(sqListNode*& list)
{
    sqListNode* pTemp=nullptr,*pCur=list->Next;
    while (pCur)
    {
        pTemp=pCur->Next;
        delete pCur;
        pCur=nullptr;
        pCur=pTemp;
    } 
    //����ɾ���ɹ�
    printf("����ɾ���ɹ�!\n");
    return;
}

//��������
void travel(sqListNode* list)
{
    if (IsEmpty(list))
    {
        printf("����Ϊ��!\n");
        return;
    }
    sqListNode* pTemp=list->Next;
    while (pTemp)
    {
        printf("%d ",pTemp->data);
        pTemp=pTemp->Next;
    }
    cout<<endl;
}

//���ٴ�������
//���ٴ�������  1:ͷ�巨  -1:β�巨
void Array_MakeList(sqListNode*& list,int* arr,int n,Type type)
{
    if (type==head)
    {
        //ͷ�巨
        for (int i=0;i<n;++i)
        {
            push_head(list,arr[i]);
        }
    }
    else if (type==back)
    {
        //β�巨
        for (int i=0;i<n;++i)
        {
            push_back(list,arr[i]);
        }
    }
    else
    {
        printf("�����鴴������ʧ��!\n");
    }
    return;
}


//����β���ڵ�
sqListNode* ArriveListTail(sqListNode* list)
{
    sqListNode* pTemp=list->Next;
    while (pTemp->Next)
    {
        pTemp=pTemp->Next;
    }
    return pTemp;
}

//�ж������Ƿ�Ϊ��
inline
bool IsEmpty(sqListNode* list)
{
    return (list->Next==nullptr)?true:false;
}

//������ĳ���
int GetListLength(sqListNode* list)
{
    int length=0;
    auto pTemp=list->Next;

    while (pTemp)
    {
        length++;
        pTemp=pTemp->Next;
    }
    return length;
}

//ͷ�巨
void push_head(sqListNode*& list,Element elem)
{
    sqListNode* pNew=CreateNode(elem);
    if (!pNew)
    {
        printf("�ڵ㴴��ʧ��!\n");
        return;
    }

    //�������Ϊ��
    if(IsEmpty(list))
    {
        list->Next=pNew;
    }
    else
    {   //����Ϊ�գ�ͷ�巨����
        pNew->Next=list->Next;
        list->Next=pNew;
    }
}

//β�巨
void push_back(sqListNode*& list,Element elem)
{
    sqListNode* pNew=CreateNode(elem);
    if (!pNew)
    {
        printf("�ڵ㴴��ʧ��!\n");
        return;
    }
    sqListNode* pTail=nullptr;

    //�������Ϊ��
    if(IsEmpty(list))
    {
        list->Next=pNew;
    }
    else
    {   //����Ϊ�գ�β�巨����
        pTail=ArriveListTail(list);
        pTail->Next=pNew;
        pTail=pNew;
    }

}

//����λ�ò���
void Insert(sqListNode*& list,Element elem,int pos)
{
    sqListNode* pTemp=list->Next;
    sqListNode* pNew=CreateNode(elem);
    if (!pNew)
    {
        printf("�ڵ㴴��ʧ��!\n");
        return;
    }
    if (pos<=1 || pos> GetListLength(list))
    {
        printf("����λ�ò��Ϸ�!\n");
        return ;
    }
    for (int i=0;i<pos-2;++i)
    {
        pTemp=pTemp->Next;
    }
    //����ǰһ���ڵ�
    pNew->Next=pTemp->Next;
    pTemp->Next=pNew;
}

//ͷ��ɾ��
void pop_head(sqListNode*& list)
{
    sqListNode* pTemp=list->Next;
    if (!GetListLength(list))
    {
        printf("����Ϊ��!\n");
        return;
    }

    //ɾ����Ԫ�ڵ�
    list->Next=pTemp->Next;
    delete pTemp;
}

//β��ɾ��
void pop_back(sqListNode*& list)
{
    sqListNode* pTemp=list->Next,*pPreTail=pTemp;
    if (!GetListLength(list))
    {
        printf("����Ϊ��!\n");
        return;
    }

    if (pTemp->Next==nullptr)
    {
        //ֻ��һ���ڵ�
        delete pTemp;
        list->Next=nullptr;
        return;
    }

    //����һ���ڵ�
    //����β���ڵ��ǰ���ڵ�
    while (pPreTail->Next!=ArriveListTail(list))
    {
        pPreTail=pPreTail->Next;
    }
    pTemp=pPreTail->Next;
    pPreTail->Next=pTemp->Next;
    delete pTemp;
}

//����λ��ɾ��
void Delete(sqListNode*& list,int pos)
{
    sqListNode* pTemp=list->Next,*pPre=list;
    if (!pTemp)
    {
        printf("����Ϊ��!\n");
        return;
    }
    if (pos<=0 || pos> GetListLength(list))
    {
        printf("ɾ��λ�ô���!\n");
        return;
    }

    for (int i=0;i<pos-1;++i)
    {
        pPre=pTemp;          //��ɾ��ǰ���ڵ�
        pTemp=pTemp->Next;   //ɾ���ڵ�
    }
    pPre->Next=pTemp->Next;
    delete pTemp;
}

//��ȸ�������
void CopyList(sqListNode*& list_dst,sqListNode* list_src)
{
    sqListNode* pTemp=list_src->Next;
    while (pTemp)
    {
        push_back(list_dst,pTemp->data);
        pTemp=pTemp->Next;
    }
}

//��һ��ɨ��ȷ���������е�һ��Ԫ�����Ľڵ�
sqListNode* GetMaxNode(sqListNode* list)
{
    auto pTemp=list->Next,MaxP=pTemp;
    if (IsEmpty(list))
    {
        printf("����Ϊ��!\n");
        return nullptr;
    }

    while (pTemp)
    {
        if (MaxP->data<pTemp->data)
        {
            MaxP=pTemp;
        }
        pTemp=pTemp->Next;
    }
    return MaxP;
}


//��һ��ɨ��ȷ���������е�һ��Ԫ�����Ľڵ��ǰ���ڵ�
sqListNode* GetMaxPreNode(sqListNode* list)
{
    auto pTemp=list->Next,pTempPre=list,MaxP=pTemp,MaxPre=list;
    if (IsEmpty(list))
    {
        printf("����Ϊ��!\n");
        return nullptr;
    }

    while (pTemp)
    {
        if (MaxP->data<pTemp->data)
        {
            MaxP=pTemp;      //���ֵ��ǰ���ڵ�
            MaxPre=pTempPre;    
        }
        pTempPre=pTemp;         //�ƶ���ǰ���ڵ�
        pTemp=pTemp->Next;
    }
    return MaxPre;
}

//ɾ����һ��Ԫ�����Ľڵ�
void Delete_Max(sqListNode*& list)
{
    auto pTemp=list->Next,pTempPre=list,MaxP=pTemp,MaxPre=list;
    if (IsEmpty(list))
    {
        printf("����Ϊ��!\n");
        return;
    }

    while (pTemp)
    {
        if (MaxP->data<pTemp->data)
        {
            MaxP=pTemp;
            MaxPre=pTempPre;
        }
        pTempPre=pTemp;
        pTemp=pTemp->Next;
    }

    MaxPre->Next=MaxP->Next;
    delete MaxP;
}

//����������Ԫ������
void Reverse(sqListNode*& list)
{
    sqListNode* pTemp=list->Next,*pTempNext=nullptr;
    list->Next=nullptr;

    while (pTemp)
    {
        pTempNext=pTemp->Next;
        pTemp->Next=list->Next;
        list->Next=pTemp;
        pTemp=pTempNext;
    }
}


//�������Ƶ�ż����ǰ��
void pushOddToEvenNum(sqListNode*& list)
{
    sqListNode* pTemp=list->Next,*q,*pTail;
    list->Next=nullptr; //�ض�
    pTail=list;         //βָ��

    while (pTemp)
    {
        if (pTemp->data%2==1)
        {
            //�����ڵ�ͷ��
            q=pTemp->Next;
            if (list->Next==nullptr)
            {
                pTemp->Next=list->Next;
                list->Next=pTemp;
                pTail=pTemp;    
            }
            else
            {
                pTemp->Next=list->Next;
                list->Next=pTemp;
            }
            pTemp=q;
        }
        else
        {
            //ż���ڵ�β��
            pTail->Next=pTemp;
            pTail=pTemp;
            pTemp=pTemp->Next;
        }
    }
    pTail->Next=nullptr;
}

//��������Ķ�·�鲢: ������������ϳ�һ����������   ����ԭ����
void Merge_But_Destroy(sqListNode*& list1,sqListNode*& list2)
{
    sqListNode* p1=list1->Next,*p2=list2->Next,*pTail=nullptr;
    
    list1->Next=nullptr;
    pTail=list1;          //βָ��ָ��Ŀ��ͷ�ڵ�

    delete list2;       //�ͷ�B����ͷ�ڵ�
    while (p1 && p2)
    {
        //β�巨
        if (p1->data < p2->data)
        {  
            pTail->Next=p1;
            pTail=p1;
            p1=p1->Next;
        }
        else
        {
   
            pTail->Next=p2;
            pTail=p2;
            p2=p2->Next;
        }
    }
    pTail->Next=nullptr;
    if (p1)
    {
        pTail->Next=p1;
    }
    if (p2)
    {
        pTail->Next=p2;
    }
    list2->Next=nullptr;
}


//��������Ķ�·�鲢 ��������ϳ�һ���й�ͬԪ�ص��������������������ԭ����
void MergeComm_Not_Destroy(sqListNode* list1,sqListNode* list2,sqListNode*& Dst)
{
    sqListNode* p1=list1->Next,*p2=list2->Next;
    sqListNode* pTail=nullptr,*pNew=nullptr;
    //βָ��ָ��Ŀ��ͷ�ڵ�
    pTail=Dst;

    while (p1 && p2)
    {
        if (p1->data<p2->data)
        {
            p1=p1->Next;
        }
        else if (p2->data < p1->data)
        {
            p2=p2->Next;
        }
        else
        {
            pNew=CreateNode(p1->data);
            if (!pNew)
            {
                printf("�ڵ㴴��ʧ��!\n");
                return;
            }
            pTail->Next=pNew;
            pTail=pNew;

            p1=p1->Next;
            p2=p2->Next;
        }
    }
}

//�����������
void SortList(sqListNode*& list,Sort type)
{
    //�ݼ�����
    if (IsEmpty(list))
    {
        printf("����Ϊ��!\n");
        return;
    }
    sqListNode* pPre=nullptr;
    sqListNode* pCur=list->Next->Next,*pTemp=nullptr;
    //�ֳ�������
    list->Next->Next=nullptr;

    while (pCur)
    {
        pTemp=pCur->Next;   //������ʱλ��
        pPre=list;          //ÿ�ζ���ͷ�ڵ㿪ʼ����

        //((type==Sort::less)?
        //(
        //{
        //    while (pPre->Next && pPre->Next->data > pCur->data)
        //    {
        //        pPre=pPre->Next;    //�ƶ������ʲ���λ�õ�ǰ���ڵ�
        //    }
        //}) :
        //(
        //{
        //    while (pPre->Next && pPre->Next->data <  pCur->data)
        //    {
        //        pPre=pPre->Next;    //�ƶ������ʲ���λ�õ�ǰ���ڵ�
        //    }
        //}));
        //����ڵ�
        pCur->Next=pPre->Next;
        pPre->Next=pCur;
        pCur=pTemp;         //������ڵ��ƶ�
    }
}


//�жϵ������Ƿ������������
bool IsIncrease(sqListNode* list)
{
    sqListNode* pTemp=list->Next,*pNextTemp=pTemp->Next;
    while (pNextTemp)
    {
        if (pTemp->data>pNextTemp->data)
        {
            return false;
        }
        pTemp=pNextTemp;
        pNextTemp=pNextTemp->Next;
    }
    return true;
}


//���Ϊ��������,A����ż���ڵ㣬B���������ڵ�
void SplitList(sqListNode*& listA,sqListNode*& listB)
{
    sqListNode* p1=listA->Next,*pTailB=listB,*pPre=listA;
    //����ڵ���ż����A���䣻�����������ɾ�������뵽B��
    while (p1)
    {
        if (p1->data%2==0)
        {
            //ż��
            pPre=p1;
            p1=p1->Next;
        }
        else
        {
            //����
            //B��������
            auto node=CreateNode(p1->data);
            pTailB->Next=node;
            pTailB=node;
            //A����Ͽ� 
            pPre->Next=p1->Next;
            delete p1;
            p1=pPre->Next;
        }
    }
    pTailB->Next=nullptr;
}


//���������������в���һ��ֵΪX�Ľڵ㣬������Ȼ����
void push_XNode(sqListNode*& list,Element elem)
{
    if (IsEmpty(list))
    {
        push_back(list,elem);
        return;
    }
    //������������
    sqListNode* pCur=list->Next->Next,*pPre=list->Next
    ;

    //������ͷ��
    if (pPre->data>=elem)
    {
        push_head(list,elem);
    }
    else
    {
        auto node=CreateNode(elem);
        while (pCur)
        {
            if (pPre->data<=elem && elem<=pCur->data)
            {
                node->Next=pCur;
                pPre->Next=node;    //����
                return;
            }
            pPre=pPre->Next;
            pCur=pCur->Next;
        }
        //������
        node->Next=pCur;
        pPre->Next=node;
    }

}