#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;

    if( s.length() == 0 )
        return -1;

    map<char,int> mapChar;
    for( int i = 0 ; i < s.length() ; i ++)
        mapChar[s[i]] ++ ;

    for(map<char,int>::iterator ite = mapChar.begin() ; ite != mapChar.end() ; ite ++)
        if( ite->second == 1)
        {
            cout<<ite->first<<endl;
            break;
        }
    return 0;
}
