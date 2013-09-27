#include<iostream>
using namespace std;

int Fabonacci(int n)
{
    if( n == 0 )
        return 0;
    if ( n == 1 )
        return 1;
    return Fabonacci(n-1) + Fabonacci(n-2);
}
int main()
{
    int n;
    cout<<"Input a positive integer:";
    cin >> n;
    cout<<Fabonacci(n)<<endl;
    return 0;
}
