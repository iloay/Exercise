#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data,Node *leftNode = NULL,Node *rightNode = NULL):data(data),left(leftNode),right(rightNode){}
};

class HuffmanTree{
    public:
        HuffmanTree():root(NULL){}
        void createTree(int *array,int length);
        void print();
    private:
        Node *root;
        void print(Node *root);
};

class cmp{
    public:
        bool operator()(const Node* a,const Node* b) const
        {
            return a->data > b->data;
        }
};

void HuffmanTree::createTree(int *array,int length)
{
    if(array == NULL || length <= 0)
        return;

    priority_queue<Node *,vector<Node *>,cmp > q;
    for(int i = 0; i < length; i ++)
    {
        Node *cur = new Node(array[i]);
        q.push(cur);
    }

    Node *leftNode;
    Node *rightNode;
    while(!q.empty())
    {
        if(!q.empty())
        {
            leftNode = q.top();
            q.pop();
            root = leftNode;
        }
        if(!q.empty())
        {
            rightNode = q.top();
            q.pop();
            Node *parent = new Node(leftNode->data + rightNode->data,leftNode,rightNode);
            q.push(parent);
        }
    }
}

void HuffmanTree::print(Node *node)
{
    if(node == NULL)
        return;
    print(node->left);
    cout<<node->data<<" ";
    print(node->right);
}

void HuffmanTree::print()
{
    if(root == NULL)
        return;

    print(root);
    cout<<"\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int size = 10;
    int array[size];
    for(int i=0 ; i < size; i ++)
    {
        int data = rand() % 100;
        cout<<data<<" ";
        array[i] = data;
    }
    cout<<"\n";

    HuffmanTree h;
    h.createTree(array,size);
    h.print();
    return 0;
}
