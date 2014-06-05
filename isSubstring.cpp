#include<iostream>
#include<string>
using namespace std;

void isSubstring(string &str1,string &substr2)
{
    int len1 = str1.length();
    int len2 = substr2.length();
    if(len1 < len2 || len1 <= 0 || len2 <= 0)
    {
        cout<<"False"<<endl;
        return;
    }

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
    while( i < len1)
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
            {
                cout<<"True"<<endl;
                break;
            }

            if(j < jump || jump == -1)
                k = k + j - 1;
            else
                k = k + jump - 1 ;
        }
        i = k;
    }

    if( j < len2 )
        cout<<"False"<<endl;
}

int main()
{
    string str1;
    string str2;

    cout<<"Input string1 and string2 seperately"<<endl;
    cin>>str1;
    cin>>str2;

    isSubstring(str1,str2);
    return 0;
}
