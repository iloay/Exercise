#include<iostream>
using namespace std;

int coverMatrix(int n)
{
    if( n == 1 )
        return 1;
    if( n == 2 )
        return 2;
    return coverMatrix(n-1) + coverMatrix(n-2);
}

int main()
{
    int n;
    cout<<"Input a integer(1<=n<=70):";
    cin>>n;
    cout<<"The kinds of covering matrix :"<<coverMatrix(n)<<endl;
    return 0;
}
