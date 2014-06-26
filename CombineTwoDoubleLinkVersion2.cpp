#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct DNode{
    int data;
    DNode *prev;
    DNode *next;
};

void insertNode(DNode **root,int value)
{
    DNode *newNode = new DNode;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(root == NULL || *root == NULL)
        (*root) = newNode;
    else
    {
        DNode *cur = *root;
        // Insert node by asce order
        while( cur->data < value && cur->next )
            cur = cur->next;
        
        if(cur == *root && cur->data > value) //insert node before root node
        {
            newNode->next = cur;
            cur->prev = newNode;
            (*root) = newNode;
        }
        else if(cur->data < value && cur->next == NULL) // insert node at the tail
        {
            cur->next = newNode;
            newNode->prev = cur;
        }
        else                                          // insert node in the middle of double link
        {
            newNode->prev=cur->prev;
            newNode->next=cur;
            cur->prev->next=newNode;
            cur->prev=newNode;
        }
    }
}

void printDLink(DNode *root)
{
    if(root ==  NULL)
        return;

    DNode *cur = root;
    while(cur)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<"\n";
}

DNode *combineTwoDLink(DNode *root1,DNode *root2)
{
    DNode *head = new DNode ;
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;

    DNode *cur = head;
    
    if(root1 == NULL || root2 == NULL)
    {
        if(root1 == NULL)
            return root2;
        else
            return root1;
    }

    DNode *begin1 = root1;
    DNode *tail1 = root1;

    DNode *begin2 = root2;
    DNode *tail2 = root2;

    while( tail1 && tail2 )
    {
        if( tail1 && tail2 && tail1->data <= tail2->data )
        {
            DNode *prevNode = tail1;
            while( tail1 && tail1->data <= tail2->data )
            {
                prevNode = tail1;
                tail1 = tail1->next;
            }
            
            cur->next = begin1;
            begin1->prev = cur;
            cur = prevNode;

            if( tail1 )
                begin1 = tail1;
        }

        if( tail1 && tail2 && tail2->data <= tail1->data )
        {
            DNode *prevNode = tail2;
            while(tail2 && tail2->data <= tail1->data )
            {
                prevNode = tail2;
                tail2 = tail2->next;
            }

            cur->next = begin2;
            begin2->prev = cur;
            cur = prevNode;

            if( tail2 )
                begin2 = tail2;
        }
    }

    if( tail1 == NULL && tail2 )
    {
        cur->next = begin2;
        begin2->prev = cur;
    }

    if( tail2 == NULL && tail1 )
    {
        cur->next = begin1;
        begin1->prev = cur;
    }

    head = head->next;

    return head;
}

int main()
{
    DNode *root1 = NULL;
    srand((unsigned)time(NULL));
    for(int i = 0 ; i < 10; i ++)
        insertNode(&root1,rand()%100);
    printDLink(root1);
    cout<<"\n";

    DNode *root2 = NULL;
    for(int i = 0 ; i < 10; i ++)
        insertNode(&root2,rand()%100);
    printDLink(root2);
    cout<<"\n";

    cout<<"Combine the Double Link Above\n";
    DNode *head = combineTwoDLink(root1,root2);
    printDLink(head);

    return 0;
}
