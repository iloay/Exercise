#include<iostream>
using namespace std;

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int getSize(int *array,int length)
{
    int i = 1;
    for( ; array[i] != 0 && i < length; i ++)
        ;
    return i - 1;
}

void adjustHeap(int *array,int pos)
{
    int cur = pos;
    while(cur > 1)
    {
        int par = cur / 2;
        if(array[par] < array[cur])
        {
            swap(array[par],array[cur]);
            cur = par;
            par = cur / 2;
        }
        else
            break;

    }
}

void buildMaxHeap(int *array,int length)
{
    if(array == NULL || length <= 0)
        return;

    int size = getSize(array,length);

    if(size == 0 || size == 1)
        return;
    
    for(int i = 2; i <= size ; i ++)
        adjustHeap(array,i);
}

void printHeap(int *array, int length)
{
    if( array==NULL || length <= 0 )
        return;

    for(int i = 0 ; i < length ; i ++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int *resize(int *array,int &length)
{
     int newlen = length * 2;
     int *newArray = new int[newlen];
     for(int i = 0 ; i < length ; i ++)
         newArray[i] = array[i];

     delete[] array;

     for( int i = length; i < newlen; i ++)
         newArray[i] = 0;

     length = newlen;
     return newArray;
}

int* insertNode(int *array, int &length, int value)
{
    int size = getSize(array,length);
    if( size == length - 1)
        array=resize(array,length);

    array[size+1]=value;

    cout<<"After insert node and adjust heap:";
    adjustHeap(array,size+1); 
    return array;
}

void deleteNode(int *array, int length)
{
    int size = getSize(array,length);
    if( size == 0 )
        return;
    if(size == 1 )
        array[size] = 0;

    array[1] = array[size];
    array[size] = 0;
    size --;

    int pos = 1;
    while( pos < size )
    {
        int left = pos * 2;
        int right = left + 1;

        if(left > size)
            break;

        //三种情况：第一种孩子是有两个孩子，第二种孩子是只有左孩子，第三种情况是没有孩子
        if(left <= size && right <= size)
        {
            if(array[pos] > array[left] && array[pos] > array[right])
                break;

            if(array[left] > array[right])
            {
                swap(array[left],array[pos]);
                pos = left;
            }
            else
            {
                swap(array[right],array[pos]);
                pos = right + 1;
            }
        }
        else if(left == size)
        {
            if(array[left] > array[pos])
                swap(array[left],array[pos]);
        }
        else
            break;
    }
}

int main()
{
    int length; 
    cout<<"Input length of the array:";
    cin>>length;

    int *array = new int[length];
    cout<<"Input element of the array:";
    array[0]=0;

    int i ,j;
    for(i = 1; i < length; i ++)
    {
        cin>>array[i];
        if(array[i] == 0)
            break;
    }
    
    for( j = i + 1; j < length; j ++)
        array[j] = 0;

    buildMaxHeap(array,length);
    printHeap(array,length);

//    deleteNode(array,length);
//    cout<<"Delete Root Node"<<endl;
//    printHeap(array,length);

    array=insertNode(array,length,19);
    cout<<"Insert Node 19"<<endl;
    printHeap(array,length);
    return 0;
}
