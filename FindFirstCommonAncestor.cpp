//Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree.Avoid storing additional nodes in a data structure.

#include<iostream>
#include<stack>
using namespace std;

struct BNode{
    int data;
    BNode *leftNode;
    BNode *rightNode;
};

static bool isFound = false;

void findThePathOfNode(BNode *root,BNode* node,stack<BNode *>& path)
{
    if(isFound)
        return;
    if(root == NULL)
        return;

    BNode *cur=root;
    path.push(cur);

    if(cur->data == node->data)
        isFound = true;

    if(!isFound)
        findThePathOfNode(cur->leftNode,node,path);
    if(!isFound)
        findThePathOfNode(cur->rightNode,node,path);

    if(!path.empty() && !isFound)
        path.pop();
}

BNode *findTheCommonAncestor(BNode *root,BNode* node1,BNode *node2)
{
    if(root == NULL)
        return NULL;

    stack<BNode *>path1;
    isFound = false;
    findThePathOfNode(root,node1,path1);

    stack<BNode *>path2;
    isFound = false;
    findThePathOfNode(root,node2,path2);

    if(path1.size() > path2.size())
    {
        int dist = path1.size() - path2.size();
        while(dist --)
            path1.pop();
    }
    else if(path1.size() < path2.size())
    {
        int dist = path2.size() - path1.size();
        while(dist --)
            path2.pop();
    }
    else
        ;

    while(!path1.empty() && !path2.empty())
    {
        if(path1.top() == path2.top() )
            break;

        path1.pop();
        path2.pop();
    }

    return path1.top();
}

int height(BNode *root)
{
    if(root==NULL)
        return 0;

    BNode *cur = root;
    int left = 1 + height(cur->leftNode);
    int right = 1 + height(cur->rightNode);

    return (left > right)?left : right;
}

void printBTree(BNode *root)
{
    if(root==NULL)
        return;

    BNode *cur = root;
    cout<<cur->data<<" ";
    printBTree(cur->leftNode);
    printBTree(cur->rightNode);
}

BNode* createBTree(BNode *root)
{
    int value;
    cin>>value;
    
    if(value <= 0)
        return NULL;

    BNode *newNode = new BNode;
    newNode->data = value;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    if(root == NULL)
        root=newNode;

    root->leftNode = createBTree(root->leftNode);
    root->rightNode = createBTree(root->rightNode);

    return root;
}

int main()
{
    BNode *root = NULL;
    root = createBTree(root);
    cout<<"Height:"<<height(root)<<endl;
    printBTree(root);
    cout<<endl;

    BNode *node1 = new BNode ;
    node1->data = 4;
    node1->leftNode = NULL;
    node1->rightNode = NULL;

    BNode *node2 = new BNode;
    node2->data = 3;
    node2->leftNode = NULL;
    node2->rightNode = NULL;

    BNode *com=findTheCommonAncestor(root,node1,node2);
    cout<<"The common ancestor of node1 and node2 is:"<<com->data<<endl;
    return 0;
}
