#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
long long int f(vector <long long int> cables, long long int mid, long long int k)
{
	if(mid == 0)
		return 0;
	for(int i = 0 ; i < cables.size() && k > 0 ; i++)
		k -= cables[i]/mid;
	return k;
}
int main(void)
{
	int cases;
		long long int num, k , ini, fin;
		vector <long long int>  cables;
		cin >> num >> k;
		fin = 0;
		for(int i = 0 ; i < num ; i++)
		{
			double aux1;
			cin >> aux1;
			cables.push_back((long long int)aux1 * 100);
			fin = max(fin, (long long int)aux1 * 100);
		}
		ini = 0;
		while(ini < fin)
		{
			if(ini + 1 == fin)
			{
				if(f(cables, fin, k) <= 0)
					ini = fin;
				break;
			}
			long long int mid = (ini + fin) / 2;
			if(f(cables, mid, k) <= 0)
			{
				ini = mid;
			}
			else
			{
				fin = mid;
			}
		}
		printf("%lld.%02lld\n",ini/100, ini%100);
	return 0;
}