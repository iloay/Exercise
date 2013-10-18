#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef struct BTree{
    int data;
    struct BTree *leftNode;
    struct BTree *rightNode;
    bool hasVisited;
}BTree;

BTree *createBTree(int matrix[][3],int n,BTree *root)
{
    queue<BTree *> nodeQueue;

    if(root == NULL)
    {
        root = new BTree();
        root->data = matrix[0][0];
        root->leftNode = NULL;
        root->rightNode = NULL;
        root->hasVisited = false;
    }

    nodeQueue.push(root);
    int j = 0;

    while(!nodeQueue.empty() && j < n)
    {
        BTree *tmpNode = nodeQueue.front();
        nodeQueue.pop();

        if(matrix[j][1] != -1)
        {
            int index = matrix[j][1] - 1;
            BTree *leftChild = new BTree();
            leftChild->data = matrix[index][0];
            leftChild->leftNode = NULL;
            leftChild->rightNode = NULL;
            leftChild->hasVisited = false;

            nodeQueue.push(leftChild);

            tmpNode->leftNode = leftChild;
        }

        if(matrix[j][2] != -1)
        {
            int index = matrix[j][2]-1;
            BTree *rightChild = new BTree();
            rightChild->data = matrix[index][0];
            rightChild->leftNode = NULL;
            rightChild->rightNode = NULL;
            rightChild->hasVisited = false;

            nodeQueue.push(rightChild);

            tmpNode->rightNode = rightChild;
        }
        j++;
    }
    return root;
}

void findPath(BTree *root,int k)
{
    if( root == NULL )
        return;
    vector<BTree *> nodeVector;
    nodeVector.push_back(root);
    int sum = root->data;
    root->hasVisited = true;
    while( !nodeVector.empty() )
    {
        while( sum < k && !nodeVector.empty())
        {
            BTree *tmpNode = nodeVector.back();
            while( sum < k )
            {
                while( sum < k && tmpNode->leftNode && !tmpNode->leftNode->hasVisited )
                {
                    BTree *newNode = tmpNode->leftNode;
                    tmpNode->leftNode->hasVisited = true;
                    sum += newNode->data;
                    nodeVector.push_back(newNode);
                    tmpNode = newNode;
                }

                if(sum < k)
                {
                    if( tmpNode->rightNode && !tmpNode->rightNode->hasVisited )
                    {
                        BTree *newNode = tmpNode->rightNode;
                        tmpNode->rightNode->hasVisited = true;
                        sum += newNode->data;
                        nodeVector.push_back(newNode);
                        tmpNode = newNode;
                    }
                    else
                        break;
                }
            }

            if( sum == k && !tmpNode->leftNode && !tmpNode->rightNode )
            {
                cout<<"a path is found:";
                for ( vector<BTree *>::iterator it = nodeVector.begin(); it != nodeVector.end() ; ++it )
                    cout<<' '<< (*it)->data;
                cout<<"\n";
            }

            sum -= nodeVector.back()->data;
            nodeVector.pop_back();
        }
    }
}

int main()
{
    int n,k;
    cout<<"Input the node number and the sum:";
    cin>>n>>k;
    int matrix[n][3];
    for(int i = 0; i < n ; i ++)
        for(int j = 0 ; j < 3; j++)
            cin>>matrix[i][j];

    BTree *root = NULL;
    root = createBTree(matrix,n,root);

    cout<<"result:\n";
    findPath(root,k);

    return 0;
}
