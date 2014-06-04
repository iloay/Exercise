//Write code to reverse a C-Style String.(C-String means that "abcd" is repesented as five characters,including the null character.)

#include<iostream>
#include<string>
using namespace std;

void swap(char &num1,char &num2)
{
    char temp = num1;
    num1 = num2;
    num2 = temp;
}

void reverseString(char *str,int length)
{
    if(str==NULL || length <= 1)
        return;

    for(int i = 0,j = length-1; i < j; i ++,j --)
        swap(str[i],str[j]);
}

void printChar(char *str,int length)
{
    for(int i = 0; i < length; i ++)
        cout<<str[i];
    cout<<endl;
}

int main()
{
    char str[]="Hello World";
    int len=string(str).length();

    cout<<"Before reverse string:";
    printChar(str,len);
    reverseString(str,len);
    cout<<"After reverse string:";
    printChar(str,len);
    return 0;
}
