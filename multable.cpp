#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int ini, fin, n, m;

long long int place(long long int mid)
{
	long long int aux = 0;
	for(long long int i = 1 ; i <= m ; i++)
	{
		if(n < (mid/i))
			aux += n;
		else
			aux += mid/i;
		//aux += min((mid/i), ini);
	}
	return aux;
}

int main(void)
{
	long long int k, aux, final, mid;
	cin >> n >> m >> k;
	ini = 1;
	fin = n * m;
	aux = k;
	while(ini <= fin)
	{
		mid = (fin + ini) / 2;
		if(place(mid) < k)	
			ini = mid + 1;
		else
			fin = mid - 1;
	}
	cout << ini << "\n";
	return 0;	
}