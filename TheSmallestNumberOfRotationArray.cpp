#include<iostream>
using namespace std;

int findTheSmallestNumber(int array[],int n,int start,int end)
{
    while( start + 1 < end )
    {
        int mid = (start + end)/2 ;
        if( array[mid] > array[start] )
            start = mid ;
        else if ( array[mid] < array[start] )
            end = mid ;
        else
        {}
    }
    if (start + 1 == end)
        if( array[start] < array[end])
            return array[start];
        else
            return array[end];
}
int main()
{
    int n;
    cout<<"Input the numbers of the elements:";
    cin>>n;
    int array[n];
    cout<<"Input the values of array"<<endl;
    for (int i=0 ; i < n ; i++)
        cin>>array[i];
    if( array[0] < array[n-1])
    {
        cout<<"The format is Wrong."<<endl;
        return 0;
    }
    cout<<findTheSmallestNumber(array,n,0,n-1)<<endl;
    return 0;
}
