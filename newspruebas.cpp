#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int indice(char a, vector <char> letr)
{
	int cont = 0;
	for(char c: letr)
	{
		if(a == c)
			return cont;
		cont++;
	}
	return -1;
}

int main()
{
//	cout<<fixed;
//	cout<<setprecision(2);
	int cases,letras,lines,precio,aux;
	char auxl;
	int auxc;
	string linea;
	cin>>cases;
	float suma;
	vector <float> sumas;
	vector <char> let;
	vector <float> dinero;
	while(cases>0)
	{	
		let.clear();
		dinero.clear();
		letras = 0;
		auxl = 0;
		auxc = 0;
		lines = 0;
		suma = 0;
		cin>>letras;
		while(letras > 0)
		{
			cin>>auxl>>auxc;
			let.push_back(auxl);
			dinero.push_back((float)auxc/(float)100);
			letras--;
		}
		cin>>lines;
		cin.ignore();
		while(lines--)
		{
			getline(cin,linea);
			for(char c:linea)
			{
				if(indice(c,let) != -1)
					suma = suma + dinero[indice(c,let)];
			}
		}
		cout<<fixed;
		cout<<setprecision(2);
//		cout<<suma<<"$"<<'\n';
		sumas.push_back(suma);
		cases--;
	}
	for(float a:sumas)
		cout<<a<<"$"<<'\n';
	cout<<'\n';
	return 0;
}
