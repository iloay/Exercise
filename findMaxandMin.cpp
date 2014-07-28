//寻找数组中的最大值和最小值

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void findMaxandMin(int *arr,int begin,int end,int* max,int* min)
{
    if(begin == end)
    {
        *max = *min = arr[begin];
        return;
    }

    if(begin + 1 == end)
    {
        if(arr[begin] > arr[end])
        {
            *max = arr[begin];
            *min = arr[end];
        }
        else
        {
            *max = arr[end];
            *min = arr[begin];
        }
        return;
    }
    
    int lmax=0,lmin=0,rmax=0,rmin=0;

    int m = begin + (end - begin)/2;
    findMaxandMin(arr,begin,m,&lmax,&lmin);
    findMaxandMin(arr,m+1,end,&rmax,&rmin);

    if(rmax > lmax)
        *max = rmax;
    else
        *max = lmax;

    if(rmin > lmin)
        *min = lmin;
    else
        *min = rmin;
}

int main()
{
    srand((unsigned)time(NULL));

    int len = rand() % 10 + 1;
    int arr[len];
    
    for(int i = 0 ; i < len; i ++)
        arr[i] = rand() % 100;

    for(int i = 0 ; i < len; i ++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    int max=0, min=0;
    findMaxandMin(arr,0,len-1,&max,&min);

    cout<<"Max:"<<max<<endl;
    cout<<"Min:"<<min<<endl;
    
    return 0;
}
