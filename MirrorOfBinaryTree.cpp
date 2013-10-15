#include<iostream>
#include<queue>
using namespace std;

typedef struct BTree{
    int data;
    struct BTree *leftNode;
    struct BTree *rightNode;
}BTree;

BTree *createBTree(int array[],int n,BTree *root)
{
    queue<BTree *> nodeIndex;
    if(root == NULL)
    {
        root = new BTree();
        root->data = array[0];
        root->leftNode = NULL;
        root->rightNode = NULL;
    }
    nodeIndex.push(root);
    int j = 0;
    char letter;
    int value1,value2;
    while(j++ < n)
    {
        BTree *tmp = nodeIndex.front();
        nodeIndex.pop();
        cin>>letter;
        if(letter == 'd')
        {
            cin>>value1>>value2;
            BTree *leftChild = new BTree();
            leftChild->data = array[value1-1];
            leftChild->leftNode = NULL;
            leftChild->rightNode = NULL;

            BTree *rightChild = new BTree();
            rightChild->data = array[value2-1];
            rightChild->leftNode = NULL;
            rightChild->rightNode = NULL;

            nodeIndex.push(leftChild);
            nodeIndex.push(rightChild);

            tmp->leftNode = leftChild;
            tmp->rightNode = rightChild;
        }
        else if(letter == 'l')
        {
                cin>>value1;
                BTree *leftChild = new BTree();
                leftChild->data = array[value1-1];
                leftChild->leftNode = NULL;
                leftChild->rightNode = NULL;

                nodeIndex.push(leftChild);

                tmp->leftNode = leftChild; 
        }
        else if(letter == 'r')
        {
                cin>>value1;
                BTree *rightChild = new BTree();
                rightChild->data = array[value1-1];
                rightChild->leftNode = NULL;
                rightChild->rightNode = NULL;

                nodeIndex.push(rightChild);

                tmp->rightNode = rightChild; 
        }
        else
        {}
    }
    return root;
}

void transferTree2ItsMirror(BTree *root)
{
    if(root->leftNode == NULL && root->rightNode == NULL)
        return;
    else
    {
        BTree *tmp = root->leftNode;
        root->leftNode = root->rightNode;
        root->rightNode = tmp;
    }
    if(root->leftNode != NULL)
        transferTree2ItsMirror(root->leftNode);
    if(root->rightNode != NULL)
        transferTree2ItsMirror(root->rightNode);
}

void printTreePreOrder(BTree *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    printTreePreOrder(root->leftNode);
    printTreePreOrder(root->rightNode);
}

int main()
{
	int n;
	cout<<"Input the node number of binary tree:";
	cin>>n;
	int array[n];

	for(int i = 0 ; i < n ; i ++)
		cin>>array[i];

    BTree *root = NULL;
    root = createBTree(array,n,root);
    transferTree2ItsMirror(root);
    printTreePreOrder(root);

    cout<<endl;
    return 0;
}
