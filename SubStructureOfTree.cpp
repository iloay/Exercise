#include<iostream>
#include<queue>
using namespace std;

typedef struct BTree
{
    int data;
    struct BTree *leftNode;
    struct BTree *rightNode;
}BTree;

bool compareTree(BTree *root1,BTree *root2)
{
    if(root2 == NULL)
        return true;
    if(root1 == NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    else
        return compareTree(root1->leftNode,root2->leftNode) && compareTree(root1->rightNode,root2->rightNode);
}

bool foundSubTree(BTree *root1,BTree *root2)
{
    bool isFound = false;
    queue<BTree *> nodeQueue;
    if(root2 == NULL)
        return true;
    if(root1 == NULL)
        return false;
    nodeQueue.push(root1);
    while( nodeQueue.empty() == false && isFound == false )
    {
        BTree *tmpNode = nodeQueue.front();
        nodeQueue.pop();
        if(tmpNode->leftNode)
            nodeQueue.push(tmpNode->leftNode);
        if(tmpNode->rightNode)
            nodeQueue.push(tmpNode->rightNode);
        if(tmpNode->data == root2->data)
            isFound = compareTree(tmpNode,root2);
    }
    return isFound;
}

BTree *createBTree(int array[],int n,BTree *root)
{
    queue<BTree *> nodeQueue;
    if(root == NULL)
    {
        root = new BTree();
        root->data = array[0];
        root->leftNode = NULL;
        root->rightNode = NULL;
    }

    nodeQueue.push(root);

    int count,index1,index2;
    int j = 0;
    while( j ++ < n)
    {
        BTree *tmpNode = nodeQueue.front();
        nodeQueue.pop();
        
        cin>>count;
        if( count == 2 )
        {
            cin>>index1>>index2;
            BTree *leftChild = new BTree();
            leftChild->data = array[index1-1];
            leftChild->leftNode = NULL;
            leftChild->rightNode = NULL;

            BTree *rightChild = new BTree();
            rightChild->data = array[index2-1];
            rightChild->leftNode = NULL;
            rightChild->rightNode = NULL;

            tmpNode->leftNode = leftChild;
            tmpNode->rightNode = rightChild;

            nodeQueue.push(leftChild);
            nodeQueue.push(rightChild);
        }
        else if(count == 1)
        {
            cin>>index1;
            BTree *leftChild = new BTree();
            leftChild->data = array[index1-1];
            leftChild->leftNode = NULL;
            leftChild->rightNode = NULL;

            tmpNode->leftNode = leftChild;

            nodeQueue.push(leftChild);
        }
        else
        {
        }
    }
    return root;
}
int main()
{
    BTree *root1 = NULL;
    BTree *root2 = NULL;

    int n,m;
    cout<<"Input the node number of two binary trees:";
    cin>>n>>m;

    int array1[n];
    for (int i = 0 ; i < n ; i ++)
        cin>>array1[i];

    root1 = createBTree(array1,n,root1);

    int array2[m];

    for( int j = 0 ; j < m ; j ++)
        cin>>array2[j];

    root2 = createBTree(array2,m,root2);

    if(foundSubTree(root1,root2))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
