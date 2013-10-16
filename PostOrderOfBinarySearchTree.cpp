#include<iostream>
using namespace std;

bool isPostOrder(int array[],int begin,int end)
{
    if(begin == end || begin+1 == end)
        return true;
    int value = array[end];
    int i = begin;
    int j = end-1;

    while(i <= j)
    {
        if(array[i] > value)
        {
            i--;
            break;
        }
        else
            i++;
    }
    while( i <= j )
    {
        if(array[j] < value)
        {
            j++;
            break; 
        }
        else
            j--;
    }

    if( i + 1 != j )
        return false;

    return isPostOrder(array,begin,i) && isPostOrder(array,j,end-1);
}
int main()
{
    int n;
    cout<<"Input the length of array(1<=n<=10000):";
    cin>>n;
    int array[n];
    for( int i = 0 ; i < n ; i ++)
        cin>>array[i];

    bool result = isPostOrder(array,0,n-1);

    if(result)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
