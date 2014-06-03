#include<iostream>
using namespace std;

void merge(int *array,int first,int middle,int end)
{
    for( int i  = middle; i < end; i ++ )
    {
        int temp = array[i];
        int j;
        for( j = i - 1; j >= first; j -- )
        {
            if( temp < array[j] )
                array[j+1] = array[j];
            else
            {
                array[j+1] = temp;
                break;
            }
        }
        if(j < first)
            array[j+1] = temp;
    }
}

void mergesort(int *array, int first, int end)
{
    if(array == NULL || end - first <= 1)
        return;

    int middle = (end - first)/2;
    mergesort(array,first,first+middle);
    mergesort(array,first+middle,end);
    merge(array,first,first+middle,end);
}

void printarray(int *array,int length)
{
    for( int i = 0; i < length; i ++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    int length;
    cout<<"Input the length of array:";
    cin>>length;
    
    int array[length];
    cout<<"Input the elements of array:";
    for(int i = 0; i < length; i ++)
        cin>>array[i];

    cout<<"Before Sort:";
    printarray(array,length);

    mergesort(array,0,length);

    cout<<"After Sort:";
    printarray(array,length);
    return 0;
}
