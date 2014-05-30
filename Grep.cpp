#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<dirent.h>
#include<sys/stat.h>
using namespace std;

void search(char *dir,string tobefound,string::size_type len,bool recursion)
{
    DIR *Dp;
    struct dirent *enty;
    struct stat statbuf;

    int found;

    if(NULL == (Dp = opendir(dir)))
    {
        exit(-1);
    }

    chdir(dir);

    while(NULL != (enty = readdir(Dp)))
    {
        lstat(enty->d_name,&statbuf);

        if(S_ISDIR(statbuf.st_mode) && recursion)
        {
            if(0== strcmp(".",enty->d_name) || 0 == strcmp("..",enty->d_name))
                continue;
            else
                search(enty->d_name,tobefound,len,recursion);
        }

        if(S_ISREG(statbuf.st_mode))
        {
            char* filename = enty->d_name;
            ifstream fin(filename);
            if(!fin)
            {
                cerr<<"Error opening file:"<<filename<<"\n";
                continue;
            }
            string str;
            while(getline(fin,str))
            {
                found = str.find(tobefound,0);
                if(found != string::npos)
                    cout<<string(getcwd(NULL,0)).substr(len)<<"/"<<filename<<":"<<str<<"\n";
            }
        }
    }
}

int main(int argc,char *argv[])
{
    char *str;
    char *dir;
    bool recursion=false;

    if(argc == 4)
    {
        if(argv[1][0]=='-')
            if(argv[1][1]=='R' || argv[1][1]=='r')
                recursion=true;
        str=argv[2];
        dir=argv[3];
    }
    else if(argc == 3)
    {
        str=argv[1];
        dir=argv[2];
    }
    else
    {
        cerr<<"Needs more arguments,please check!!!\n";
        exit(-1);
    }

    if(0==strcmp(str,"."))
        str=getcwd(NULL,0);

    string tobefound(str);

    string::size_type len=string(getcwd(NULL,0)).size();
    search(dir,tobefound,len,recursion);
    return 0;
}
