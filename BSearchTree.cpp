#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<queue>
using namespace std;

struct BNode{
    int data;
    BNode *leftNode;
    BNode *rightNode;
};

void insertNode(BNode **root,int value)
{
    BNode *newNode = new BNode;
    newNode->data = value;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    if(root == NULL || *root == NULL)
        (*root) = newNode;

    else
    {
        BNode *cur = (*root);
        while(1)
        {
            while(cur->data > value && cur->leftNode)
                cur = cur->leftNode;
            if(cur->data > value)
            {
                cur->leftNode = newNode;
                break;
            }

            while(cur->data < value && cur->rightNode)
                cur = cur->rightNode;
            if(cur->data < value)
            {
                cur->rightNode = newNode;
                break;
            }
        }
    }
}

//中序遍历
void printTree(BNode *root)
{
    if(root == NULL)
        return;

    printTree(root->leftNode);
    cout<<root->data<<" ";
    printTree(root->rightNode);
}

BNode *findNode(BNode *root,int value,BNode **parent)
{
    if(root == NULL)
        return NULL;

    if(root->data == value)
        return root;

    queue<BNode *> nodeQueue;

    nodeQueue.push(root);

    while(!nodeQueue.empty() && nodeQueue.front()->data != value)
    {
        BNode *cur = nodeQueue.front();
        (*parent) = cur;
        if(cur->leftNode)
        {
            if(cur->leftNode->data != value)
                nodeQueue.push(cur->leftNode);
            else
                return cur->leftNode;
        }
        if(cur->rightNode)
        {
            if(cur->rightNode->data != value)
                nodeQueue.push(cur->rightNode);
            else
                return cur->rightNode;
        }
        nodeQueue.pop();
    }

    if(nodeQueue.empty())
    {
        return NULL;
    }
}

void deleteNode(BNode **root,int value)
{
    BNode *parent = NULL;
    BNode *toBeDeleted = findNode(*root,value,&parent);
    if(toBeDeleted == NULL)
    {
        cout<<"Node not exist!\n";
        return;
    }

//寻找比待删除节点小的最大节点或比待删除节点大的最小节点
    if(toBeDeleted->leftNode == NULL && toBeDeleted->rightNode == NULL)
    {
        if(parent == NULL)  //待删除节点是根节点，且其没有左右节点
            toBeDeleted = NULL;
        else
        {
            if(parent->leftNode == toBeDeleted)
                parent->leftNode = NULL;
            else
                parent->rightNode = NULL;
        }
        return;
    }

    if(toBeDeleted->leftNode)
    {
        BNode *cur = toBeDeleted->leftNode;
        BNode *prev = toBeDeleted;
        while(cur->rightNode)
        {
            prev = cur;
            cur=cur->rightNode;
        }

        if( cur == prev->leftNode )
            prev->leftNode = cur->leftNode;
        else
            prev->rightNode=cur->leftNode;

        toBeDeleted->data = cur->data;
        delete cur;
    }
    else
    {
        BNode *cur = toBeDeleted->rightNode;
        BNode *prev = toBeDeleted;

        while(cur->leftNode)
        {
            prev = cur;
            cur = cur->leftNode;
        }

        if(cur == prev->rightNode)
            prev->rightNode = cur->rightNode;
        else
            prev->leftNode = cur->rightNode;

        toBeDeleted->data = cur->data;
        delete cur;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int length = 10;
    int array[length];
    BNode *root = NULL;

    for(int i = 0;i < length; i ++)
    {
        array[i] = rand()%100;
        cout<<array[i]<<" ";
        insertNode(&root,array[i]);
    }
    cout<<"\n";
    printTree(root);
    cout<<"\n";

    int j = 0 ;
    int count = 10;
    while(j++ < 5)
    {
        int pos =rand() % count;
        count--;
        cout<<"Delete Node:"<<array[pos]<<endl;
        deleteNode(&root,array[pos]);
        printTree(root);
        cout<<"\n";
    }
    return 0;
}
