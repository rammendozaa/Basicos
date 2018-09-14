#include <iostream>
#include <vector>
using namespace std;

int cuantos(vector <string> prop, vector <string> req)
{
	int count = 0;
	int tama, tamb;
	tamb = prop.size();
	tama = req.size();
	for(int i=0;i<tama;i++)
	{
		for(int j = 0; j<tamb;j++)
		{
			if(prop[j] == req[i])
			{
				count++;
			}
		}
	}

	return count;
}
/*
int posmin(vector <int> numeros)
{
	int i = 0;
	int j = 0;
	int pos = 0;
	54for(i = 1; i<numeros.size();i++)
	{
		if(numeros[i] < numeros[pos])
			pos = i;
	}
	return pos;
}
*/
int main()
{
	string aux;
	vector <int> num;
	vector <string> prop;
	vector <string> req;
	int nume;
	for(int i = 0;i<6;i++)
	{
		cin>>aux;
		req.push_back(aux);
	}
	for(int i = 0; i<4;i++)
	{
		cin>>aux; 
		prop.push_back(aux);
	}
	nume = cuantos(prop, req);
	cout<<" "<<nume;

		return 0;
}
