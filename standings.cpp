#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector <pair<int, int> > numeros;

void merge(int ini, int mid, int fin)
{
	int i, j, k;
	int tam1 = mid - ini + 1;
	int tam2 = fin - mid;

	vector <pair<int, int> > izq(tam1);
	vector <pair<int, int> > der(tam2);
	for(i = 0 ; i < tam1 ; i++)
	{
		izq[i].first = numeros[ini + i].first;
		izq[i].second = numeros[ini + i].second;
	}
	for(j = 0 ; j < tam2 ; j++)
	{

		der[j].first  = numeros[mid + 1 + j].first;
		der[j].second  = numeros[mid + 1 + j].second;
	}
	i = 0;
	j = 0;
	k = ini;
	while(i < tam1 && j < tam2)
	{
		if(izq[i].second >= der[j].second)
		{
			numeros[k].first = izq[i].first;
			numeros[k].second = izq[i].second;
			i++;
		}
		else
		{
			numeros[k].first = der[j].first;
			numeros[k].second = der[j].second;
			j++;
		}
		k++;
	}
	while(i < tam1)
	{
		numeros[k].first = izq[i].first;
		numeros[k].second = izq[i].second;
		i++;
		k++;
	}
	while(j < tam2)
	{
		numeros[k].first = der[j].first;
		numeros[k].second = der[j].second;
		k++;
		j++;
	}

}

void mergeSort(int ini, int fin)
{
	if(ini < fin)
	{
		int mid = (fin + ini) / 2;
		mergeSort(ini, mid);
		mergeSort(mid + 1, fin);
		merge(ini, mid, fin); 
	}
}


int main(void)
{
	numeros.clear();
	int auxID, auxProb, nums;
	cin >> nums;
	for(int i = 0 ; i < nums ; i++)
	{
		cin >> auxID >> auxProb;
		numeros.push_back(make_pair(auxID, auxProb));
	}

	mergeSort(0, numeros.size() - 1);

		for(auto a : numeros)
		cout << a.first << " " << a.second << "\n";
	

	return 0;
}