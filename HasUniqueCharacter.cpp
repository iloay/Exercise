//Implement an algorithm to determine if a string has all unique characters.What if you can not use additional data structure?
#include<iostream>
#include<string>
using namespace std;

#define NUMBER 1
void set1(int* bit,int offset)
{
    (*bit) = (*bit) | (NUMBER << offset);
}

bool ifunique(int* bit,int offset)
{
    if((*bit) & (NUMBER<<offset))
        return false;
    else
        return true;
}

int main()
{
    cout<<"Input string:";
    string str;
    cin>>str;

    int bitInt=0;
    int bitCap=0;
    int bitLower=0;
    int *bit;
    int len=str.length();
    if(len == 0)
    {
        cout<<"Empty String!"<<endl;
        return 0;
    }

    int i;
    int offset;
    for(i = 0; i < len; i ++)
    {
        if( str[i] >= 48 && str[i] <= 57 ) //数字'1234567890'
        {
            offset=str[i];
            bit=&bitInt;
        }
        else if(str[i] >= 65 && str[i] <= 90) //'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        {
            offset=str[i]-16;
            bit=&bitCap;
        }
        else
        {
            offset=str[i]-49; // 'abcdefghijklmnopqrstuvwxyz'
            bit=&bitLower;
        }
        if(!ifunique(bit,offset))
        {
            cout<<"Non Unique!"<<endl;
            break;
        }
        else
            set1(bit,offset);
    }
    if(i == len)
        cout<<"Unique!"<<endl;
    return 0;
}
