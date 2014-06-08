//Given two sorted linked list, and merge them without using extra space(using constant space is allowed).For example,if 1->2->5 merges with 2->4->5,we have 1->2->4->5
#include<iostream>
using namespace std;


struct LinkList{
    int data;
    LinkList *next;
};

LinkList* mergeList(LinkList *list1,LinkList *list2)
{
    if(list1 == NULL || list2 == NULL)
        if(list1 == NULL)
            return list2;
        else
            return list1;

    LinkList *listhead1 = list1;
    LinkList *listhead2 = list2;

    LinkList *newhead = NULL;
    LinkList *cur = NULL;

    while(listhead1 && listhead2)
    {
        int value;
        if(listhead1->data < listhead2->data)
        {
            value = listhead1->data;
            listhead1 = listhead1->next;
        }
        else if(listhead2->data < listhead1->data)
        {
            value = listhead2->data;
            listhead2 = listhead2->next;
        }
        else
        {
            value = listhead1->data;
            listhead1 = listhead1->next;
            listhead2 = listhead2->next;
        }

        LinkList *newnode = new LinkList;
        newnode->data = value;
        newnode->next = NULL;

        if(newhead == NULL)
            cur = newhead = newnode;
        else
        {
            cur ->next = newnode;
            cur = newnode;
        }
    }

    if(listhead1)
        cur->next = listhead1;
    else if(listhead2)
        cur->next = listhead2;
    else
        ;

    return newhead;
}

void printLink(LinkList *head)
{
    LinkList *cur = head;
    while(cur)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

LinkList* createList(int array[],int len)
{
    if(len <= 0 )
        return NULL;

    LinkList *head = new LinkList;
    head->data = array[0];
    head->next = NULL;

    LinkList *cur = head;
    for(int i = 1; i < len; i ++)
    {
        LinkList *newnode = new LinkList;
        newnode->data = array[i];
        newnode->next = NULL;
    
        cur->next = newnode;
        cur = newnode;
    }

    return head;
}

int main()
{
    int len1;
    cout<<"Input the length of the first array:";
    cin>>len1;

    int array1[len1];
    cout<<"Input the element of the first array:";
    for( int i = 0 ; i< len1; i ++)
        cin>>array1[i];

    LinkList *list1 = createList(array1,len1);

    int len2;
    cout<<"Input the length of the second array:";
    cin>>len2;

    int array2[len2];
    cout<<"Input the element of the second array:";
    for( int i = 0 ; i< len2; i ++)
        cin>>array2[i];

    LinkList *list2 = createList(array2,len2);

    LinkList *merger=mergeList(list1,list2);
    printLink(merger);

    return 0;
}
