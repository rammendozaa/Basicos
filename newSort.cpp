#include <iostream>
#include <vector>
using namespace std;
vector <int> numeros;
	
void merge(int ini, int mid, int fin)
{
	int i, j, k;
	int tam1 = mid - ini + 1;
	int tam2 = fin - mid;

	vector <int> izq(tam1);
	vector <int> der(tam2);
	for(i = 0 ; i < tam1 ; i++)
		izq[i] = numeros[ini + i];
	for(j = 0 ; j < tam2 ; j++)
		der[j]  = numeros[mid + 1 + j];
	i = 0;
	j = 0;
	k = ini;
	while(i < tam1 && j < tam2)
	{
		if(izq[i] <= der[j])
		{
			numeros[k] = izq[i];
			i++;
		}
		else
		{
			numeros[k] = der[j];
			j++;
		}
		k++;
	}
	while(i < tam1)
	{
		numeros[k] = izq[i];
		i++;
		k++;
	}
	while(j < tam2)
	{
		numeros[k] = der[j];
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
	int aux;
	while(cin >> aux)
		numeros.push_back(aux);
	
	for(int a : numeros)
		cout << a << " ";
	cout << "\n";

	mergeSort(0, numeros.size() - 1);
	
	for(int a : numeros)
		cout << a << " ";
	cout << "\n";

	return 0;
}