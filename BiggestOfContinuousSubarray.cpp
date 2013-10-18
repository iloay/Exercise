#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Input the number of elements:";
    cin>>n;

    int array[n];
    for( int i = 0 ; i < n ; i ++ )
        cin>>array[i];

    int sumArray[n];
    sumArray[0] = array[0] ;
    for( int i = 1 ; i < n ; i ++ )
        sumArray[i] = sumArray[i-1] + array[i];

    int begin = 0;
    int end = 0;
    int max = sumArray[0];
    for ( int i = 1; i < n ; i ++ )
        if(sumArray[i] > max) 
        {
            max = sumArray[i];
            end = i ; 
        }

    for( int i = 0 ; i < n ; i ++ )
        for( int j = i+1 ; j < n ; j ++ )
        {
            if( sumArray[j] - sumArray[i] > max)
            {
                begin = i+1;
                end = j;
                max = sumArray[j] - sumArray[i];
            }
        }

    cout<<max<<' '<<begin<<' '<<end<<endl;
    return 0;
}
