#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

bool vacios(map <int, queue<int> > est)
{
	for(auto a : est)
	{
		if(!a.second.empty())
			return false;
	}
	return true;
}

int main(void)
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int estaciones, maxStack, maxQueue, cuantos, auxID, estActual, tiempo;
		map <int, queue <int> > X;
		cin >> estaciones >> maxStack >> maxQueue;
		for(int i = 1 ; i <= estaciones ; i++)
		{
			cin >> cuantos;
			queue <int> auxQ;
			for(int j = 0 ; j < cuantos ; j++)
			{
				cin >> auxID;
				auxQ.push(auxID);
			}
			X[i] = auxQ;
		}
		estActual = 1;
		stack <int> cargo;
		map <int, queue<int> > aux;
		aux = X;
		/*
		for(int i = 1 ; i <= X.size() ; i++)
		{
			cout << i << ": ";
			while(!X[i].empty())
			{
				cout << X[i].front() << " ";
				X[i].pop();
			}
			cout << "\n";
		}
		cout << "\n";
		for(auto a : aux)
		{
			cout << a.first << ": ";
			while(!a.second.empty())
			{
				cout << a.second.front() << " ";
				a.second.pop();
			}
			cout << "\n";
		}
		*/
		tiempo = 0;
		estActual = 1;
		//maybe < 
		stack <int> auxI;
		bool final = false;
	//	cout << cargo.size() << " " << maxStack << "\n";
		while(true)
		{
				//unloading
			while(!cargo.empty())
			{
				if(cargo.top() != estActual)
				{
					if(X[estActual].size() == maxQueue)
						break;
					X[estActual].push(cargo.top());
				}
				cargo.pop();
				tiempo++;
			}
				while(X[estActual].size() <= maxQueue && !cargo.empty())
				{
					if(cargo.top() == estActual)
					{
						cargo.pop();
						tiempo++;
					}
					else if(X[estActual].size() < maxQueue)
					{
						X[estActual].push(cargo.top());
						cargo.pop();
						tiempo++;
					}
					else
						break;
				}
				//loading
				while(cargo.size() < maxStack && !X[estActual].empty())
				{
						cargo.push(X[estActual].front());
						X[estActual].pop();
						tiempo++;
				}
			if(cargo.empty())
			{
				if(vacios(X))
					break;
			}
			estActual++;
			tiempo += 2;
			if(estActual == estaciones + 1)
				estActual = 1;
		
			}
		cout << tiempo << "\n";
	}	
	return 0;
}