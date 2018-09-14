#include <iostream>
#include <vector>
using namespace std;
int main()
{
	double aux1,aux2;
	double aux;
	double costo, deuda;
	int posaux;
	double precio;
	vector <double> car(4,-1);
	for(int i = 0; i<4; i++)
	{
		cin>>aux;
		car[i] = aux;
	}
	vector <vector <double>> costos(car[3]);
	for(int i = 0; i<car[3]; i++)
	{
		cin>>aux1>>aux2;
		costos[i].push_back(aux1);
		costos[i].push_back(aux2);
	}
	for(int i = 0; i<4; i++)
		cout<<car[i]<<" ";
	for(int i = 0; i<car[3]; i++)
		cout<<costos[i][0]<<" "<<costos[i][1]<<'\n';
	precio = car[1] + car[2];
	posaux = 0;
	int j = 0;
	deuda = car[2];
	for(int i = 0; i<car[0]; i++)
	{
		if(j < costos[car[3]-1][0])// && i == costos[j][0])
		{	
			if(i == 0)
			{
				precio = precio * (1 - costos[j][1]);	
				j++;
			}
			else if(i == costos[j][0])
			{
				cout<<i<<" ";
				cout<<costos[j][0]<<'\n';
				precio = precio * (1 - costos[j][1]);
				cout<<(1- costos[j][1])<<'\n';
				posaux = j;	
				j++;
			}
			else if(i > costos[j][0])
			{
				cout<<i<<" ";
				precio = precio * (1 - costos[j][1]);
				cout<<(1- costos[j][1])<<'\n';
				posaux = j;	
				j++;
			}
			else
				precio = precio * (1 - costos[posaux][1]);
		}
		else
			precio = precio * (1 - costos[car[3]-1][1]);
		if(i > 0)
			deuda = deuda - car[1];
		if(deuda < precio){
			cout<<"Entra"<<i;break;}
		cout<<"DEUDA "<<deuda<<" "<<"VALOR "<<precio<<'\n';
	}
	return 0;
}
