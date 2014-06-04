//Design an algorithm and write code to remove the serial duplicate characters in a string without using any additional buffer.

#include<iostream>
#include<string>
using namespace std;

//从后往前考虑字符串中的字符,可以减少字符串的移动
void removeDupCharacter(string &str,int len)
{
    if(str == "" || len <= 1)
        return;

    for(int i = len - 1; i >= 0 ; i --)
    {
        int j = i - 1;
        if(j >=0 && str[j] == str[i])
        {
            while(j >= 0 && str[j] == str[i])
                j--;
            str=str.replace(j+1,len-j-1,str.substr(i,len-i));
            len = len - i + j + 1;
            i = j + 1;
        }
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
