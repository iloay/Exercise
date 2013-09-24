#include<iostream>
using namespace std;

int main()
{
    int m,n,t;
    cout<<"m as row and n as column(1<=m,n<=1000):";
    cin>>m>>n;
    cout<<"Input value you want to find(1<=t<=1000000):";
    cin>>t;
    int array[m][n];
    cout<<"Two dimension array is:"<<endl;
    for (int i=0 ; i<m ; i++)
        for(int j=0; j<n ; j++)
            cin>>array[i][j];
    int i,j;
    bool isFound = false ;
    for (i = 0; i < m ; i++)
    {
        if( array[i][0] == t )
            isFound = true ;
        else if(array[i][0] > t)
            break;
    }

    if( isFound == false)
    {
        for (j = 1 ,i = i - 1; j < n && i > 0 ; j++)
        {
            if(array[i][j] > t)
            {
                i = i - 1;
                j = j - 2;
            }
            if(array[i][j] == t)
            {
                isFound = true;
                break;
            }
        }
    }

    if(isFound == true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
