#include<iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode *prev;
    struct LinkNode *next;
}LinkNode;

int main()
{
    LinkNode *head = NULL;
    LinkNode *tail = NULL;
    int value;
    cout <<"Input a value greater than 0,if -1,then stop:"<<endl;
    cin >> value;
    while(value != -1)
    {
        LinkNode *node = new  LinkNode();
        node->data=value;
        node->prev=node->next=NULL;
        if( head==NULL || tail==NULL)
            head=tail=node;
        else
        {
            node->prev=tail;
            tail->next=node;
            tail=node; 
        }
        cin>>value;
    }
    //output node data in inverse
    if(head != NULL && tail != NULL)
    {
        LinkNode *tmp = tail;
        while (tmp != head)
        { 
             cout<<tmp->data<<endl;
             tmp = tmp ->prev;
        }  
        cout<<tmp->data<<endl;
    }
    return 0;
}
