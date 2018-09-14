#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,aux1,aux2,enmedio;
	cin>>n;
	vector <int> num(3);
	for(i=0;i<n;i++)
	{
	cin>>num[0]>>num[1]>>num[2];
	sort(num.begin(),num.end());
	cout<<"Case "<<i+1<<": "<<num[1]<<'\n';
	}
	return 0;
}
