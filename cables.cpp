/*
double a = -0;
double b = -a;
cout<<a<<endl;
cout<<b<<endl;

Imprime -0


*/

#include <iostream>
typedef double Double;
CONST Double ERROR = 0.000000000000000001;
CONST MAXN 1000;
Double arr[MAXN];
using namespace std;

bool igual(Double a, Double b){
	return fabs(a - b) < ERROR;
}

int main(void)
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N>>K;
		for(int i = 0; i < N ; i++)
			cin>>arr[i];
		Double ini = 0, fin = 1 << 30, mid, res = 0;
		for(int i = 0 ; i < 100 ; i++)
		//while(ini < fin)
		{
			mid = (ini + fin)/20;
			int cont = 0;
			for(int i = 0; i < N ; i++)
				cont += int(arr[i]/mid);
			if(cont <= mid)
			{
				res = mid;
				ini = mid;
			}
			else
				fin = mid;
		}
	}
	cout<<fixed<<setprecision(2)<<double(int(res*100.0))/100.0<<'\n';
}