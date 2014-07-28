#include<iostream>
#include<assert.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(){next = NULL;}
    Node(int data):data(data){next = NULL;}
};

// n代表节点的个数，k是从第k开始数数，m是数到m就退出循环链表  
void countNumber(int n,int k, int m)
{
    cout<<"N:"<<n<<"  K:"<<k<<"  M:"<<m<<endl;
    assert(n > 0);
    Node *head = new Node;
    head->data = 1;
    
    int i = 1;

//创建循环链表
    Node *cur = head;
    while( ++i <= n)
    {
        Node *newNode = new Node(i);
        cur->next = newNode;
        cur = newNode;
    }
    cur->next = head;

    cur = head;

//从第k个节点开始数数
    int j = k;
    while(--j)
        cur = cur->next;
    
    while(1)
    {
        int i = k;
        while( i++ < m)
            cur = cur->next;

        cout<<cur->data<<" ";

        if(cur->next == cur)
        {
            delete cur;
            break;
        }
        else
        {
            Node *toBeDeleted = cur->next;
            cur->data = cur->next->data;
            cur->next = cur->next->next;
            delete toBeDeleted;
        }
    }

    cout<<"\n";
}

int main()
{
    countNumber(18,3,6);
    return 0;
}
