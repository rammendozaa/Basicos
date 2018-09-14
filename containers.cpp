#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main(void)
{
	string entrada;
	int caso = 1;
	while(cin >> entrada && entrada != "end")
	{
		vector <stack<char> > cont;
		stack <char> aux;
		int tam;
		tam = entrada.length();
		aux.push(entrada[0]);
		cont.push_back(aux);
		bool entra;
		for(char a : entrada)
		{
			stack <char> auxInt;
			entra = false;
			for(int i = 0 ; i < cont.size() ; i++)
			{
				if(cont[i].top() >= a)
				{
					cont[i].push(a);
					entra = true;
					break;
				}
			}
			if(!entra)
			{
				cont.push_back(auxInt);
				cont[cont.size() - 1].push(a);
			}
		}
		cout << "Case "<< caso << ": " << cont.size() << "\n";
		caso++;
	}
	return 0;
}