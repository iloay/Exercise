// 一个字符串中连续出现次数最多的子串
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<vector>
#include<string>
#include<map>
using namespace std;

int cmp(const pair<string,int>& x,const pair<string,int>& y)
{
    if(x.second == y.second)
        return x.first.length() > y.first.length();
    return x.second > y.second;
}

void sortMap(map<string,int>& tmap,vector<pair<string,int> >& tvector)
{
    for(map<string,int>::iterator curr = tmap.begin(); curr != tmap.end(); curr ++)
        tvector.push_back(make_pair(curr->first,curr->second));

    sort(tvector.begin(),tvector.end(),cmp);
}

void occurenceNumbersofSubstring(string str)
{
    int len = str.length();
    assert(len > 0);

    map<string,int> occurNum;

    string arr[len];

    //后缀数组
    for(int i = 0 ; i < len; i ++)
        arr[i] = &str[i];

    sort(arr,arr+len);

    int i , j;
    for(i = 0,j =1; j < len; i++,j++)
    {
        int k = 0;
        while(arr[i][k] == arr[j][k])
        {
            if(occurNum.find(arr[i].substr(0,k+1)) == occurNum.end())
                occurNum.insert(make_pair(arr[i].substr(0,k+1),2));
            else
                occurNum[arr[i].substr(0,k+1)] ++;
            k++;
        }
    }

    vector<pair<string,int> > tvector;
    sortMap(occurNum,tvector);

    for(int i = 0 ; i < tvector.size(); i ++)
        cout<<tvector[i].first<<"  "<<tvector[i].second<<endl;
}

int main()
{
    string str="abdfabdcab";
    occurenceNumbersofSubstring(str);
    return 0;
}
