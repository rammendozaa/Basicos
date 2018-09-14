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




int posmin(vector <int> numeros)
{
	int i = 0;
	int j = 0;
	int pos = 0;
	for(i = 1; i<numeros.size();i++)
	{
		if(numeros[i] < numeros[pos])
			pos = i;
	}
	return pos;
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

int main()
{
	int req, cumpl,i,j,number;
	float price;
	vector <string> requis; //agarra los requisitos
	vector <string> nombres; //nombre de propuesta
	vector <float> precio; //precio de propuest
//	vector <vector <string> > carac; //carac de propuesta
	vector <string> carac;
	vector <int> numero; //carac cumplidas
	string aux;
	int k;
	int cumplidos;
	while(cin>>req>>cumpl)
	{
		k = 0;
		requis.clear();
		//cumplidos.clear();
		numero.clear();
		for(i = 0; i<=req;i++)
		{
			getline(cin,aux);//cin>>aux;
			aux = sinespacios(aux);
			requis.push_back(aux);
		}
		cout<<cumpl;
		numero.clear();
		nombres.clear();
		precio.clear();
		for(i = 0; i<cumpl;i++)
		{	
			cin>>aux;
			cout<<aux;
			cin>>price;
			cout<<price;
			cin>>number;
			cout<<number;
			nombres.push_back(aux);
			precio.push_back(price);
			for(j = 0; j<number; j++)
			{
		//		cin>>aux;
				getline(cin,aux);
				aux = sinespacios(aux);
				carac.push_back(aux);
				cout<<"J"<<j<<'\n';
				cout<<"NUMERO"<<number<<'\n';
			}
			cumplidos = cuantos(carac, requis);
			numero.push_back(cumplidos);
			carac.clear();
			cin.ignore();
				cout<<"I"<<i<<'\n';
				cout<<"CUMPL"<<cumpl<<'\n';
		}
		int ind = posmin(numero);
		cout<<" "<<nombres[ind];
	}
	return 0;
}	
