#include<iostream>
using namespace std;

void swap(int &num1,int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void insertSort(int *array,int length, int interval)
{
    int i , j , k;
    for( i = 0; i < interval ; i ++ )
    {
        for( j = i + interval; j < length ; j = j + interval )
        {
            int temp = array[j];
            for( k = j - interval ; k >= 0 ; k = k - interval )
            {
                if(array[k] > temp)
                    array[k+interval] = array[k];
                else
                {
                    if( k != j - interval)
                        array[k+interval] = temp;
                    break;
                }
            }
            if( k < 0 )
                array[k+interval] = temp;
        }
    }
}


void printArray(int *array,int length)
{
    for( int i = 0; i < length; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

void shellSort(int *array, int length)
{
    if(array==NULL || length <= 1)
        return;

    if( length == 2)
    {
        if(array[0] > array[1])
            swap(array[0],array[1]);
        return;
    }

    int interval = length / 2; 
    int count = 0;
    while(interval>=1)
    {
        insertSort(array,length,interval);

        count ++;
        cout<<"第"<<count<<"趟\n";
        printArray(array,length);

        interval = interval / 2;
    }
}

int main()
{
    int length;
    cout<<"Input the length of array:";
    cin>>length;

    int array[length];
    cout<<"Input the element of array:";
    for( int i = 0 ; i < length; i ++)
        cin>>array[i];

    cout<<"Before sort:";
    for ( int i = 0 ; i < length ; i ++ )
        cout<<array[i]<<" ";
    cout<<endl;

    shellSort(array,length);

    cout<<"After sort:";
    for( int i = 0 ; i < length; i ++)
        cout<<array[i]<<" ";
    cout<<endl;
    return 0;
}
