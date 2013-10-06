#include<iostream>
using namespace std;
int power(int base,int exponent)
{
	int result = 1;
	for (int i = 0;i < exponent ; i++)
		result *= base;
	return result;
}
int main()
{
	int N;
	cout<<"Input N(1<=N<=5):";
	cin>>N;
	if (N<1 || N> 5)
	{
		cout<<"Out of Range"<<endl;
		return -1;
	}
	int max = power(10,N);
	for (int i = 1; i< max ; i++)
		cout<<i<<endl;
	return 0;
}
