#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(void)
{
	double aux1,aux2,months,downP,owed,carPrice,numMonths,monthPay;
	int i, j, k, counter;
	while(cin>>months>>downP>>owed>>numMonths && months > 0)
	{
		vector <vector <double> > depre(numMonths);
		for(i = 0; i<numMonths; i++)
		{
			cin>>aux1>>aux2;
			depre[i].push_back(aux1);
			depre[i].push_back(aux2);
		}
		carPrice = (downP + owed) * (1 -depre[0][1]);
		monthPay = owed/months;
		i = 0;
		j = 1;
		if(owed < carPrice)
		{
			cout<<"0 months\n";
		}
		else
		{
			for(i = 1; i<months; i++)
			{
				owed = owed - monthPay;
				if(i < depre[numMonths-1][0])
				{
					if(i == depre[j][0])
					{
						carPrice = carPrice * (1 - depre[j][1]);
						j++;
					}
					else
						carPrice = carPrice * (1 - depre[j-1][1]);
				}
				else
					carPrice = carPrice * (1 - depre[numMonths-1][1]);
				if(owed < carPrice)
					break;
			}
			if(i == 1)
				cout<<"1 month\n";
			else
				cout<<i<<" months\n";
		}	
	}
	return 0;
}