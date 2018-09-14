#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool f(vector <long long>  cables, long long mid, long long k)
{
	if(mid == 0)
		return true;
	for(int i = 0 ; i < cables.size() && k > 0 ; i++)
		k -= cables[i]/mid;
	return k <= 0;
}

int main(void)
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		long long num, k , ini, fin;
		cin >> num >> k;
		vector <long long> cables(num);
		fin = 0;
		for(int i = 0 ; i < num ; i++)
		{
			double aux1;
			scanf("%lf", &aux1);
			cables[i] = aux1 * 100;
			fin = max(fin, cables[i]);
		}
		ini = 0;
		while(ini < fin)
		{
			if(ini + 1 == fin)
			{
				if(f(cables, fin, k))
					ini = fin;
				break;
			}
			const long long mid = (ini + fin) / 2;
			if(f(cables,mid, k))
			{
				ini = mid;
			}
			else
			{
				fin = mid;
			}
		}
		printf("%lld.%02lld\n",ini/100, ini%100);
		//	cout << (double)((double)ini/(double)100) << "\n";
		if(cases >= 1)
			cout << "\n";
	}
	return 0;
}