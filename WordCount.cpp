#include<stdlib.h>
#include<cstddef>
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>
using namespace std;

class WordCount
{
    public:
        void ReadDataFromFile(char *);
        void outputResult();
    private:
        void splitWord(string);
        void suffixes_s(string &);
        map<string,int> wordcount;
};

void WordCount::ReadDataFromFile(char* filename)
{
    ifstream fin(filename);
    if(!fin)
    {
        cout<<"Error opening,maybe the file is not exist!"<<endl;
        exit(-1);
    }
    string str;
    while(getline(fin,str))
        splitWord(str);
}

void WordCount::suffixes_s(string &word)
{
    string suffixes("oussisius");
    string::size_type npos=0;

    string ies("ies");
    string ses("ses");

    string::size_type len = word.size();

    if(len > 3 && !word.compare(len-1,1,"s"))
    {
        if(!word.compare(len-3,3,suffixes,npos,3) || !word.compare(len-3,3,suffixes,npos+6,3) || !word.compare(len-2,2,suffixes,npos+2,2)|| !word.compare(len-2,2,suffixes,npos+4,2) )
               ;
        else 
        {
            if( !word.compare(len-3,3,ies))
                word.replace(len-3,3,1,'y');
            else if(!word.compare(len-3,3,ses))
                word.erase(len-2,2);
            else
                word.erase(len-1);

            if(word[len-2] == '\'')
                word.erase(len-2);
        }
    }
}

void WordCount::splitWord(string str)
{
    if(str.empty())
        return;

    // transfer capital to lowercase
    string cap("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    size_t foundcap = str.find_first_of(cap);
    while(foundcap != string::npos)
    {
        str[foundcap]=str[foundcap] + 32;
        foundcap = str.find_first_of(cap,foundcap+1);
    }

    // split string into word
    string other(" ,.!?");
    size_t found = str.find_first_of(other);
    int pos=0;
    string word;

    while(found != string::npos)
    {
        word=str.substr(pos,found-pos);

        // replace word whose suffix  is "ies","ss","ses"
        // only take the word whose length is greater than 3 into account
        suffixes_s(word);

        if(!wordcount.count(word))
            wordcount.insert(pair<string,int>(word,1));
        else
            wordcount[word]++;

        pos=found+1;
        found=str.find_first_of(other,found+1);
    }

    word=str.substr(pos,found-pos);
    if(!word.empty())
    {
        suffixes_s(word);

        if(!wordcount.count(word))
            wordcount.insert(pair<string,int>(word,1));
        else
            wordcount[word]++;
    }
}

void WordCount::outputResult()
{
    map<string,int>::iterator it;
    for(it = wordcount.begin(); it != wordcount.end(); it++)
        cout<<it->first<<"  "<<it->second<<"\n";
}

int main(int argc, char *argv[])
{
    if( argc <=1 )
    {
        cout<<"Please select one file!!!";
        exit(-1);
    }
    WordCount wc;
    wc.ReadDataFromFile(argv[1]);
    wc.outputResult();
    return 0;
}
