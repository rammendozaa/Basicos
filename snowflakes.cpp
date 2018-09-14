#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
using namespace std;

bool repeated(vector <long int> recibido)
{
	set <long int> mira(recibido.begin(), recibido.end());
	return mira.size() == recibido.size();	
}

int main(void)
{
	int cases, numbers, auxN;
	cin >> cases;
	while(cases--)
	{
		map <long int, long int> ocur;
		map <long int, long int> pos;
		priority_queue <long int> snows;
		set <long int> hola;
		long int contador, auxPos;
		vector <long int> numeros;
		vector <long int> aux;
		long int lrv;
		cin >> numbers;
		contador = 0;
		bool entro = false;
		snows.push(contador);
		lrv = -1;
		pos[lrv] = -1;
		for(int i = 1 ; i <= numbers; i++)
		{
			cin >> auxN;
			ocur[auxN] = ocur[auxN] + 1;
			hola.insert(auxN);
			aux.push_back(auxN);
			cout << "antes \t\t" << auxN << " " << contador << " " << ocur[auxN] << "\n";
			if(ocur[auxN] >= 2)
			{	
				auxPos = i - pos[auxN];
				contador = auxPos;
				for(auto a : hola)
				{
					ocur[a] = 1;	
				}
				lrv = auxN;
				//ocur[auxN] = 1;
			}
			else //if(ocur[auxN] == 1)
			{

				contador++;
			//	pos[auxN] = i;
			}
			snows.push(contador);
			pos[auxN] = i;
			cout << "desuoes \t" << auxN << " " << contador << " " << ocur[auxN] << "\n\n";
			
		}	
		cout << snows.top() << "\n";
		//cout << "\n";
		
/*
cout << "\n";
	while(!snows.empty())
	{
		cout << snows.top() << "\n";
		snows.pop();
	}//p() << "\n";		
*/	}
	return 0;
}