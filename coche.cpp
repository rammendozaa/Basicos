#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int meses, mesesde,j;
	double pago, deuda,valorcoche,sino,auxf1,auxf2;
	while(cin>>meses)
	{
		cin>>pago>>deuda>>mesesde;
		if(meses < 0)
		{
			break;
		}
		vector <vector<float> > valores(mesesde+1);//,vector<float>(2));
		for(int i=0;i<mesesde;i++)
		{
			cin>>auxf1>>auxf2;
			valores[i].push_back(auxf1);
			valores[i].push_back(auxf2);
		}
		valores[mesesde].push_back((float)-1);
		valores[mesesde].push_back(0);
	/*	for(auto i: valores)
		{
			for(auto j:i)
				cout<<j<<" ";
			cout<<'\n';
		}*/
		valorcoche = pago + deuda;
		valorcoche = valorcoche * (1 - valores[0][1]);
		sino = valores[0][1];
		int i = 1;
		j = 1;
		while(deuda > valorcoche)
//		for(int i=0;i<meses;i++)
		{
			cout<<valores[j][0];
			if(i < (int)valores[j][0])
			{
				valorcoche = valorcoche * (1 - sino);
				deuda = deuda - pago;
				i++;	
			}
			else if(i > (int)valores[j][0])
			{
				j++;
				valorcoche = valorcoche * (1 - sino);
				deuda = deuda - pago;
				i++;
			}
			else
			{
				valorcoche = valorcoche * (1 - valores[j][1]);
				deuda = deuda - pago;
				sino = valores[j][1];
				j++;
				i++;
			}
			
			cout<<"Valor coche"<<valorcoche<<"\tDeuda"<<deuda<<"\t"<<i<<'\n';
		}

		if(i == 2)
			cout<<"1 month"<<'\n';
		else
			cout<<i-1<<" months"<<'\n';	
			
	}
	return 0;
}	
