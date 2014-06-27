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

void BNode2DLink(BNode *root)
{
    if(root == NULL)
        return;

    BNode *cur = root;
    BNode2DLink(cur->leftNode);
    BNode2DLink(cur->rightNode);

    if(cur->leftNode)
    {
        BNode *leftNodeOfRoot = cur->leftNode;
        BNode *largestNodeofLeftTree = leftNodeOfRoot;
        while(largestNodeofLeftTree->rightNode)
            largestNodeofLeftTree = largestNodeofLeftTree->rightNode;
        
        largestNodeofLeftTree->rightNode = cur;
        cur->leftNode = largestNodeofLeftTree;

    }

    if(cur->rightNode)
    {
        BNode *rightNodeOfRoot = cur->rightNode;
        BNode *smallestNodeofRightTree = rightNodeOfRoot;

        while(smallestNodeofRightTree->leftNode)
            smallestNodeofRightTree = smallestNodeofRightTree->leftNode;

        smallestNodeofRightTree->leftNode = cur;
        cur->rightNode = smallestNodeofRightTree;

    }
}

BNode *changeBNode2DLink(BNode *root)
{
    if(root == NULL)
        return NULL;

    BNode *head = root;
    while(head->leftNode)
        head = head->leftNode;

    BNode2DLink(root);

    return head;
}

void printDLink(BNode *head)
{
    if(head == NULL)
        return;

    while(head)
    {
        cout<<head->data<<" ";
        head=head->rightNode;
    }
    cout<<"\n";
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

    BNode *head = changeBNode2DLink(root);
    cout<<"Print Double Link:\n";
    printDLink(head);
    cout<<"\n";

    return 0;
}
