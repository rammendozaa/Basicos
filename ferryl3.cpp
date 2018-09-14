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
int cross, cTime, ferry, maxCars;

void loadF()
{
	while(bank[current].front() <= cTime && ferry < maxCars && !bank[current].empty())
	{
		bank[current].pop();
		ferry++;
	}
}

void emptyF()
{
	while(ferry > 0)
	{
		llegar.push_back(cTime);
		llegada[opposite].push(cTime);
		ferry--;
	}
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
	cTime += cross;
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
		cin >> maxCars >> cross >> lines;
		for(int i = 0 ; i < lines ; i++)
		{
			cin >> auxI >> auxS;
			bank[auxS].push(auxI);
			//tener cuidado con el caso en donde son iguales las entradas en ambos lados
			order.push_back(auxS);
		}
		current = "left";
		opposite = "right";
		cTime = 0;
		ferry = 0;
		/*
		for(auto a : bank)
		{
			cout << a.first << "\t";
			while(!a.second.empty())
			{
				cout << a.second.front() << " ";
				a.second.pop();
			}
			cout << "\n";
		}
		*/
		//could probably change to while(true)
		//cout << bank[izq].size() << " " << bank[der].size() << "\n";
		while(!bank[izq].empty() || !bank[der].empty() || ferry > 0)
		{
			if(bank[current].empty())// && !bank[opposite].empty())
			{
				if(ferry > 0)
					emptyF();
				if(bank[opposite].front() > cTime)
					cTime = bank[opposite].front();
				crossR();
			}
			else if(bank[opposite].empty())// && !bank[current].empty())
			{
				if(ferry > 0)
					emptyF();
				if(bank[current].front() > cTime)
					cTime = bank[current].front();
				loadF();
				crossR();
			}
			else if(bank[current].front() < bank[opposite].front())
			{
				if(ferry > 0)
					emptyF();
				if(bank[current].front() > cTime)
					cTime = bank[current].front();
				loadF();
				crossR();
			}
			//check further into this one
			else if(bank[current].front() > bank[opposite].front())
			{
				if(ferry > 0)
					emptyF();
				if(bank[current].front() <= cTime)
					loadF();
				else if(bank[opposite].front() > cTime)
					cTime = bank[opposite].front();
				crossR();
			}
			//else
			else if(bank[current].front() == bank[opposite].front())
			{
				if(ferry > 0)
					emptyF();
				if(bank[current].front() > cTime)
					cTime = bank[current].front();
				loadF();
				crossR();
			}
		}
		for(auto a : order)
		{
			cout << llegada[a].front() << "\n";
			llegada[a].pop();
		}
		/*
		for(auto a : llegar)
			cout << a << "\n";
		*/
		if(cases >= 1)
			cout << "\n";
	}
	return 0;
}