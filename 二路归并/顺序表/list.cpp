#include "list.h"

//初始化链表
void InitList(sqListNode*& list)
{
    list=new sqListNode;
    list->Next=nullptr;
}

//创建链表节点
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

//销毁链表
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
    //链表删除成功
    printf("链表删除成功!\n");
    return;
}

//遍历链表
void travel(sqListNode* list)
{
    if (IsEmpty(list))
    {
        printf("链表为空!\n");
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

//快速创建链表
//快速创建链表  1:头插法  -1:尾插法
void Array_MakeList(sqListNode*& list,int* arr,int n,Type type)
{
    if (type==head)
    {
        //头插法
        for (int i=0;i<n;++i)
        {
            push_head(list,arr[i]);
        }
    }
    else if (type==back)
    {
        //尾插法
        for (int i=0;i<n;++i)
        {
            push_back(list,arr[i]);
        }
    }
    else
    {
        printf("用数组创建链表失败!\n");
    }
    return;
}


//到达尾部节点
sqListNode* ArriveListTail(sqListNode* list)
{
    sqListNode* pTemp=list->Next;
    while (pTemp->Next)
    {
        pTemp=pTemp->Next;
    }
    return pTemp;
}

//判断链表是否为空
inline
bool IsEmpty(sqListNode* list)
{
    return (list->Next==nullptr)?true:false;
}

//求链表的长度
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

//头插法
void push_head(sqListNode*& list,Element elem)
{
    sqListNode* pNew=CreateNode(elem);
    if (!pNew)
    {
        printf("节点创建失败!\n");
        return;
    }

    //如果链表为空
    if(IsEmpty(list))
    {
        list->Next=pNew;
    }
    else
    {   //链表不为空，头插法连接
        pNew->Next=list->Next;
        list->Next=pNew;
    }
}

//尾插法
void push_back(sqListNode*& list,Element elem)
{
    sqListNode* pNew=CreateNode(elem);
    if (!pNew)
    {
        printf("节点创建失败!\n");
        return;
    }
    sqListNode* pTail=nullptr;

    //如果链表为空
    if(IsEmpty(list))
    {
        list->Next=pNew;
    }
    else
    {   //链表不为空，尾插法连接
        pTail=ArriveListTail(list);
        pTail->Next=pNew;
        pTail=pNew;
    }

}

//任意位置插入
void Insert(sqListNode*& list,Element elem,int pos)
{
    sqListNode* pTemp=list->Next;
    sqListNode* pNew=CreateNode(elem);
    if (!pNew)
    {
        printf("节点创建失败!\n");
        return;
    }
    if (pos<=1 || pos> GetListLength(list))
    {
        printf("插入位置不合法!\n");
        return ;
    }
    for (int i=0;i<pos-2;++i)
    {
        pTemp=pTemp->Next;
    }
    //到达前一个节点
    pNew->Next=pTemp->Next;
    pTemp->Next=pNew;
}

//头部删除
void pop_head(sqListNode*& list)
{
    sqListNode* pTemp=list->Next;
    if (!GetListLength(list))
    {
        printf("链表为空!\n");
        return;
    }

    //删除首元节点
    list->Next=pTemp->Next;
    delete pTemp;
}

//尾部删除
void pop_back(sqListNode*& list)
{
    sqListNode* pTemp=list->Next,*pPreTail=pTemp;
    if (!GetListLength(list))
    {
        printf("链表为空!\n");
        return;
    }

    if (pTemp->Next==nullptr)
    {
        //只有一个节点
        delete pTemp;
        list->Next=nullptr;
        return;
    }

    //多于一个节点
    //到达尾部节点的前驱节点
    while (pPreTail->Next!=ArriveListTail(list))
    {
        pPreTail=pPreTail->Next;
    }
    pTemp=pPreTail->Next;
    pPreTail->Next=pTemp->Next;
    delete pTemp;
}

//任意位置删除
void Delete(sqListNode*& list,int pos)
{
    sqListNode* pTemp=list->Next,*pPre=list;
    if (!pTemp)
    {
        printf("链表为空!\n");
        return;
    }
    if (pos<=0 || pos> GetListLength(list))
    {
        printf("删除位置错误!\n");
        return;
    }

    for (int i=0;i<pos-1;++i)
    {
        pPre=pTemp;          //待删除前驱节点
        pTemp=pTemp->Next;   //删除节点
    }
    pPre->Next=pTemp->Next;
    delete pTemp;
}

//深度复制链表
void CopyList(sqListNode*& list_dst,sqListNode* list_src)
{
    sqListNode* pTemp=list_src->Next;
    while (pTemp)
    {
        push_back(list_dst,pTemp->data);
        pTemp=pTemp->Next;
    }
}

//用一趟扫描确定单链表中第一个元素最大的节点
sqListNode* GetMaxNode(sqListNode* list)
{
    auto pTemp=list->Next,MaxP=pTemp;
    if (IsEmpty(list))
    {
        printf("链表为空!\n");
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


//用一趟扫描确定单链表中第一个元素最大的节点的前驱节点
sqListNode* GetMaxPreNode(sqListNode* list)
{
    auto pTemp=list->Next,pTempPre=list,MaxP=pTemp,MaxPre=list;
    if (IsEmpty(list))
    {
        printf("链表为空!\n");
        return nullptr;
    }

    while (pTemp)
    {
        if (MaxP->data<pTemp->data)
        {
            MaxP=pTemp;      //最大值的前驱节点
            MaxPre=pTempPre;    
        }
        pTempPre=pTemp;         //移动的前驱节点
        pTemp=pTemp->Next;
    }
    return MaxPre;
}

//删除第一个元素最大的节点
void Delete_Max(sqListNode*& list)
{
    auto pTemp=list->Next,pTempPre=list,MaxP=pTemp,MaxPre=list;
    if (IsEmpty(list))
    {
        printf("链表为空!\n");
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

//单链表所有元素逆置
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


//将奇数移到偶数的前面
void pushOddToEvenNum(sqListNode*& list)
{
    sqListNode* pTemp=list->Next,*q,*pTail;
    list->Next=nullptr; //截断
    pTail=list;         //尾指针

    while (pTemp)
    {
        if (pTemp->data%2==1)
        {
            //奇数节点头插
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
            //偶数节点尾插
            pTail->Next=pTemp;
            pTail=pTemp;
            pTemp=pTemp->Next;
        }
    }
    pTail->Next=nullptr;
}

//有序单链表的二路归并: 两个递增链表合成一个递增链表   销毁原链表
void Merge_But_Destroy(sqListNode*& list1,sqListNode*& list2)
{
    sqListNode* p1=list1->Next,*p2=list2->Next,*pTail=nullptr;
    
    list1->Next=nullptr;
    pTail=list1;          //尾指针指向目标头节点

    delete list2;       //释放B链表头节点
    while (p1 && p2)
    {
        //尾插法
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


//有序单链表的二路归并 两个链表合成一个有共同元素的有序递增链表，不会销毁原链表
void MergeComm_Not_Destroy(sqListNode* list1,sqListNode* list2,sqListNode*& Dst)
{
    sqListNode* p1=list1->Next,*p2=list2->Next;
    sqListNode* pTail=nullptr,*pNew=nullptr;
    //尾指针指向目标头节点
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
                printf("节点创建失败!\n");
                return;
            }
            pTail->Next=pNew;
            pTail=pNew;

            p1=p1->Next;
            p2=p2->Next;
        }
    }
}

//单链表的排序
void SortList(sqListNode*& list,Sort type)
{
    //递减排序
    if (IsEmpty(list))
    {
        printf("链表为空!\n");
        return;
    }
    sqListNode* pPre=nullptr;
    sqListNode* pCur=list->Next->Next,*pTemp=nullptr;
    //分成两个表
    list->Next->Next=nullptr;

    while (pCur)
    {
        pTemp=pCur->Next;   //保存临时位置
        pPre=list;          //每次都从头节点开始遍历

        //((type==Sort::less)?
        //(
        //{
        //    while (pPre->Next && pPre->Next->data > pCur->data)
        //    {
        //        pPre=pPre->Next;    //移动到合适插入位置的前驱节点
        //    }
        //}) :
        //(
        //{
        //    while (pPre->Next && pPre->Next->data <  pCur->data)
        //    {
        //        pPre=pPre->Next;    //移动到合适插入位置的前驱节点
        //    }
        //}));
        //插入节点
        pCur->Next=pPre->Next;
        pPre->Next=pCur;
        pCur=pTemp;         //主链表节点移动
    }
}


//判断单链表是否是有序递增的
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


//拆分为两个链表,A链表偶数节点，B链表奇数节点
void SplitList(sqListNode*& listA,sqListNode*& listB)
{
    sqListNode* p1=listA->Next,*pTailB=listB,*pPre=listA;
    //如果节点是偶数，A不变；如果是奇数，删除并插入到B中
    while (p1)
    {
        if (p1->data%2==0)
        {
            //偶数
            pPre=p1;
            p1=p1->Next;
        }
        else
        {
            //奇数
            //B链表链接
            auto node=CreateNode(p1->data);
            pTailB->Next=node;
            pTailB=node;
            //A链表断开 
            pPre->Next=p1->Next;
            delete p1;
            p1=pPre->Next;
        }
    }
    pTailB->Next=nullptr;
}


//往递增有序链表中插入一个值为X的节点，链表仍然有序
void push_XNode(sqListNode*& list,Element elem)
{
    if (IsEmpty(list))
    {
        push_back(list,elem);
        return;
    }
    //递增有序链表
    sqListNode* pCur=list->Next->Next,*pPre=list->Next
    ;

    //假设是头插
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
                pPre->Next=node;    //连接
                return;
            }
            pPre=pPre->Next;
            pCur=pCur->Next;
        }
        //最后插入
        node->Next=pCur;
        pPre->Next=node;
    }

}