#include<iostream>
#include<stack>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct BNode{
    int data;
    BNode *leftNode;
    BNode *rightNode;
};

void createBTree(BNode **root,int array[],int length)
{
    if(length <= 0)
        return;

    (*root) = new BNode ;
    (*root)->data = array[0];
    (*root)->rightNode = NULL;
    (*root)->leftNode = NULL;

    int i = 1;
    while(i < length)
    {
        BNode *newNode = new BNode;
        newNode->data = array[i];
        newNode->leftNode = NULL;
        newNode->rightNode = NULL;

        BNode *cur = *root;

        while(1)
        {
            if(cur->data >= array[i])
            {
                while(cur->data >= array[i] && cur->leftNode)
                    cur = cur->leftNode;

                if(cur->data >= array[i])
                {
                    cur->leftNode = newNode;
                    break;
                }
            }

            if(cur->data <= array[i])
            {
                while(cur->data <= array[i] && cur->rightNode)
                    cur = cur->rightNode;

                if(cur->data <= array[i])
                {
                    cur->rightNode = newNode;
                    break; 
                }
            }
        }

        i++;
    }
}

//void printBTree(BNode *root)
//{
//    if(root == NULL)
//        return;
//
//    printBTree(root->leftNode);
//    cout<<root->data<<" ";
//    printBTree(root->rightNode);
//}

void printBTree(BNode *root,bool iterate)
{
    if(root == NULL)
        return;

    stack<BNode *> nodeStack;
    BNode *cur = root;

    nodeStack.push(cur);

    while(!nodeStack.empty())
    {
        while(cur->leftNode)
        {
            cur = cur->leftNode;
            nodeStack.push(cur);
        }

        if(cur->leftNode == NULL)
        {
            cout<<cur->data<<" ";
            nodeStack.pop();
        }
        
        if(cur->rightNode == NULL)
        {
            while( !nodeStack.empty() && cur->rightNode == NULL)
            {
                cur = nodeStack.top();
                cout<<cur->data<<" ";
                nodeStack.pop();
            }
        }

        if( cur->rightNode )
        {
            cur = cur->rightNode;
            nodeStack.push(cur);
        }
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int length = 5;
    
    int array[length];
    for (int i = 0 ; i < length ; i ++)
        array[i] = rand()%100;

    for (int i = 0 ; i < length ; i ++)
        cout<<array[i]<<" ";
    cout<<"\n";
    BNode *root = NULL;
    createBTree(&root,array,length);
    printBTree(root);
    cout<<"\n";
    printBTree(root,1);
    cout<<"\n";

    return 0;
}
