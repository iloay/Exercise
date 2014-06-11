#include<iostream>
using namespace std;

struct BNode{
    int data;
    BNode *leftNode;
    BNode *rightNode;
};

BNode *createBTree(BNode *root)
{
    int value;
    cin>>value;
    
    if(value <= 0)
        return NULL;
    BNode *newNode = new BNode;
    newNode->data = value;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    
    if(root == NULL )
        root = newNode;
    root->leftNode = createBTree(root->leftNode);
    root->rightNode = createBTree(root->rightNode);

    return root;
}

void printBTree(BNode *root)
{
    if(root == NULL)
        return;

    BNode *cur = root;
    cout<<cur->data<<" ";
    printBTree(cur->leftNode);
    printBTree(cur->rightNode);
}

int height(BNode *root)
{
    if(root == NULL)
        return 0;

    int left = 1 + height(root->leftNode);
    int right = 1 + height(root->rightNode);
    
    return (left > right) ? left : right;
}

bool compare(BNode *root1,BNode *root2)
{
    if(root2 == NULL)
        return true;
    if(root1 == NULL)
        return false;

    if(root1->data != root2->data)
        return false;
    return compare(root1->leftNode,root2->leftNode) && compare(root1->rightNode,root2->rightNode);
}

bool isSubtree(BNode *root1,BNode *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    
    if(root2 == NULL)
        return true;

    if(root1 == NULL)
        return false;

    BNode *cur1=root1;
    BNode *cur2=root2;
    if(cur1->data == cur2->data)
        if(compare(cur1,cur2))
            return true;

    return isSubtree(cur1->leftNode,cur2) || isSubtree(cur1->rightNode,cur2);
}

int main()
{
    BNode *root1=NULL;
    root1=createBTree(root1);
    printBTree(root1);
    cout<<endl;
    cout<<"The height of the first tree:"<<height(root1)<<endl;

    BNode *root2=NULL;
    root2=createBTree(root2);
    printBTree(root2);
    cout<<endl;
    cout<<"The height of the second tree:"<<height(root2)<<endl;

    cout<<"Whether the second tree is the subtree of the first tree:"<<isSubtree(root1,root2)<<endl;
    return 0;
}
