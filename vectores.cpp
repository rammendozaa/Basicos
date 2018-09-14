#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int aux = 0;
//	vector<vector<int> > bi(4, vector<int> (2));
	vector<vector<int> > bi(4);//(4, vector<int> (2,-1));
//	vector <int> bi;
	int i,j;
	for(i=0;i<4;i++)
	{
//	for(auto i: bi)
//	{
//		for(auto j: i)
//		{
		for(j=0;j<2;j++)
		{
			cin>>aux;
			bi[i].push_back(aux);
		//	cout<<j<<" ";
		}
		//cout<<'\n';
	}
//	bi.clear();
	for(auto i:bi)
	{
		for(auto j: i)
		{
			cout<<j<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
