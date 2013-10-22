#include<iostream>
#include<string>
using namespace std;

void arrangeString(string s,int begin,int end)
{
    if( begin == end )
        cout<<s<<' ';
    int i = begin;
    for( int j = begin ; j < end ; j ++ )
    {
        if( i != j )
        {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
        arrangeString(s,begin+1,end);
    }
}

int main()
{
    string s;
    cin>>s;
    int len = s.length();

    arrangeString(s,0,len);
    cout<<endl;
    return 0; 
}
