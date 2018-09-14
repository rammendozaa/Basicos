#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
using namespace std;

map <string, queue <int> > bank;
map <string, queue <int> > llegada;
vector <int> llegar;
string current, opposite, izq = "left", der = "right";
int cross, veces, ferry, tamTotal, suma;

void loadF()
{
	suma = 0;
	while(suma < tamTotal && !bank[current].empty())
	{
		if(suma + bank[current].front() > tamTotal)
			break;
		suma += bank[current].front();
		bank[current].pop();
		ferry++;
	}
}

void emptyF()
{
	suma = 0;
	ferry = 0;
}

void crossR()
{
	if(current == "right")
	{
		current = "left";
		opposite = "right";
	}
	else
	{
		current = "right";
		opposite = "left";
	}
	veces++;
}

int main(void)
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int lines, auxI;
		string auxS, cSide;
		bank.clear();
		llegada.clear();
		llegar.clear();
		vector <string> order;
		cin >> tamTotal >> lines;
		tamTotal *= 100;
		for(int i = 0 ; i < lines ; i++)
		{
			cin >> auxI >> auxS;
			bank[auxS].push(auxI);
			//tener cuidado con el caso en donde son iguales las entradas en ambos lados
		}
		current = "left";
		opposite = "right";
		veces = 0;
		ferry = 0;
		while(!bank[izq].empty() || !bank[der].empty() || ferry > 0)
		{
			/*if(bank[current].empty())// && !bank[opposite].empty())
			{
				if(ferry > 0)
					emptyF();
				crossR();
			}
			else if(bank[opposite].empty())// && !bank[current].empty())
			{
				if(ferry > 0)
					emptyF();
				loadF();
				crossR();
			}
			else
			{*/
				if(ferry > 0)
					emptyF();
				loadF();
				crossR();
		}
		cout << veces - 1 << "\n";
	}
	return 0;
}