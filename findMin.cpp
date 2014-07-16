#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
using namespace std;

bool findMin(int **array,int row,int column,int toBeFound)
{
    assert(row > 0 && column > 0);

    int i = 0, j = column - 1;

    while(i < row && j >= 0)
    {
        while( i < row && j >= 0 && array[i][j] < toBeFound)
            i++;
        while( i < row && j >= 0 && array[i][j] > toBeFound)
            j--;
        if(array[i][j] == toBeFound)
            return true;
    }
    return false;
}

int main()
{
   srand((unsigned)time(NULL)); 
   int **array;
   int row,column;
   cout<<"Input the row:";
   cin>>row;
   cout<<"Input the coloumn:";
   cin>>column;

   assert(row > 0 && column > 0);

   array = new int*[row];
   assert(array);

   for(int i = 0 ; i < row; i ++ )
       array[i] = new int[column];

   for(int i = 0 ; i < row; i ++)
       for(int j = 0 ; j < column; j ++)
           cin >> array[i][j];

   int toBeFound;
   cout<<"Input data to be found:";
   cin>>toBeFound;
   
   cout<<"Whether exist:"<<findMin(array,row,column,toBeFound)<<endl;
   return 0;
}
