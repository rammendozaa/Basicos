#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int aux, i,j;
	int numpersonas,budget,hoteles,semanas;
	int costomin,costo,costofinal, precionoche;
	while(cin>>numpersonas)
	{
		costomin = 10000000;
		cin>>budget>>hoteles>>semanas;
		vector <vector<int> > hotel(hoteles);
		for(i=0;i<hoteles;i++)
		{
			for(j=0;j<semanas+1;j++)
			{
				cin>>aux;
				hotel[i].push_back(aux);
			}
		}
		for(i=0;i<hoteles;i++)
		{
			precionoche = hotel[i][0];
			for(j=1;j<=semanas;j++)
			{
				if(hotel[i][j]>=numpersonas)
				{
					costo = precionoche * numpersonas;
					costomin = min(costo,costomin);
				}
			}
		}
		if(costomin<=budget)
			cout<<costomin<<'\n';
		else
			cout<<"stay home"<<'\n';
	}
	return 0;
}
