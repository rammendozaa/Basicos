#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<stack <string> > deck(52);
queue <string> car;
		
bool match(string a, string b)
{
	return a[0] == b[0] || a[1] == b[1];
}	
void revisar(vector <stack <string> >cartas)
{
	string auxS;
	vector <int> tam;
	int i = 0;
	while(i < cartas.size())
	//for(int i = 0 ; i < cartas.size() ; i++)
	{
		if(match(cartas[i].top(), cartas[i + 1].top()) && !cartas[i + 1].empty() && !cartas[i].empty() && cartas.size() > 1)
		{
			auxS = cartas[i + 1].top();
			cartas[i].push(auxS);
			cartas[i + 1].pop();
			if(cartas[i + 1].empty() && cartas.size() > 1)
				cartas.erase(cartas.begin() + i + 1);
			for(auto a : cartas)
			{
				if(!a.empty())
				cout << a.top() << " ";
			}
			cout << "\n";
			revisar(cartas);
		}
		else if(!match(cartas[i].top(), cartas[i + 1].top()) && !cartas[i + 1].empty() && !cartas[i].empty() && cartas.size() > 1)
		{
			if(match(cartas[i].top(), cartas[i + 3].top()) && !cartas[i + 3].empty() && cartas.size() > 3)
			{
				auxS = cartas[i + 3].top();
				cartas[i].push(auxS);
				cartas[i + 3].pop();
				if(cartas[i + 3].empty() && cartas.size() > 3)
					cartas.erase(cartas.begin() + i + 3);
				for(auto a : cartas)
				{
				if(!a.empty())
					cout << a.top() << " ";
				}
				cout << "\n";
				revisar(cartas);
			}
//			else
			i++;

		}

		/*

		//this works, kind of, with the other method
		if(match(cartas[i].top(), cartas[i + 3].top()) && cartas.size() > 3)// && !cartas[i].empty() && !cartas[i + 3].empty())
		{
			cout << cartas[i].top() << " " <<  cartas[i + 3].top() << "\n ";
			auxS = cartas[i + 3].top();
			cartas[i].push(auxS);
			cartas[i + 3].pop();
		//	cout<< i << "primer \n";
			if(cartas[i + 3].empty())
				cartas.erase(cartas.begin() + i + 3);
			for(auto a : cartas)
			{
				cout << a.top() << " ";
			}
			cout << "\n";
			revisar(cartas);
			}
		else if(!match(cartas[i].top(), cartas[i + 3].top()) && match(cartas[i].top() , cartas[i + 1].top()) &&  cartas.size() > 2)// && !cartas[i].empty() && !cartas[i + 1].empty())
		{
			cout << cartas[i].top() << " " <<  cartas[i + 1].top() << "\n ";
			auxS = cartas[i + 1].top();
			cartas[i].push(auxS);
			cartas[i + 1].pop();
		//	cout<<i << "seg \n";
			if(cartas[i + 1].empty())
				cartas.erase(cartas.begin() + i + 1);
		//	revisar(cartas);
			for(auto a : cartas){
				cout << a.top() << " ";
			}
			cout << "\n";
			revisar(cartas);
		}
		else
		{
			continue;//tam.push_back((int)cartas[i].size());

		//	cout<<i  << "ult " << cartas[i].size()<< "\n";
		}
		*/
	}

}

int main(void)
{
	string carta, auxCarta;
	char suit, rank;
	while(cin >> carta && carta != "#")
	{
		while(!car.empty())
			car.pop();
		int entrada = 1, posAct;
		//car.push(carta);
		deck[0].push(carta);
		//while(entrada < 52)
		for(int i = 1 ; i < 52 ; i++)
		{
			cin >> carta;
			deck[i].push(carta);
		}
		cout << "entrada:\n";
		for(auto a : deck)
		{
			while(!a.empty())
			{
				cout << a.top() << " ";
				a.pop();
			}
		}
			cout << "\n";
		revisar(deck);

/*
		for(auto a : deck)
			for(auto b : a)
				cout << b << " ";
			cout << "\n\n";
		*/
	}
	return 0;
}