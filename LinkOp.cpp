#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value,Node *next=NULL):data(value),next(next){}
    Node(){next = NULL;}
};

Node *createLink( int size)
{
    int value;
    scanf("%d",&value);
    Node *head = new Node(value);
    Node *cur = head;
    int j = 1;
    while( j < size)
    {
        scanf("%d",&value);
        Node *newNode = new Node(value);
        cur->next = newNode;
        cur = cur->next;
        j++;
    }

    return head;
}

void printLink(Node *head)
{
    if(head == NULL)
        return;
    Node *cur = head;
    while(cur)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<"\n";
}

Node *reverseLink(Node *head)
{
    if(head == NULL)
        return NULL;

    Node *prev = head;
    Node *cur = head->next;
    prev->next = NULL;
    while(cur)
    {
        Node *ne = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ne;
    }
    head = prev;
    return head;
}

void sortLink(Node *head) //冒泡排序
{
    if(head == NULL)
        return;

    if(head->next == NULL)
        return;

    Node *tail = head;
    while(tail->next)
        tail = tail->next;

    Node *cur = head;
    Node *post = head;

    while( post && post != tail)
    {
        Node *flag = head;
        while(post)
        {
            if(cur->data > post->data) //交换元素 
            {
                int temp = cur->data;
                cur->data = post->data;
                post->data = temp;
                flag = cur; 
            }

            cur = post;
            post = post->next;
        } 

        tail = flag;
        cur = post = head;
    }
}

Node *MiddleNode(Node *head)
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;

    Node *oneStep = head->next;
    Node *twoStep = head->next->next;
    Node *prev = head;

    while(twoStep != NULL && twoStep->next != NULL)
    {
        prev = oneStep;
        oneStep = oneStep->next;
        twoStep = twoStep->next->next;
    }

    if(twoStep == NULL)
        return prev;
    if(twoStep->next == NULL)
        return oneStep;

    return NULL;
}

int main()
{
    srand((unsigned)time(NULL));

    int len = rand()% 10 + 1;
    cout<<"Length:"<<len<<endl;

    Node *head = createLink(len);
    printLink(head);

    cout<<"Reverse Link:"<<endl;
    head = reverseLink(head);
    printLink(head);

    cout<<"Sort Link:"<<endl;
    sortLink(head);
    printLink(head);

    Node *mid = MiddleNode(head);
    cout<<mid->data<<endl;
    return 0;
}
