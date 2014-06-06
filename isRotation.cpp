//Assume you have a method isSubstring which checks if one word is a substring of another.Given two string,s1 and s2,write code to check if s2 is a rotation of s1 using only one call to isSubstring.

#include<iostream>
#include<string>
using namespace std;

bool isSubstring(string str1,string substr2)
{
     int len1 = str1.length();
    int len2 = substr2.length();
    if(len1 < len2 || len1 <= 0 || len2 <= 0)
        return false;

    //至多一次可以跳跃的步数
    int jump = -1;
    for(int i = 1; i < len2; i ++)
    {
         if(substr2[i] == substr2[0])
        {
            jump=i;
            break;
        }
    }

    int i = 0;
    int j = 0;
    int k = 0;
    while( i <= len1 - len2)
    {
        k = i + 1;
        j = 0;
        if(str1[i] == substr2[j])
        {
            while( i < len1 && j < len2 )
            {
                if(str1[i] != substr2[j])
                    break;
                i++;
                j++;
            }
            if(j == len2)
                return true;

            if(j < jump || jump == -1)
                k = k + j - 1;
            else
                k = k + jump - 1 ;
        }
        i = k;
    }

    if( j < len2 )
        return  false;
}

bool isRotation(string &str1,string &str2)
{
    if( str1.length() != str2.length() || str1.length() == 0 )
        return false;
    return isSubstring(str1.append(str1),str2);
}

int main()
{
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;

    cout<<isRotation(str1,str2)<<endl;
    return 0;
}
