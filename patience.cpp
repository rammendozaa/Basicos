#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;
vector <string> cartas;

bool match(string a, string b)
{
	return a[0] == b[0] || a[1] == b[1];
}

vector <stack <string> > revisar(vector <stack <string> > cartas)
{
	int i, j, k, cartaAct;
	string auxS;
	vector <stack<string> > auxDeck;
	stack<string> auxCart;
	auxCart.push(cartas[0]);
	auxDeck.push_back(auxCart);
	cartaAct = 1;



	string auxS;
	vector <int> tam;
	int i = 0;
	while(i < cartas.size())
	//for(int i = 0 ; i < cartas.size() ; i++)
	{
		if(match(cartas[i].top(), cartas[i + 1].top()))
		{
			auxS = cartas[i + 1].top();
			cartas[i].push(auxS);
			cartas[i + 1].pop();
			if(cartas[i + 1].empty())
				cartas.erase(cartas.begin() + i + 1);
			i = 0;
		}
		else if(match(cartas[i].top()xxxxx))


	}
	while(true)
{


		if(match(cartas[i].top(), cartas[i + 3].top()) && cartas.size() >= 3 && i >= 3)// && !cartas[i].empty() && !cartas[i + 3].empty())
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
				if(!a.empty())
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
				if(!a.empty())
				cout << a.top() << " ";
			}
			cout << "\n";
			revisar(cartas);
		}
		else if (!match(cartas[i].top(), cartas[i + 3].top()) && !match(cartas[i].top() , cartas[i + 1].top()))
		{
			break;
		}
		else
		{
			continue;//tam.push_back((int)cartas[i].size());

		//	cout<<i  << "ult " << cartas[i].size()<< "\n";
		}
	}
	//return cartas;
}

int main(void)
{
	string carta, auxCarta;
	char suit, rank;
	while(cin >> carta && carta != "#")
	{
		vector<stack <string> > deck;//(52);
		vector <stack <string> > aux;
		cartas.erase(cartas.begin(), cartas.end());
		cartas.push_back(carta);
		for(int i = 1 ; i < 52 ; i++)
		{
			cin >> carta;
			cartas.push_back(carta);
		}
		cout << "entrada:\n";
		for(auto a : deck)
		{
			cout << a << " ";
		}
			cout << "\n";
		deck = revisar(cartas);
}
	return 0;
}