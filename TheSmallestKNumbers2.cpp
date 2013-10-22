#include<iostream>
using namespace std;

void realizeSmallHeap( int array[] , int n )
{
    int pos = n / 2;
    
    while( pos > 0 )
    {
        int temp = pos ;

        while( pos <= n )
        {
            int left = 2 * pos;
            int right = left + 1;

            int next = pos ;
            if( left <= n )
            {
                if( array[left] < array[next])
                {
                    next = left;
                }
            }
            if(right <= n )
            {
                if( array[right] < array[next])
                {
                    next = right;
                }
            }

            if( next == pos)
                break;
            else
            {
                int temp = array[pos];
                array[pos] = array[next];
                array[next] = temp;

                pos = next;
            }
        }

        pos --;
    }
}

int main()
{
    int n;
    cout<<"Input n and k(1<=n<=200000):";
    cin>>n;
    int k;
    cin>>k;

    if( n <=0 || n> 200000)
    {
        cerr<<"Out of Range!"<<endl;
        return -1;
    }

    int array[n+1];

    for(int i = 1 ; i < n+1 ; i ++)
        cin>>array[i];
    array[0]=0;

    for ( int i = 0 ; i < k ; i ++ , n--)
    {
        realizeSmallHeap(array,n);
        cout<<array[1]<<' ';
        array[1] = array[n];
    }
    cout<<endl;

    return 0;
}
