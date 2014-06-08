//You have two numbers represented by a linked list,where each node contains a single digit,The digits are stored in reversed order,such that the 1's digit is at the head of the list.Write a function that adds the two numbers and returns the sums as a linked list.
#include<iostream>
using namespace std;

struct LinkList{
    int data;
    LinkList *next;
};

LinkList *ComputeSum(LinkList* list1,LinkList* list2)
{
    if(list1 == NULL || list2 == NULL)
        return NULL;

    LinkList* listhead1 = list1;
    LinkList* listhead2 = list2;

    int carry=0;
    LinkList *head = NULL;
    LinkList *cur = NULL;

    int sum;
    while(listhead1 && listhead2)
    {
        int value = listhead1->data + listhead2->data + carry;

        sum = value % 10;
        carry = value / 10;

        LinkList *newnode = new LinkList;
        newnode->data = sum;
        newnode->next = NULL;

        if(head == NULL)
            cur = head = newnode;
        else
        {
            cur->next = newnode;
            cur=newnode;
        }

        listhead1 = listhead1->next;
        listhead2 = listhead2->next;
    }
    if(listhead1 || listhead2)
        return NULL;
    else
        return head;
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

    cout<<"Create the first List:"<<endl;
    LinkList *list1 = createList(array1,len1);
    printLink(list1);

    int len2;
    cout<<"Input the length of the second array:";
    cin>>len2;

    int array2[len2];
    cout<<"Input the element of the second array:";
    for( int i = 0 ; i< len2; i ++)
        cin>>array2[i];
    LinkList *list2 = createList(array2,len2);

    LinkList *sum=ComputeSum(list1,list2);
    printLink(sum);

    return 0;
}
