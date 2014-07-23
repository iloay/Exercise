#include<iostream>
#include<string>
using namespace std;

int String2Int(char* str)
{
    static const int MAX_INT = (int)((unsigned)~0>>1);
    static const int MIN_INT = -(int)((unsigned)~0>>1)-1;
    char *p = str;

    int n = 0;
    int flag = 1;

    while( *p != '\0' && *p == ' ')
        p++;

    if(*p != '\0' && (*p == '-' || *p == '+'))
    {
        if( *p == '-')
            flag = -1;
        p++;
    }

    while(isdigit(*p))
    {   
        if(flag > 0 && ((n == MAX_INT / 10 && *p > MAX_INT % 10) || n > MAX_INT / 10))
        {
            n = MAX_INT;
            return n;
        }
        else if( flag < 0 && ((n == unsigned(MIN_INT) / 10 && *p > MAX_INT % 10) || n > (unsigned)MAX_INT / 10))
        {
            n = MIN_INT;
            return n;
        }
        n = n * 10 + (*p - '0');
        p++;
    }

    return (flag > 0) ? n : -n; 
}

int main()
{
    char str[] = "1231239123123";
    int n = String2Int(str);
    cout<<n<<endl;
    return 0;
}
