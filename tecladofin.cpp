#include <iostream>
#include <string>
#include <list>
using namespace std;

string order(string palabra)
{
	string auxS, auxA, mandar;
	int contIzq, contDer;
	auxS = "";
	auxA = "";
	//fin = "";
	contIzq = 0;
	contDer = 0;
	list <string> cadena;
	int n, i, j, k;
	for(int i = 0 ; i < palabra.length() ; i++)
	{
		if(palabra[i] == '[')
		{
			contIzq++;
			cadena.push_back(auxS);
			i++;
			auxA = "[";
			while(contIzq != contDer)
			{
				if(palabra[i] == '[')
				{
					contIzq++;
					auxA += palabra[i];
				}
				else if(palabra[i] == ']')
				{	
					contDer++;
					auxA += palabra[i];
				}
				else
					auxA += palabra[i];
				i++;
			//	cout<<contIzq<<" "<<contDer<<"\n";
			}
			//cout<<"HERE "<<auxA.substr(1, auxA.length() - 2)<<"\n";
			auxA = auxA.substr(1, auxA.length() - 2);
			contIzq = 0;
			contDer = 0;
			//funcion para palabraenar
			auxA = order(auxA);
			//después de agrega al inicio
			cadena.emplace_front(auxA);
			auxS = "";
			i--; 
		}
		else
			auxS += palabra[i]; 
//		cadena.push_back(entrada[i]);
	}
	cadena.push_back(auxS);
	for(auto a : cadena)
		mandar += a;


	return mandar;
}

int main(void)
{
	string palabra, auxS, auxA, recibido, fin;
	int contIzq, contDer;
	//cin >> palabra;
	auxS = "";
	auxA = "";
	fin = "";
	list<string> cadena;
	int n, i, j, k;
	contIzq = 0; 
	contDer = 0;
//	TODO meter aqui EOF
	/*
	for(int i = 0 ; i < palabra.length() ; i++)
	{
		if(palabra[i] == '[')
		{
			contIzq++;
			cadena.push_back(auxS);
			i++;
			auxA = "[";
			while(contIzq != contDer)
			{
				if(palabra[i] == '[')
				{
					contIzq++;
					auxA += palabra[i];
				}
				else if(palabra[i] == ']')
				{	
					contDer++;
					auxA += palabra[i];
				}
				else
					auxA += palabra[i];
				i++;
				cout<<contIzq<<" "<<contDer<<"\n";
			}
			//cout<<"HERE "<<auxA.substr(1, auxA.length() - 2)<<"\n";
			auxA = auxA.substr(1, auxA.length() - 2);
			contIzq = 0;
			contDer = 0;
			//funcion para palabraenar
			auxA = order(auxA);
			//después de agrega al inicio
			cadena.emplace_front(auxA);
			auxS = "";
			i--; 
		}
		else
			auxS += palabra[i]; 
//		cadena.push_back(entrada[i]);
	}
	cadena.push_back(auxS);
	for(auto a : cadena)
		cout<<a;
	*/
	while(cin>>palabra)
	{
		recibido = order(palabra);
		cout<<recibido;
		cout<<"\n";
	}return 0;
}