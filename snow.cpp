#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int main(void)
{
	int cases, numbers, auxN;
	cin >> cases;
	while(cases--)
	{
		cin >> numbers;
		set <long int> numeros;
		vector <long int> valores;
		long int tam, maxInd, maxTam;
		for(int i = 0 ; i < numbers ; i++)
		{
			cin >> auxN;
			valores.push_back(auxN);
		}
		tam = (long int)valores.size();
		maxInd = 0;
		maxTam = 0;
		for(int i = 0 ; i < tam ; i++)
		{

			while(numeros.find(valores[i]) != numeros.end())
				numeros.erase(valores[i - numeros.size()]);
			numeros.insert(valores[i]);
			if(numeros.size() > maxTam)
				maxTam = numeros.size();
		}
		cout << maxTam << "\n";
	}

	return 0;
}