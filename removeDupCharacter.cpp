//Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.

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

void removeDupCharacter(string &str,int len)
{
    if(str == "" || len <= 1)
        return;

    int bitCap=0;
    int bitLower=0;
    int *bit;
    
    int offset;

    for( int i = 0 ; i < len; i ++)
    {
        if(str[i] >= 65 && str[i] <= 90)
        {
            offset = str[i] - 16;
            bit=&bitCap;
        }
        else
        {
            offset = str[i] - 49;
            bit = &bitLower;
        }
        if(!ifunique(bit,offset))
        {
            if(i<len-1)
            {
                len --;
                str = str.replace(i,len-i,str.substr(i+1,len-i-1));
                i--;
            }
            else
                str = str.erase(i);
        }
        else
            set1(bit,offset);
    }
}

int main()
{
    string str;
    cout<<"Input String:";
    cin>>str;
    int len = str.length();
    
    cout<<"Before Remove Duplicate Character:";
    cout<<str<<endl;

    removeDupCharacter(str,len);

    cout<<"After Remove Duplicate Character:";
    cout<<str<<endl;
    
    return 0;
}
