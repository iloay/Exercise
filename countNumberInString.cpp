#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

char * countNumber(string str)
{
    int len = str.length();
    char *array = new char[len * 2 + 1];
    char *sub = new char[3];

    int count = 1;
    for( int i = 0 ; i < len - 1 ; i ++)
    {
        if(str[i] == str[i + 1])
            count ++;
        else
        {
            sprintf(array,"%s%c%d",array,str[i],count);
            count = 1;
        }
    }

    return array;
}

int main()
{
    string str="12333223912298999";
    char *result = countNumber(str);
    cout<<str<<"\n";
    cout<<result<<"\n";
    return 0;
}
