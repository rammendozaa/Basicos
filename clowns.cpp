#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int casos,numero,aux,maxspeed,clownspeed;
	cin>>casos;
	for(int i=0;i<casos;i++)
	{
		maxspeed = -1;
		cin>>numero;
		vector <int> ninos(numero);
		for(int j=0;j<numero;j++)
		{
			cin>>aux;
			ninos.push_back(aux);
		}
		for(int a:ninos)
		{
			maxspeed = max(maxspeed,a);
		}
		cout<<"Case "<<i+1<<": "<<maxspeed<<'\n';
	}
	return 0;
}
