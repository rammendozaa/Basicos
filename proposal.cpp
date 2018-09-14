#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string sinespacios(string a)
{
	string aux="";
	for(char b:a)
	{
		if(b == ' ')
		{
			continue;
		}
		else
			aux = aux + b;
	}
	return aux;
}
/*
int menorprecio(int rep, vector <int> cumplen, vector<float> precio)
{
	vector <int> indicesrepetidos;
	vector <float> auxprecios;
	float menor;
	for(int a: cumplen)
	{
		if(a == rep)
			indicesrepetidos.push_back(a);
	}
	for(int a: indicesrepetidos)
		auxprecios.push_back(precio[a]);
	sort(auxprecios.begin(),auxprecios.end());
	menor = auxprecios[0];
	for(int i = 0; i<precio.size();i++)
	{
		if(precio[i] == menor)
		{
			return i;
		}
	}
} 

int posmax(vector <int> numeros)
{
	int i = 0;
	int j = 0;
	int pos = 0;
	for(i = 1; i<numeros.size();i++)
	{
		if(numeros[i] > numeros[pos])
			pos = i;
	}
	return pos;
}

bool esta (int a,vector <int> numeros)
{
	for(int b:numeros)	
		if(a == b)
			return true;

	return false;
}

int cuantos(vector <string> prop, vector <string> req)
{
        int count = 0;
        int tama, tamb;
        tamb = prop.size();
        tama = req.size();
        for(int i=0;i<tama;i++)
        {
                for(int j = 0; j<tamb;j++)
                {
                        if(prop[j] == req[i])
                        {
                                count++;
                        }   
                }   
        }   

        return count;
}

int cuantasveces(int numero,vector <int> donde)
{
	int contador = 0;
	for(int a:donde)
	{
		if(a == numero)
			contador++;
	}
	return contador;
}
*/

int main()
{
	int req, cumpl,i,j,number;
	float price;
	vector <string> requis; //agarra los requisitos
	vector <string> nombres; //nombre de propuesta
	vector <float> precio; //precio de propuest
	vector <string> carac;
	vector <int> numero; //carac cumplidas
	string aux,otro;
	int k,cumplidos,ind,veces,indmenor;
	k = 0;
	cin>>req>>cumpl;
	while(req != 0 && cumpl != 0)
	{
		cin.ignore();
		requis.clear();
		for(i = 0; i<req;i++) 
		{
			getline(cin,aux);//cin>>aux;
			aux = sinespacios(aux);
			cout<<aux<<'\n';
		}
		numero.clear();
		nombres.clear();
		precio.clear();
		for(i = 0; i<cumpl;i++)
		{
			cin>>aux;
			cin>>price;
			cin>>number;
			cin.ignore();
			for(j = 0; j<number; j++)
			{
				getline(cin,otro);
//				otro = sinespacios(otro);
			}
//			cumplidos = cuantos(carac, requis);
//			carac.clear();
		}
/*		ind = posmax(numero);
		veces = cuantasveces(numero[ind],numero);
		if(veces == 1)
			cout<<"RFC #"<<k+1<<'\n'<<nombres[ind]<<'\n';
		else
		{
			indmenor = menorprecio(numero[ind],numero, precio);
			cout<<"RFC #"<<k+1<<'\n'<<nombres[indmenor]<<'\n';
		}
*/		k++;	
		cin>>req>>cumpl;
	}		
	return 0;
}	
