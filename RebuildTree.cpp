#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct TreeNode
{
    int data;
    struct TreeNode *leftNode;
    struct TreeNode *rightNode;
}TreeNode;

int seq = -1; // declare global variable

TreeNode* RebuildTree(int PreOrder[],int IntOrder[],int intStart,int intEnd,int len)
{
    if( intStart == intEnd )
        return NULL;

    seq = seq + 1 ;
    
    if( seq > len )
    {
        cout<<"Out of Range"<<endl;
        exit(-1);
    }

    TreeNode* root = new TreeNode();
    root->data = PreOrder[seq];
    root->leftNode = NULL;
    root->rightNode = NULL;

    int i;
    for ( i = intStart ; i < intEnd; i++)
    {
        if( IntOrder[i] == PreOrder[seq] )
            break;
    }

    if( i == intEnd )
    {
        cout<<"No"<<endl;
        exit(-1);
    }
    
    root->leftNode = RebuildTree(PreOrder,IntOrder,intStart,i,len);
    root->rightNode = RebuildTree(PreOrder,IntOrder,i+1,intEnd,len);

    return root;
}

void OutputPostOrder(TreeNode *root)
{
    if(root==NULL)
        return;
    OutputPostOrder(root->leftNode);
    OutputPostOrder(root->rightNode);
    cout<<root->data<<"  ";
}
int main()
{
    int n;
    cout<<"Number of Node:";
    cin>>n;
    int PrevOrder[n];
    cout<<"Input Values of PrevOrder:";
    for( int i =0 ; i< n ; i++)
        cin>>PrevOrder[i];

    int IntOrder[n];
    cout<<"Input Values of IntOrder:";
    for ( int i=0 ; i<n ; i++)
        cin>>IntOrder[i];

    TreeNode *root;
    root = RebuildTree(PrevOrder,IntOrder,0,n,n);
    OutputPostOrder(root);
    return 0;
}
