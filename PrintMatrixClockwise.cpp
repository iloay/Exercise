#include<iostream>
using namespace std;

void printMatrixClockwise(int **matrix,int m,int n)
{
    int beginX = 0;
    int beginY = 0;
    int endX = m;
    int endY = n;
    int i = 0;
    int j = 0;
    while(beginX <= endX && beginY <= endY)
    {
        while(j < endY)
            cout<<matrix[i][j++]<<" ";
        beginX ++;
        j --;
        i = beginX;
        while( i < endX)
            cout<<matrix[i++][j]<<" ";
        endY --;
        i--;
        j = endY;
        while(j  > beginY)
            cout<<matrix[i][--j]<<" ";
        endX -- ;
        i = endX;
        while( i > beginX)
            cout<<matrix[--i][j]<<" ";
        beginY ++;
        j = beginY;
    }
}
int main()
{
    int m,n;
    cout<<"Input m as row and n as column(1<=m,n<=1000):";
    cin>>m>>n;
    int **matrix;
    
    matrix = new int *[m];
    for (int i = 0 ; i < m ; i ++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n ;  j ++)
            cin>>matrix[i][j];
    }
    printMatrixClockwise(matrix,m,n);
    cout<<endl;
    return 0;
}
