#include<iostream>
using namespace std;

void adjustArray(int array[],int n)
{
	int i = n - 1;
    int j = n - 1 ;
	while( j >= 0 && array[j]%2 == 0)
		j--;	
	i = j ;
	while(j >= 0 && i >= 0)
	{
		if( i >= 0 )
		{
			i = i - 1;
			while(i >= 0 && array[i]%2 == 1)
				i--;
		}
		else
			break;
		if(i>=0)
		{
			int tmp = array[i];
            for (int k = i ; k < j ; k ++)
            {
                array[k] = array[k+1];
            }
			array[j] = tmp;
			j--;
			i--;
		}
	}
	for (int k = 0 ; k<n ; k++)
		cout<<array[k]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Input n:"<<endl;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
		cin>>array[i];
	adjustArray(array,n);
	return 0;
}
