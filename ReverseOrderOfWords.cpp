#include<iostream>
#include<string>
#include<stack>
using namespace std;

void reverseWords( string s )
{
    stack<string> vString;

    string temp  = s;

    int begin = 0;
    int i ;

    string subString;

    for( i = 0 ; i < temp.length() ; i ++ )
    {
        if( temp[i] == ' ')
        {
            subString = temp.substr(begin,i-begin);
            vString.push(subString);
            begin = i + 1;
        }
    }
    subString = temp.substr( begin , i - begin );
    vString.push(subString);
    

    while( ! vString.empty() )
    {
        cout<<vString.top()<<' ';
        vString.pop();
    }
    cout<<'\n';
}

int main()
{
    string s; 
    cout<<"Input string:";

    getline(cin,s);

    reverseWords(s);

    return 0;
}
