#include<iostream>
using namespace std;

typedef struct LinkNode
{
	int data;
	struct	LinkNode *next;
}LinkNode;

void printLink(LinkNode *head)
{
    LinkNode *tmp = head;
    while(tmp)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
LinkNode *createLink(LinkNode* head,int array[],int n)
{
    head->data = array[0];
    head->next = NULL;
    LinkNode *tail = head ;
    int m = 1;
    while (m<n)
    {
		LinkNode *newNode = new LinkNode();
		newNode->data = array[m++];
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
    }
	return head;
}

LinkNode* combineLink(LinkNode* head1,LinkNode* head2,LinkNode *head)
{
	LinkNode *tail;

	if(head1 == NULL && head2 == NULL)
		return NULL;
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	LinkNode *tmp1 = head1;
	LinkNode *tmp2 = head2;
	while( tmp1 != NULL && tmp2 != NULL)
	{
		LinkNode *newNode;
		if(tmp1->data < tmp2->data)
		{
			newNode = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			newNode = tmp2;
			tmp2 = tmp2->next;
		}
		if(head==NULL)
		{
			head = tail = newNode;
			tail->next = NULL;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
			tail->next = NULL;
		}
	}
	if( tmp1 == NULL && tmp2 != NULL )
	{
		tail->next = tmp2;
	}
	else if (tmp1 != NULL && tmp2 == NULL)
	{
		tail->next = tmp1;
	}
	else
	{
	}
	return head;
}
int main()
{
	int n,m;
	cout<<"N,M:";
	cin>>n>>m;

    int array1[n];
    int array2[m];
    for ( int i = 0 ; i < n ; i ++)
        cin>>array1[i];
    for (int j = 0; j < m ; j ++)
        cin>>array2[j];
    LinkNode *head1 = new LinkNode();
    LinkNode *head2 = new LinkNode();
	head1 = createLink(head1,array1,n);
	head2 = createLink(head2,array2,m);
	LinkNode *head = NULL;
    head = combineLink(head1,head2,head);

	LinkNode *tmp = head;
	while( tmp )
	{
		cout<< tmp->data <<" ";
		tmp = tmp->next;
	}
	cout<<endl;
	return 0;
}
