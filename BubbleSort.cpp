#include<iostream>
using namespace std;

void swap(int &num1,int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void BubbleSort(int *array,int length,int &count)
{
    if( array == NULL || length <=0 )
        return;
    int end = length;
    while( end > 0)
    {
        int index = 0;
        for ( int i = 0 ; i < end-1 ; i ++ )
        {
            if( array[i] > array[i+1] )
            {
                swap(array[i],array[i+1]);
                index = i + 1 ;
                count ++;
            }
        }
        end = index;
    }
}

void printArray(int *array, int length)
{
    if( array == NULL || length <=0 )
        return;
    for( int i = 0 ; i < length ; i ++ )
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int count = 0; //Swap Count
    int length;
    cout<<"Input the length of the array:";
    cin>>length;
    
    int array[length];
    cout<<"Input the array element:";
    for(int i = 0; i < length; i++)
        cin>>array[i];

    cout<<"Before Sort:";
    printArray(array,length);

    BubbleSort(array,length,count);
    cout<<"After Sort:";
    printArray(array,length);

    cout<<"In Bubble Sort,the swap count between element is:"<<count<<endl;
    return 0;
}
