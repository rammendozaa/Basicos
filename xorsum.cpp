#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
using namespace std;
int main(void)
{
	long long cases, numbers,auxN,xorMax;
	/*
	int siete = 7;
	int value = 7 xor 3;
	*/
	long long value;
	cin>>cases;
	while(cases--)
	{
		cin>>numbers;
		vector <long long> numeros(numbers);
		for(int i = 0 ; i < numbers ; i++)
		{
			cin>>auxN;
			numeros.push_back(auxN);
		}
		xorMax = -1;
		do{
			value = numeros[0] xor numeros[1];
			for(int i = 2 ; i < numeros.size() ; i++)
			{
				value = value xor numeros[i];
			}
			xorMax = max(value, xorMax);
		}while(next_permutation(numeros.begin(),numeros.end()));
		cout<<xorMax<<endl;
	}
	return 0;
}