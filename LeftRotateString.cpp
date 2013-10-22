#include<iostream>
#include<string>
using namespace std;

void _leftRotate( string &s, int k)
{
    int len = s.length();
    string temp = s.substr(0,k);
    s = s.substr(k,len - k);
    s.append(temp);

    cout<<s<<'\n';
}

void leftRotate(string s, int k)
{
    int len = s.length();
    while( k > len)
        k = k - len;

    if( k < 0)
    {
        cerr<<"Out Of Range!"<<endl;
        return;
    }

    _leftRotate(s,k);

}
int main()
{
    string s;
    cin>>s;

    int k;
    cin>>k;

    leftRotate(s,k);

    return 0;
}
