#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<stack <string> > deck;
queue <string> car;
int vacios;
void check();

bool match(string a, string b)
{
	return a[0] == b[0] || a[1] == b[1];
}	

void move(int paraAca, int deAqui)
{

	if(paraAca == 0 && deAqui == 0)
		return;
	string auxS;
	auxS = deck[deAqui].top();
	deck[paraAca].push(auxS);
	deck[deAqui].pop();
	if(deck[deAqui].empty())
		deck.erase(deck.begin() + deAqui);
	check();
}

void check()
{

	if(deck.size() == 1)
		return;
	else
	{
		for(int i = 1 ; i < deck.size() ; i++)
		{

			if(i >= 3 && match(deck[i - 3].top(), deck[i].top()))
			{
				move(i - 3, i);
			}
			else if(match(deck[i - 1].top(), deck[i].top()))
			{
				move(i - 1, i);
			}
			else
			{
				move(0, 0);
			}
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
		stack <string> auxStack;
		auxStack.push(car.front());
		car.pop();
		deck.push_back(auxStack);
		check();
	}
}




int main(void)
{
	string carta, auxCarta;
	vector <int> tam;
	while(cin >> carta && carta != "#")
	{
		while(!car.empty())
			car.pop();
		car.push(carta);
		deck.clear();
		queue <string> aux;
		for(int i = 1 ; i < 52 ; i++)
		{
			cin >> carta;
			car.push(carta);
		}
		aux = car;
		stack <string> auxStck;
		auxStck.push(car.front());
		deck.push_back(auxStck);
		car.pop();
		tam.clear();
		revisar();
		for(auto a : deck)
		{
			tam.push_back(a.size());
		}
		if(tam.size() > 1)
			cout << tam.size() << " piles remaining:";
		else
			cout << "1 pile remaining:";
		for(auto a : tam)
			cout << " " << a;
		cout << "\n";
	}
	return 0;
}