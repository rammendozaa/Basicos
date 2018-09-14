#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void allsums(vector <int> canciones, int time)
{
	int n = canciones.size();
	int resultados [ ( 1 << n ) ];
	memset(resultados, 0, sizeof(resultados));
	vector <int> best, bestFinal;
	int resultBest = -1;
	for(int i = 0 ; i < ( 1 << n ) ; i++)
	{
		best.clear();
			
		for(int j = 0 ; j < n ; j++)
		{
			if((i & ( 1 << j )) != 0)
			{
				resultados[i] += canciones[j];
			//	cout << canciones[j] << " ";
				best.push_back(canciones[j]);
			}
		}	
		if(resultados[i] <= time && resultados[i] >= resultBest)
		{
			bestFinal = best;
			resultBest = resultados[i];
		}
		else
		{
			best.clear();
		}
//		cout << resultados[i] << "\n";
//		cout << "\n";
	}
	for(auto a : bestFinal)
		cout << a << " ";
	cout << "sum:" << resultBest << "\n";
	return;
}
 
int main(void)
{
	int time, tracks, auxI;
	while(cin >> time)
	{
		cin >> tracks;
		vector <int> canciones;
		vector <bool> todos(tracks), mejor(tracks);
		for(int i = 0 ; i < tracks ; i++)
		{
			cin >> auxI;
			canciones.push_back(auxI);
		}
		allsums(canciones, time);
	}
	return 0;
}