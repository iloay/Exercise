#include<iostream>
#include<queue>
using namespace std;

typedef struct BTree{
    int data;
    struct BTree *leftNode;
    struct BTree *rightNode;
}BTree;

BTree *createBTree(int array[],int n,int matrix[][2],BTree *root)
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
    while(j < n)
    {
        if(matrix[j][0] != 0 || matrix[j][1] != 0)
        {
            BTree *tmp = nodeIndex.front();
            nodeIndex.pop();
            if(matrix[j][0] != 0 && matrix[j][1] != 0)
            {
                BTree *leftChild = new BTree();
                leftChild->data = array[matrix[j][0]-1];
                leftChild->leftNode = NULL;
                leftChild->rightNode = NULL;

                BTree *rightChild = new BTree();
                rightChild->data = array[matrix[j][1]-1];
                rightChild->leftNode = NULL;
                rightChild->rightNode = NULL;

                nodeIndex.push(leftChild);
                nodeIndex.push(rightChild);

                tmp->leftNode = leftChild;
                tmp->rightNode = rightChild;
            }
            else if(matrix[j][0] != 0)
            {
                BTree *leftChild = new BTree();
                leftChild->data = array[matrix[j][0]-1];
                leftChild->leftNode = NULL;
                leftChild->rightNode = NULL;

                nodeIndex.push(leftChild);

                tmp->leftNode = leftChild; 
            }
            else
            {
                BTree *rightChild = new BTree();
                rightChild->data = array[matrix[j][1]-1];
                rightChild->leftNode = NULL;
                rightChild->rightNode = NULL;

                nodeIndex.push(rightChild);

                tmp->rightNode = rightChild; 
             }
        }
        else
            nodeIndex.pop();
        j++;
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
    int matrix[n][2];
    for (int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < 2; j ++)
            matrix[i][j]=0;

	for(int i = 0 ; i < n ; i ++)
		cin>>array[i];
    char letter;
    int j = 0;
    while(j < n)
    {
        cin >> letter;
        switch(letter)
        {
            case 'd':
                cin>>matrix[j][0]>>matrix[j][1];
                break;
            case 'r':
                cin>>matrix[j][1];
                break;
            case 'l':
                cin>>matrix[j][0];
                break;
            case 'z':
                break;
        }
        j++;
    }

    BTree *root = NULL;
    root = createBTree(array,n,matrix,root);
    transferTree2ItsMirror(root);
    printTreePreOrder(root);

    cout<<endl;
    return 0;
}
