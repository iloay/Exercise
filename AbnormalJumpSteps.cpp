//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶....它可以跳上n级台阶。求该青蛙跳上一个n级台阶总共有多少种跳法。
//
//
#include<iostream>
using namespace std;

int jumpSteps(int n)
{
    if(n == 1)
        return 1;
    return 2 * jumpSteps(n-1);
}

int main()
{
    int n;
    cout<<"Input a integer(1<=n<=50):";
    cin>>n;
    
    cout<<"The kind of jump is :"<<jumpSteps(n)<<endl;
    return 0;
}
