#include<iostream>
using namespace std;

char* replaceSpaces(char *str)
{
    int len = 0;
    int spaces = 0;
    for(; str[len] !='\0'; len++)
    {
        if(str[len] == ' ')
            spaces ++;
    }

    if(len <= 0 || spaces <= 0)
        return str;

    char *newstr=new char[len + 2 * spaces];

    int i = 0;
    int j = 0;

    while(i<len)
    {
        if(str[i] != ' ')
            newstr[j++] = str[i++];
        else
        {
            newstr[j++]='%';
            newstr[j++]='2';
            newstr[j++]='0';
            i++;
        }
    }
    newstr[j]='\0';

    return newstr;
}

int main()
{
    char s[]="Hello World";
    cout<<"Before replace:"<<s<<endl;

    cout<<"After replace:"<<replaceSpaces(s)<<endl;
    return 0;
}
