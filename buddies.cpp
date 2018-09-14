#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int S, B, n, m, auxPosI, auxPosD, auxIzq, auxDer;
	while(cin >> S >> B && (S != 0 || B != 0))
	{
		vector <int> original(S + 2);
		vector <int> der(S + 2);
		vector <int> izq(S + 2);
		original[0] = -1;
		original[S + 1] = -1;
		izq[0] = -1;
		izq[1] = -1;
		der[S] = -1;
		der[S + 1] = -1;
		for(int i = 1 ; i <= S ; i++)
		{
			original[i] = i;
			izq[i + 1] = i;
			der[i - 1] = i;
		}	
		for(int i = 0 ; i < B ; i++)
		{
			cin>>n>>m;
			auxIzq = izq[n];
			auxDer = der[m];
			if(auxIzq == -1)
			{
				cout<<"* ";
				auxPosI = 0;
			}
			else
			{
				cout<<auxIzq<<" ";
				auxPosI = auxIzq;
			}
			if(auxDer == -1)
			{
				cout<<"*\n";
				auxPosD = 0;
			}
			else
			{
				cout<<auxDer<<"\n";
				auxPosD = auxDer;
			}
			der[auxPosI] = auxDer;
			izq[auxPosD] = auxIzq;
		}
		cout<<"-\n";
	}
	return 0;
}
