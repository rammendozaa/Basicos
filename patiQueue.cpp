#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<stack <string> > deck(104);
queue <string> car;
int vacios;
bool match(string a, string b)
{
	return a[0] == b[0] || a[1] == b[1];
}	

void check()
{
	vacios = 0;
	for(auto a : deck)
	{
		if(!a.empty())
			vacios++;
	}
	string auxS;
	for(int i = 0 ; i <= vacios ; i++)	
	{
		//cout << "i \t" << i << "vacios " << vacios << "\n";
		if(vacios <= 1)
			return;
		if(vacios > 3 && match(deck[i + 3].top(), deck[i].top()) && !deck[i].empty() && !deck[i + 3].empty())
		{
			vacios = 0;
			auxS = deck[i + 3].top();
			deck[i].push(auxS);
			deck[i + 3].pop();
			if(deck[i + 3].empty())
				deck.erase(deck.begin() + i + 3);
			for(auto a : deck)
			{
				if(!a.empty())
				{
					vacios++;
					cout << a.top() << " ";
				}
			}
			cout << "\n";
			if(vacios >= 2)
			{
				check();
			}
			else if(vacios <= 1)
				return;
		}
		else if(match(deck[i].top(), deck[i + 1].top()) && !deck[i].empty() && !deck[i + 1].empty())
		{
			vacios = 0;
			auxS = deck[i + 1].top();
			deck[i].push(auxS);
			deck[i + 1].pop();
			if(deck[i + 1].empty())
				deck.erase(deck.begin() + i + 1);
			for(auto a : deck)
			{
				if(!a.empty())
				{	
					vacios++;
				cout << a.top() << " ";
				}
			}
			cout << "\n";
			if(vacios >= 2)
			{
				check();
			}
			else if(vacios <= 1)
				return;
		}
		else
		{
			return;
		}
	}
	return;
}

void revisar()
{
	string auxS;
	vector <int> tam;
	int i = 0, ultEmpty;
	vacios = 0;
	while(!car.empty())
	{
		check();
		ultEmpty = 0;
		for(auto a : deck)
		{
			if(a.empty())
			{
				i = ultEmpty - 1;
				break;
			}
			ultEmpty++;
		}
		if(i >= 2 && match(deck[i - 2].top(), car.front()))
		{
			//cout << deck[i - 2].top() << " " << car.front() << "\n";
			deck[i - 2].push(car.front());
			car.pop();
			check();
		}
		else if(match(deck[i].top(), car.front()))// && !deck[i].empty() && !car.empty())
		{
			deck[i].push(car.front());
			car.pop();
			check();
		}
		else if(!match(deck[i].top(), car.front()))// && !deck[i].empty() && !car.empty())
		{
			for(int j = 0 ; j < deck.size() ; j++)
			{
				if(deck[j].empty())
				{	
					deck[j].push(car.front());
					break;
				}
			}
			car.pop();
			i++;
// este si estaba aqui	check();
//no importa si va afuera o si va aqui a dentro	
			check();
		}
		else
		{
			continue;
		}
		vacios = 0;
		for(auto a : deck)
			{
				if(!a.empty())
				{
					cout << a.top() << " ";
				}
			}
			cout << "\n";
		check();
		}
	cout << "done";
	return;
}

int main(void)
{
	string carta, auxCarta;
	char suit, rank;
	while(cin >> carta && carta != "#")
	{
		while(!car.empty())
			car.pop();
		car.push(carta);
		queue <string> aux;
		for(int i = 1 ; i < 52 ; i++)
		{
			cin >> carta;
			car.push(carta);
		}
		cout << "entrada:\n";
		aux = car;
			while(!aux.empty())
			{
				cout << aux.front() << " ";
				aux.pop();
			}
			cout << "\n";
		deck[0].push(car.front());
		car.pop();
		revisar();
	}
	return 0;
}