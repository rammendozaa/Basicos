#include <iostream>
#include <vector>
using namespace std;
int numveces(vector <vector <int> > matriz)
{
	int contador = 0;
	{
		



	return contador;
}



int main()
{
	int casos,i,j,aux,veces;
	cin>>casos;
	vector <vector <int> > matrices(3);
	while(casos-1>=0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				cin>>aux;
				matrices[i].push_back(aux);
			}
		}
		casos--;	
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<matrices[i][j]<<" ";
		}
		cout<<'\n';
	}
		veces = numveces(matrices);
		cout<<veces<<'\n';
		
	return 0;
}