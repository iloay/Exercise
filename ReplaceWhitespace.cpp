#include<iostream>
#include<string>
using namespace std;

int main()
{
    string strtmp;
    string strmatch="";

    cout<<"Please input string:";
    getline(cin,strtmp);

    int strlen = strtmp.size();
    int prev = 0,i = 0;
    for (i = 0 ; i< strlen ; i++)
    {
        if(strtmp[i]==' ')
        {
            strmatch.append(strtmp,prev,i-prev);
            strmatch.append("%20",0,3);
            prev = i+1;
        }
    }
    strmatch.append(strtmp,prev,i-prev);
    cout<<strmatch<<endl;
    return 0;
}
