#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

void swap(int &num1,int &num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int randomselect(int length,int start)
{
    srand(time(NULL));
    return rand()%length + start;
}

void QuickSort(int *array,int start,int finish)
{
    if( array==NULL || start<0 || finish<0 || start >= finish)
        return;

    int length = finish - start + 1;
    int index=randomselect(length,start);
    if(index != finish)
        swap(array[index],array[finish]);

    int begin = start;
    int end = finish-1;
    
    while(begin < end)
    {
        while(begin < end && array[begin]<=array[finish])
            begin++;
        while(begin < end && array[end]>array[finish])
            end--;
        if(begin < end)
            swap(array[begin],array[end]);
    }

    if(array[end] > array[finish])
    {
        swap(array[end],array[finish]);
        QuickSort(array,start,end-1);
        QuickSort(array,end+1,finish);
    }
    else
    {
        QuickSort(array,start,end);
        QuickSort(array,end+2,finish);
    }
}

void printArray(int *array,int length)
{
    if( array == NULL || length <= 0 )
        return;
    for(int i = 0 ; i < length; i ++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    int length;
    cout<<"Input array length:";
    cin>>length;
    int array[length];
    cout<<"Input array elements:";
    for(int i = 0 ; i < length; i++)
        cin>>array[i];
    cout<<"Before sort:\n";
    printArray(array,length);
    QuickSort(array,0,length-1);
    cout<<"After sort:\n";
    printArray(array,length);
    return 0;
}
