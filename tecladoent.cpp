#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void)
{
	string palabra, recibido, auxS, auxA;
	int contIzq, contDer;
	contIzq = 0;
	contDer = 0;
	auxS = "";
	while(cin >> palabra)
	{
		list <string> cadena;
		auxS = "";
		for(int i = 0 ; i < palabra.length() ; i++)
		{
			if(palabra[i] == '[')
			{
				cadena.push_back(auxS);
				auxS = "";
				i++;
				while(palabra[i] != ']' && palabra[i] != '[' && i < palabra.length())
				{
					if(palabra[i] == ']')
						i++;
					auxS += palabra[i];
					i++;
				}
				i--;
				if(auxS[auxS.length() - 1] == ']')
					auxS = auxS.substr(0 , auxS.length() - 2);
				cadena.emplace_front(auxS);
				auxS = "";
			}
			else if(palabra[i] == ']')
			{
				cadena.push_back(auxS);
				auxS = "";
				i++;
				while(palabra[i] != ']' && palabra[i] != '[' && i < palabra.length())
				{
					if(palabra[i] == ']')
						i++;
					auxS += palabra[i];
					i++;
				}
				i--;
				if(auxS[auxS.length() - 1] == ']')
					auxS = auxS.substr(0, auxS.length() - 2);
				cadena.push_back(auxS);
				auxS = "";
			}
			else
			{
				auxS += palabra[i];
				//cout << auxS << "\n";
			}
		}
		cadena.push_back(auxS);
		for(auto a : cadena)
			cout<<a;
		cout<<"\n";
	}
	return 0;
}