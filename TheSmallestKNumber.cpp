#include<iostream>
using namespace std;

void sort( int array[], int begin,int end)
{
    int len = end;
    while( end > begin )
    {
        for( int i = begin; i+1 < end ; i ++ )
        {
            if(array[i ] > array[i+1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        end --;
    }
    for ( int j = 0 ; j < len ; j ++)
        cout<<array[j]<<' ';
    cout<<endl;
}

int quickSort(int array[], int begin, int end)
{
    int i = begin;
    int j = end;
    while( i < j )
    {
        while( i < j && array[i] < array[j] )
            j--;
        if( i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        while( i < j && array[i] < array[j] )
            i++;
        if(i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    return i;
}

void findKSmallestNumbers(int array[],int n,int k)
{
    int index = quickSort(array,0,n-1);
    while ( index+1 != k )
    {
        if( index+1 < k )
        {
            index = quickSort(array,index + 1, n-1);
            k = k - index-1;
        }
        else
            index = quickSort(array,0,index);
    }

    if(index+1 == k)
        sort(array,0,k);
}

int main()
{
    int n,k;
    cout<<"input n and k:";
    cin>>n>>k;

    if( n < k )
        cout<<"Out Of Range!"<<endl;

    int array[n];
    for( int i = 0; i < n; i ++ )
        cin>>array[i];

    if(n == k)
        sort( array, 0, n);

    findKSmallestNumbers(array,n,k);
    cout<<endl;

    return 0;
}
